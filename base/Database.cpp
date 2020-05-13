//
// Created by 张斌 on 2020/5/7.
//

#include "Database.h"
#include <string>


using namespace std;
using namespace appConfig;
using namespace base;


Database *Database::database = new Database();

Database *Database::getDatabase() {
    return database;
}

Database::Database() {
}

bool Database::connect(string host, int port, string username, string password, string database) {
    if (isConnect) {
        return true;
    }
    if (mysql_init(&mysql) == NULL) {
        return false;
    }
    if (mysql_real_connect(&mysql, host.c_str(), username.c_str(), password.c_str(), database.c_str(), port, NULL, 0) ==
        NULL) {
        printf("Error connecting to database:%s\n", mysql_error(&mysql));
        return false;
    }
    isConnect = true;
    printf("数据库连接成功:%s\n", host.c_str());
    return true;
}

bool Database::CheckSQL(string sql) {
    string key[9] = {"%", "/", "union", "|", "&", "^", "#", "/*", "*/"};
    for (int i = 0; i < 9; i++) {
        if (sql.find(key[i]) != string::npos) {
            return false;
        }
    }
    return true;
}

bool Database::CheckParameter(string Parameter) {
    string key[14] = {"and", "*", "=", " ", "%0a", "%", "/", "union", "|", "&", "^", "#", "/*", "*/"};
    for (int i = 0; i < 14; i++) {
        if (Parameter.find(key[i]) != string::npos) {
            return false;
        }
    }
    return true;
}
