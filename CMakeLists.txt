cmake_minimum_required(VERSION 3.5.1)
project(c_login C CXX)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR})

include(FetchContent)
FetchContent_Declare(
        gRPC
        GIT_REPOSITORY https://github.com/grpc/grpc
        GIT_TAG        v1.28.1
)
set(FETCHCONTENT_QUIET OFF)
FetchContent_MakeAvailable(gRPC)

set(LINK_DIR libs/lib)
link_directories(${LINK_DIR})

set(INC_DIR libs)
include_directories(${INC_DIR})


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

        protos/login.grpc.pb.cc
        protos/login.grpc.pb.h

        main/Main.cpp
        client/Client.cpp
        )
target_link_libraries(c_login
        libmariadb.dylib
        libjsoncpp.dylib
        libhiredis.dylib
        libgrpc.dylib
        libprotobuf.dylib
        libprotoc.dylib
        grpc++
        )