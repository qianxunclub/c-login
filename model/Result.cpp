//
// Created by 张斌 on 2020/5/8.
//

#include "Result.h"

Result::Result(int code, const string &message, const string &token, const User &user) : code(code),
                                                                                         message(message),
                                                                                         token(token),
                                                                                         user(user) {}

int Result::getCode() const {
    return code;
}

void Result::setCode(int code) {
    Result::code = code;
}

const string &Result::getMessage() const {
    return message;
}

void Result::setMessage(const string &message) {
    Result::message = message;
}

const string &Result::getToken() const {
    return token;
}

void Result::setToken(const string &token) {
    Result::token = token;
}

const User &Result::getUser() const {
    return user;
}

void Result::setUser(const User &user) {
    Result::user = user;
}

Result::Result(int code, const string &message) : code(code), message(message) {}

Result::Result(int code) : code(code) {}
