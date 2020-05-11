cmake_minimum_required(VERSION 3.5.1)
project(c_login C CXX)

set(CMAKE_CXX_STANDARD 14)

set(LINK_DIR libs/lib)
link_directories(${LINK_DIR})

set(MYSQL_INC_DIR libs/mysql)
include_directories(${MYSQL_INC_DIR})

set(JSON_INC_DIR libs/json)
include_directories(${JSON_INC_DIR})


set(REDIS_INC_DIR libs/hiredis)
include_directories(${REDIS_INC_DIR})


set(CIPHER_INC_DIR libs/cipher)
include_directories(${CIPHER_INC_DIR})

set(GRPCPP_INC_DIR libs/grpcpp)
include_directories(${GRPCPP_INC_DIR})

set(GRPC_INC_DIR libs/grpc)
include_directories(${GRPC_INC_DIR})

set(GOOGLE_INC_DIR libs/protobuf)
include_directories(${GOOGLE_INC_DIR})

include_directories(config)
include_directories(libs)
include_directories(utils)
include_directories(model)
include_directories(repository)
include_directories(service)
include_directories(main)
include_directories(protos)
include_directories(base)
include_directories(grpc)

add_executable(c_login
        libs/cipher/aes.cpp
        libs/cipher/aes.h
        libs/cipher/aes_encryptor.cpp
        libs/cipher/aes_encryptor.h
        libs/cipher/md5.cc
        libs/cipher/md5.h
        libs/cipher/sha256.cc
        libs/cipher/sha256.h

        config/AppConfig.cpp
        config/AppConfig.h

        utils/Common.cpp
        utils/Common.h

        model/User.cpp
        model/User.h
        model/Result.cpp
        model/Result.h

        repository/UserRepository.cpp
        repository/UserRepository.h

        service/LoginService.cpp
        service/LoginService.h

        base/Database.cpp
        base/Database.h
        base/Redis.cpp
        base/Redis.h

#        grpc/LoginGrpcServiceImpl.cc
#        grpc/LoginGrpcServiceImpl.h

#        protos/login.grpc.pb.cc
#        protos/login.grpc.pb.h

        main/Main.cpp
        main/Main.h
        )
target_link_libraries(c_login
        libmariadb.dylib
        libjsoncpp.dylib
        libhiredis.dylib
        libgrpc.dylib
        libprotobuf.dylib
        libprotoc.dylib
        )