//
// Created by 张斌 on 2020/5/7.
//

#include "config/AppConfig.h"
#include <string>
#include "libs/mysql/mysql.h"

using namespace std;
namespace base {
    class Database {

    public:
        Database();

        MYSQL mysql;

        bool connect(string host, int port, string username, string password, string database);

        static Database *getDatabase();

        static bool CheckSQL(string sql);

        static bool CheckParameter(string Parameter);

    private:
        bool isConnect = false;
        static Database *database;

    };
}

