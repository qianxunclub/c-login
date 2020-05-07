cmake_minimum_required(VERSION 3.16)
project(c_login)

set(CMAKE_CXX_STANDARD 14)

set(MYSQL_INC_DIR /usr/local/opt/mysql-client/include)
set(MYSQL_LINK_DIR /usr/local/opt/mysql-client/lib)
set(JSON_INC_DIR /usr/local/opt/jsoncpp/include)
set(JSON_LINK_DIR /usr/local/opt/jsoncpp/lib)

include_directories(${MYSQL_INC_DIR})
link_directories(${MYSQL_LINK_DIR})

include_directories(${JSON_INC_DIR})
link_directories(${JSON_LINK_DIR})

include_directories(config)
include_directories(model)
include_directories(repository)
include_directories(service)
include_directories(utils)
include_directories(test)

add_executable(c_login
        config/DbConfig.cpp
        config/DbConfig.h
        model/User.cpp
        model/User.h
        repository/UserRepository.cpp
        repository/UserRepository.h
        service/LoginService.cpp
        service/LoginService.h
        utils/Database.cpp
        utils/Database.h
        test/Main.cpp
        test/Main.h
        )
target_link_libraries(c_login
        libmysqlclient.dylib
        libjsoncpp.dylib
        )