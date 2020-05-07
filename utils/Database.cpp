//
// Created by 张斌 on 2020/5/7.
//

#include "Database.h"
#include <string>


using namespace std;
using namespace appConfig;


Database *Database::database = new Database();

Database *Database::getDatabase() {
    return database;
}

Database::Database() {
    DbConfig dbConfig;
    Database::connect(dbConfig.getHost(), dbConfig.getPort(), dbConfig.getUsername(), dbConfig.getPassword(),
                      dbConfig.getDatabase());
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
    return true;
}

const MYSQL &Database::getMysql() const {
    return mysql;
}
