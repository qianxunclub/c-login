//
// Created by 张斌 on 2020/5/7.
//

#include "User.h"

using namespace model;
using namespace std;

User::User() {

}

User::User(int id, const string &username, const string &password, const string &salt) : id(id), username(username),
                                                                                         password(password),
                                                                                         salt(salt) {}

int User::getId() const {
    return id;
}

void User::setId(int id) {
    User::id = id;
}

const string &User::getUsername() const {
    return username;
}

void User::setUsername(const string &username) {
    User::username = username;
}

const string &User::getPassword() const {
    return password;
}

void User::setPassword(const string &password) {
    User::password = password;
}

const string &User::getSalt() const {
    return salt;
}

void User::setSalt(const string &salt) {
    User::salt = salt;
}
