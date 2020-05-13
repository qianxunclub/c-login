//
// Created by 张斌 on 2020/5/7.
//

#include "utils/Common.h"
#include "base/Database.h"
#include "base/Redis.h"
#include <iostream>
#include "service/LoginService.h"
#include "grpcpp/server_builder.h"
#include "grpcpp/grpcpp.h"
#include "protos/login.grpc.pb.h"


using namespace std;
using namespace utils;
using namespace appConfig;
using namespace base;
using namespace grpc;
using namespace service;
using namespace model;

LoginService loginService;

class LoginGrpcServiceImpl final : public grpc_login::LoginGrpcService::Service {
public:
    grpc::Status
    registerUser(::grpc::ServerContext *context, const ::grpc_login::UserRequest *request,
                 ::grpc_login::Result *response) override {
        model::Result result = loginService.registerUser(request->username(), request->password());
        response->set_code(result.getCode());
        response->set_message(result.getMessage());
        return Service::registerUser(context, request, response);
    }

    grpc::Status login(::grpc::ServerContext *context, const ::grpc_login::UserRequest *request,
                       ::grpc_login::SessionResponse *response) override {
        model::Result result = loginService.login(request->username(), request->password());
        response->set_token(result.getToken());
        response->set_code(result.getCode());
        response->set_message(result.getMessage());
        return Service::login(context, request, response);
    }

    grpc::Status
    userInfo(::grpc::ServerContext *context, const ::grpc_login::SessionRequest *request,
             ::grpc_login::Result *response) override {
        User user = loginService.userInfo(request->token());
        if (!user.getId()) {
            ::grpc_login::User *protoUser;
            response->set_code(0);
            protoUser->set_id(user.getId());
            protoUser->set_username(user.getUsername());
            response->set_allocated_user(protoUser);
        } else {
            response->set_code(1);
            response->set_message("用户不存在");
        }


        return Service::userInfo(context, request, response);
    }

    grpc::Status
    logout(::grpc::ServerContext *context, const ::grpc_login::SessionRequest *request,
           ::grpc_login::Result *response) override {
        loginService.logout(request->token());
        response->set_code(0);
        return Service::logout(context, request, response);
    }
};


void RunServer() {
    string server_address("0.0.0.0:50051");
    LoginGrpcServiceImpl loginGrpcServiceImpl;

    ServerBuilder builder;

    builder.AddListeningPort(server_address, InsecureServerCredentials());
    builder.RegisterService(&loginGrpcServiceImpl);

    unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}

void init() {
    DbConfig dbConfig;
    Database::getDatabase()->connect(dbConfig.getHost(), dbConfig.getPort(), dbConfig.getUsername(),
                                     dbConfig.getPassword(), dbConfig.getDatabase());
    RedisConfig redisConfig;
    Redis::getRedis()->connect(redisConfig.getHost(), redisConfig.getPort());

    Common::setAesEncryptor("coding");
}


int main(int argc, char **argv) {
    init();
    RunServer();
    return 0;
}