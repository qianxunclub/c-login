//
// Created by 张斌 on 2020/5/7.
//

#include "DbConfig.h"
#include <string>
#include <mysql/mysql.h>

using namespace std;

class Database {

public:
    Database();

    MYSQL mysql;

    const MYSQL &getMysql() const;

    bool connect(string host, int port, string username, string password, string database);

    static Database *getDatabase();

private:
    bool isConnect = false;
    static Database *database;

};


