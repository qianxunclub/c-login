//
// Created by 张斌 on 2020/5/7.
//

#include <string>
#include <Result.h>

using namespace std;


class LoginService {
public:
    model::Result registerUser(string username, string password);

    model::Result login(string username, string password);

    model::User userInfo(string token);

    bool logout(string token);
};


