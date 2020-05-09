//
// Created by 张斌 on 2020/5/7.
//

#include <UserRepository.h>
#include <Common.h>
#include <Redis.h>
#include <json/json.h>
#include "LoginService.h"

using namespace repository;
using namespace utils;
using namespace model;
using namespace base;

UserRepository userRepository;

Result LoginService::registerUser(string username, string password) {
    string salt = Common::salt().c_str();
    string encryptPwd = Common::encrypt(username, password, salt);
    return userRepository.registerUser(username, encryptPwd, salt);
}

Result LoginService::login(string username, string password) {
    User user;
    if (!userRepository.isRegister(username)) {
        return Result(1, "用户不存在", "", user);
    }

    user = userRepository.userInfo(username);
    string encryptPwd = Common::encrypt(username, password, user.getSalt());
    if (encryptPwd != user.getPassword()) {
        return Result(1, "密码错误", "", user);
    }
    string token = Common::token(user.getId(), username);
    char value[256];
    sprintf(value, "{\"username\":\"%s\",\"time\":%lu}", user.getUsername().c_str(), clock());
    Redis::getRedis()->set(token, value);
    return Result(0, "登录成功", token, user);
}

User LoginService::userInfo(string token) {
    if (!Common::sessionTime(token)) {
        return User();
    }
    string value = Redis::getRedis()->get(token);
    Json::Reader reader;
    Json::Value root;
    //从字符串中读取数据
    if (reader.parse(value, root)) {
        string username = root["username"].asString();
        return userRepository.userInfo(username);
    }
    return User();
}

bool LoginService::logout(string token) {
    return false;
}
