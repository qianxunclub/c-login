//
// Created by 张斌 on 2020/5/7.
//

#include <Common.h>
#include "Main.h"
#include <Database.h>
#include <Redis.h>
#include <grpcpp/grpcpp.h>
#include <LoginService.h>
//#include <LoginGrpcServiceImpl.h>


using namespace std;
using namespace utils;
using namespace appConfig;
using namespace base;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

int main(int argc, char **argv) {
    DbConfig dbConfig;
    Database::getDatabase()->connect(dbConfig.getHost(), dbConfig.getPort(), dbConfig.getUsername(),
                                     dbConfig.getPassword(), dbConfig.getDatabase());
    RedisConfig redisConfig;
    Redis::getRedis()->connect(redisConfig.getHost(), redisConfig.getPort());
    Common::setAesEncryptor("coding");
//    RunServer();
    LoginService loginService;

    Result result = loginService.login("zhangbin", "123456");
    std::cout << result.getCode() << result.getMessage() << std::endl;
    loginService.userInfo(result.getToken());
    return 0;
}

void RunServer() {
//    string server_address("0.0.0.0:8888");
//    ServerBuilder builder;
//    builder.AddListeningPort(server_address, InsecureServerCredentials());
//    LoginGrpcServiceImpl loginGrpcServiceImpl;
//    builder.RegisterService(&loginGrpcServiceImpl);
//    unique_ptr<Server> server(builder.BuildAndStart());
//    fprintf(stdout, "Server listening on: %s\n", server_address.c_str());
//    server->Wait();
}