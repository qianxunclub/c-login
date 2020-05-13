//
// Created by 张斌 on 2020/5/7.
//

#include "../model/User.h"
#include "../utils/Common.h"
#include "../repository/UserRepository.h"
#include "../base/Database.h"

using namespace model;
using namespace utils;
using namespace repository;
using namespace base;


/**
 * 校验是否已经注册
 * @return
 */
bool UserRepository::isRegister(string username) {
    if (!Database::getDatabase()->CheckParameter(username)) {
        printf("用户名包含敏感字符：%s\n", username.c_str());
    }
    char sql[256];
    sprintf(sql, "select * from user where username = '%s'", username.c_str());
    mysql_query(&Database::getDatabase()->mysql, sql);
    MYSQL_RES *res;
    res = mysql_store_result(&Database::getDatabase()->mysql);
    const char *error = mysql_error(&Database::getDatabase()->mysql);
    if (strlen(error) > 0) {
        printf("校验用户是否存在失败：%s\n", error);
        mysql_free_result(res);
        return false;
    }
    int count = mysql_affected_rows(&Database::getDatabase()->mysql);

    mysql_free_result(res);
    return count > 0;
}

/**
 * 注册
 * @return
 */
Result UserRepository::registerUser(string username, string password, string salt) {
    if (isRegister(username)) {
        printf("该用户名已经注册：%s\n", username.c_str());
        return Result(1, "该用户名已经注册");
    }
    char sql[256];
    sprintf(sql, "insert into user(username,password,salt) values ('%s','%s','%s')", username.c_str(), password.c_str(),
            salt.c_str());
    mysql_query(&Database::getDatabase()->mysql, sql);
    const char *error = mysql_error(&Database::getDatabase()->mysql);
    if (strlen(error) > 0) {
        return Result(1, error);
    }

    return Result(0);
}

User UserRepository::userInfo(string username) {
    User user = User();
    MYSQL_RES *res;
    char sql[256];
    sprintf(sql, "select * from user where username = '%s'", username.c_str());
    mysql_query(&Database::getDatabase()->mysql, sql);
    res = mysql_store_result(&Database::getDatabase()->mysql);
    if (mysql_affected_rows(&Database::getDatabase()->mysql) <= 0) {
        printf("用户不存在：%s\n", username.c_str());
        return user;
    }
    MYSQL_ROW row = mysql_fetch_row(res);
    user.setId(atoi(row[0]));
    user.setUsername(row[1]);
    user.setPassword(row[2]);
    user.setSalt(row[3]);
    mysql_free_result(res);
    return user;
}

User UserRepository::queryUser(string username, string password) {
    User user = User();
    MYSQL_RES *res;
    char sql[256];
    sprintf(sql, "select * from user where username = '%s' and password = '%s'", username.c_str(), password.c_str());
    mysql_query(&Database::getDatabase()->mysql, sql);
    res = mysql_store_result(&Database::getDatabase()->mysql);
    if (mysql_affected_rows(&Database::getDatabase()->mysql) <= 0) {
        printf("用户不存在：%s\n", username.c_str());
        return user;
    }
    MYSQL_ROW row = mysql_fetch_row(res);
    user.setId(atoi(row[0]));
    user.setUsername(row[1]);
    user.setPassword(row[2]);
    user.setSalt(row[3]);
    mysql_free_result(res);
    return user;
}
