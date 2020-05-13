//
// Created by 张斌 on 2020/5/7.
//
#ifndef C_LOGIN_USERREPOSITORY_H
#define C_LOGIN_USERREPOSITORY_H

#include <string>
#include "model/Result.h"
#include "model/User.h"

using namespace std;
using namespace model;

namespace repository {
    class UserRepository {
    public:
        bool isRegister(string username);

        User queryUser(string username, string password);

        Result registerUser(string username, string password, string salt);

        User userInfo(string username);
    };
}

#endif //C_LOGIN_USERREPOSITORY_H
