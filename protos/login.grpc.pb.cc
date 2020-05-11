// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: login.proto

#include "login.pb.h"
#include "login.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace grpc_login {

static const char* LoginGrpcService_method_names[] = {
  "/grpc_login.LoginGrpcService/registerUser",
  "/grpc_login.LoginGrpcService/login",
  "/grpc_login.LoginGrpcService/userInfo",
  "/grpc_login.LoginGrpcService/logout",
};

std::unique_ptr< LoginGrpcService::Stub> LoginGrpcService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< LoginGrpcService::Stub> stub(new LoginGrpcService::Stub(channel));
  return stub;
}

LoginGrpcService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_registerUser_(LoginGrpcService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_login_(LoginGrpcService_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_userInfo_(LoginGrpcService_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_logout_(LoginGrpcService_method_names[3], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status LoginGrpcService::Stub::registerUser(::grpc::ClientContext* context, const ::grpc_login::UserRequest& request, ::grpc_login::Result* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_registerUser_, context, request, response);
}

void LoginGrpcService::Stub::experimental_async::registerUser(::grpc::ClientContext* context, const ::grpc_login::UserRequest* request, ::grpc_login::Result* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_registerUser_, context, request, response, std::move(f));
}

void LoginGrpcService::Stub::experimental_async::registerUser(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::grpc_login::Result* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_registerUser_, context, request, response, std::move(f));
}

void LoginGrpcService::Stub::experimental_async::registerUser(::grpc::ClientContext* context, const ::grpc_login::UserRequest* request, ::grpc_login::Result* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_registerUser_, context, request, response, reactor);
}

void LoginGrpcService::Stub::experimental_async::registerUser(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::grpc_login::Result* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_registerUser_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::grpc_login::Result>* LoginGrpcService::Stub::AsyncregisterUserRaw(::grpc::ClientContext* context, const ::grpc_login::UserRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::grpc_login::Result>::Create(channel_.get(), cq, rpcmethod_registerUser_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::grpc_login::Result>* LoginGrpcService::Stub::PrepareAsyncregisterUserRaw(::grpc::ClientContext* context, const ::grpc_login::UserRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::grpc_login::Result>::Create(channel_.get(), cq, rpcmethod_registerUser_, context, request, false);
}

::grpc::Status LoginGrpcService::Stub::login(::grpc::ClientContext* context, const ::grpc_login::UserRequest& request, ::grpc_login::SessionResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_login_, context, request, response);
}

void LoginGrpcService::Stub::experimental_async::login(::grpc::ClientContext* context, const ::grpc_login::UserRequest* request, ::grpc_login::SessionResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_login_, context, request, response, std::move(f));
}

void LoginGrpcService::Stub::experimental_async::login(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::grpc_login::SessionResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_login_, context, request, response, std::move(f));
}

void LoginGrpcService::Stub::experimental_async::login(::grpc::ClientContext* context, const ::grpc_login::UserRequest* request, ::grpc_login::SessionResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_login_, context, request, response, reactor);
}

void LoginGrpcService::Stub::experimental_async::login(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::grpc_login::SessionResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_login_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::grpc_login::SessionResponse>* LoginGrpcService::Stub::AsyncloginRaw(::grpc::ClientContext* context, const ::grpc_login::UserRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::grpc_login::SessionResponse>::Create(channel_.get(), cq, rpcmethod_login_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::grpc_login::SessionResponse>* LoginGrpcService::Stub::PrepareAsyncloginRaw(::grpc::ClientContext* context, const ::grpc_login::UserRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::grpc_login::SessionResponse>::Create(channel_.get(), cq, rpcmethod_login_, context, request, false);
}

::grpc::Status LoginGrpcService::Stub::userInfo(::grpc::ClientContext* context, const ::grpc_login::SessionResponse& request, ::grpc_login::User* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_userInfo_, context, request, response);
}

void LoginGrpcService::Stub::experimental_async::userInfo(::grpc::ClientContext* context, const ::grpc_login::SessionResponse* request, ::grpc_login::User* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_userInfo_, context, request, response, std::move(f));
}

void LoginGrpcService::Stub::experimental_async::userInfo(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::grpc_login::User* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_userInfo_, context, request, response, std::move(f));
}

