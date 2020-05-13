//
// Created by 张斌 on 2020/5/9.
//

#include "../model/Result.h"
#include "LoginGrpcServiceImpl.h"

grpc::Status
LoginGrpcServiceImpl::registerUser(::grpc::ServerContext *context, const ::grpc_login::UserRequest *request,
                                   ::grpc_login::Result *response) {
    model::Result result = loginService.registerUser(request->username(), request->password());
    response->set_code(result.getCode());
    response->set_message(result.getMessage());
    return Service::registerUser(context, request, response);
}

grpc::Status LoginGrpcServiceImpl::login(::grpc::ServerContext *context, const ::grpc_login::UserRequest *request,
                                         ::grpc_login::SessionResponse *response) {
    return Service::login(context, request, response);
}

grpc::Status
LoginGrpcServiceImpl::userInfo(::grpc::ServerContext *context, const ::grpc_login::SessionResponse *request,
                               ::grpc_login::User *response) {
    return Service::userInfo(context, request, response);
}

grpc::Status LoginGrpcServiceImpl::logout(::grpc::ServerContext *context, const ::grpc_login::SessionRequest *request,
                                          ::grpc_login::Result *response) {
    return Service::logout(context, request, response);
}
