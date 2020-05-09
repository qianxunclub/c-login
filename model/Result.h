//
// Created by 张斌 on 2020/5/8.
//

#ifndef C_LOGIN_RESULT_H
#define C_LOGIN_RESULT_H

#include <string>
#include "User.h"

using namespace std;
using namespace model;

namespace model {

    class Result {
    public:

        Result(int code);

        Result(int code, const string &message);

        Result(int code, const string &message, const string &token, const User &user);

        int getCode() const;

        void setCode(int code);

        const string &getMessage() const;

        void setMessage(const string &message);

        const string &getToken() const;

        void setToken(const string &token);

        const User &getUser() const;

        void setUser(const User &user);

    private:
        int code;
        string message;
        string token;
        User user;
    };
}

#endif //C_LOGIN_RESULT_H
