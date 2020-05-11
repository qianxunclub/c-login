//
// Created by 张斌 on 2020/5/7.
//

#include <Common.h>
#include <Database.h>
#include <Redis.h>
#include "Main.h"
#include <LoginGrpcServiceImpl.h>
#include <iostream>
#include <LoginService.h>
#include <server_builder.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>


using namespace std;
using namespace utils;
using namespace appConfig;
using namespace base;
using namespace grpc;

int main(int argc, char **argv) {
    init();
    RunServer();
    service::LoginService loginService;

    Result result = loginService.login("zhangbin", "123456");
    std::cout << result.getCode() << "：" << result.getMessage() << std::endl;
    loginService.userInfo(result.getToken());
    return 0;
}

void RunServer() {
    string server_address("0.0.0.0:50051");
//    LoginGrpcServiceImpl loginGrpcServiceImpl;

//    EnableDefaultHealthCheckService(true);
//    reflection::InitProtoReflectionServerBuilderPlugin();
    ServerBuilder builder;
//    builder.AddListeningPort(server_address, InsecureServerCredentials());
//    builder.RegisterService(&loginGrpcServiceImpl);
//    unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    //    server->Wait();
}

void init() {
    DbConfig dbConfig;
    Database::getDatabase()->connect(dbConfig.getHost(), dbConfig.getPort(), dbConfig.getUsername(),
                                     dbConfig.getPassword(), dbConfig.getDatabase());
    RedisConfig redisConfig;
    Redis::getRedis()->connect(redisConfig.getHost(), redisConfig.getPort());

    Common::setAesEncryptor("coding");
}