void LoginGrpcService::Stub::experimental_async::userInfo(::grpc::ClientContext* context, const ::grpc_login::SessionResponse* request, ::grpc_login::User* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_userInfo_, context, request, response, reactor);
}

void LoginGrpcService::Stub::experimental_async::userInfo(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::grpc_login::User* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_userInfo_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::grpc_login::User>* LoginGrpcService::Stub::AsyncuserInfoRaw(::grpc::ClientContext* context, const ::grpc_login::SessionResponse& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::grpc_login::User>::Create(channel_.get(), cq, rpcmethod_userInfo_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::grpc_login::User>* LoginGrpcService::Stub::PrepareAsyncuserInfoRaw(::grpc::ClientContext* context, const ::grpc_login::SessionResponse& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::grpc_login::User>::Create(channel_.get(), cq, rpcmethod_userInfo_, context, request, false);
}

::grpc::Status LoginGrpcService::Stub::logout(::grpc::ClientContext* context, const ::grpc_login::SessionRequest& request, ::grpc_login::Result* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_logout_, context, request, response);
}

void LoginGrpcService::Stub::experimental_async::logout(::grpc::ClientContext* context, const ::grpc_login::SessionRequest* request, ::grpc_login::Result* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_logout_, context, request, response, std::move(f));
}

void LoginGrpcService::Stub::experimental_async::logout(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::grpc_login::Result* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_logout_, context, request, response, std::move(f));
}

void LoginGrpcService::Stub::experimental_async::logout(::grpc::ClientContext* context, const ::grpc_login::SessionRequest* request, ::grpc_login::Result* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_logout_, context, request, response, reactor);
}

void LoginGrpcService::Stub::experimental_async::logout(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::grpc_login::Result* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_logout_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::grpc_login::Result>* LoginGrpcService::Stub::AsynclogoutRaw(::grpc::ClientContext* context, const ::grpc_login::SessionRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::grpc_login::Result>::Create(channel_.get(), cq, rpcmethod_logout_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::grpc_login::Result>* LoginGrpcService::Stub::PrepareAsynclogoutRaw(::grpc::ClientContext* context, const ::grpc_login::SessionRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::grpc_login::Result>::Create(channel_.get(), cq, rpcmethod_logout_, context, request, false);
}

LoginGrpcService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LoginGrpcService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LoginGrpcService::Service, ::grpc_login::UserRequest, ::grpc_login::Result>(
          [](LoginGrpcService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::grpc_login::UserRequest* req,
             ::grpc_login::Result* resp) {
               return service->registerUser(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LoginGrpcService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LoginGrpcService::Service, ::grpc_login::UserRequest, ::grpc_login::SessionResponse>(
          [](LoginGrpcService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::grpc_login::UserRequest* req,
             ::grpc_login::SessionResponse* resp) {
               return service->login(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LoginGrpcService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LoginGrpcService::Service, ::grpc_login::SessionResponse, ::grpc_login::User>(
          [](LoginGrpcService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::grpc_login::SessionResponse* req,
             ::grpc_login::User* resp) {
               return service->userInfo(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LoginGrpcService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LoginGrpcService::Service, ::grpc_login::SessionRequest, ::grpc_login::Result>(
          [](LoginGrpcService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::grpc_login::SessionRequest* req,
             ::grpc_login::Result* resp) {
               return service->logout(ctx, req, resp);
             }, this)));
}

LoginGrpcService::Service::~Service() {
}

::grpc::Status LoginGrpcService::Service::registerUser(::grpc::ServerContext* context, const ::grpc_login::UserRequest* request, ::grpc_login::Result* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LoginGrpcService::Service::login(::grpc::ServerContext* context, const ::grpc_login::UserRequest* request, ::grpc_login::SessionResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LoginGrpcService::Service::userInfo(::grpc::ServerContext* context, const ::grpc_login::SessionResponse* request, ::grpc_login::User* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LoginGrpcService::Service::logout(::grpc::ServerContext* context, const ::grpc_login::SessionRequest* request, ::grpc_login::Result* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace grpc_login

