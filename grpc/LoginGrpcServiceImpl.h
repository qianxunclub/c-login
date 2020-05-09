////
//// Created by 张斌 on 2020/5/9.
////
//
//#ifndef C_LOGIN_LOGINGRPCSERVICEIMPL_H
//#define C_LOGIN_LOGINGRPCSERVICEIMPL_H
//
//
//#include <login.grpc.pb.h>
//#include <LoginService.h>
//
//
//class LoginGrpcServiceImpl final : public grpc_login::LoginGrpcService::Service {
//public:
//    ::grpc::Status registerUser(::grpc::ServerContext *context, const ::grpc_login::UserRequest *request,
//                                ::grpc_login::Result *response) override;
//
//    ::grpc::Status login(::grpc::ServerContext *context, const ::grpc_login::UserRequest *request,
//                         ::grpc_login::SessionResponse *response) override;
//
//    ::grpc::Status userInfo(::grpc::ServerContext *context, const ::grpc_login::SessionResponse *request,
//                            ::grpc_login::User *response) override;
//
//    ::grpc::Status logout(::grpc::ServerContext *context, const ::grpc_login::SessionRequest *request,
//                          ::grpc_login::Result *response) override;
//
//private:
//    LoginService loginService;
//};
//
//
//#endif //C_LOGIN_LOGINGRPCSERVICEIMPL_H
