//
// Created by 张斌 on 2020/5/7.
//

#include <User.h>
#include "UserRepository.h"
#include "Database.h"

using namespace model;
using namespace repository;

Database database;

bool UserRepository::query() {
    MYSQL_RES *res;
    MYSQL_ROW row;
    const char *sql = "select * from tb_account";
    mysql_query(&database.mysql, sql);
    res = mysql_store_result(&database.mysql);
    while (row = mysql_fetch_row(res)) {
        User user = User();
        user.setId(atoi(row[0]));
        user.setUsername(row[1]);
    }
    mysql_free_result(res);
}

bool UserRepository::isRegister() {
    MYSQL_RES *res;
    const char *sql = "select * from tb_account";
    mysql_query(&database.mysql, sql);
    res = mysql_store_result(&database.mysql);
    int count = mysql_affected_rows(&database.mysql);
    if (count > 0) {
        return true;
    }
    return false;
}
