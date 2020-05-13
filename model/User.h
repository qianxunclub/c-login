//
// Created by 张斌 on 2020/5/7.
//
#ifndef C_LOGIN_USER_H
#define C_LOGIN_USER_H

#include <string>

using namespace std;

namespace model {
    class User {
    public:
        User();

        User(int id, const string &username, const string &password, const string &salt);

        int getId() const;

        void setId(int id);

        const string &getUsername() const;

        void setUsername(const string &username);

        const string &getPassword() const;

        void setPassword(const string &password);

        const string &getSalt() const;

        void setSalt(const string &salt);

    private:
        int id;
        string username;
        string password;
        string salt;
    };
}

#endif //C_LOGIN_USER_H
