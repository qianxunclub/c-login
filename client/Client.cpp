//
//#include <string>
//#include "grpcpp/grpcpp.h"
//#include "protos/login.grpc.pb.h"
//
//using namespace std;
//using grpc::Channel;
//using grpc::ClientContext;
//using grpc::Status;
//
//class Client{
//public:
//    Client(std::shared_ptr<Channel> channel): stub_(::grpc_login::LoginGrpcService::NewStub(channel)) {}
//
//    ::grpc_login::Result registerUser(string username,string password){
//        ::grpc::ClientContext context;
//        ::grpc_login::UserRequest request;
//        ::grpc_login::Result response;
//
//        request.set_username(username);
//        request.set_password(password);
//        Status status = stub_->registerUser(&context, request, &response);
//        if (status.ok()) {
//            return response;
//        }
//        std::cout << status.error_code() << ": " << status.error_message()<< std::endl;
//
//    }
//private:
//  std::unique_ptr<::grpc_login::LoginGrpcService::Stub> stub_;
//};
//
//int main(int argc, char** argv) {
//    Client client(grpc::CreateChannel("127.0.0.1:50051", grpc::InsecureChannelCredentials()));
//    client.registerUser("zhangbin","123456");
//}