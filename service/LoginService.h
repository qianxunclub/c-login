//
// Created by 张斌 on 2020/5/7.
//
#ifndef C_LOGIN_LOGINSERVICE_H
#define C_LOGIN_LOGINSERVICE_H

#include <string>
#include "../model/Result.h"

using namespace std;

namespace service {

    class LoginService {
    public:
        Result registerUser(string username, string password);

        Result login(string username, string password);

        User userInfo(string token);

        bool logout(string token);
    };
}

#endif //C_LOGIN_LOGINSERVICE_H

