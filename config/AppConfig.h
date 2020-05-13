//
// Created by 张斌 on 2020/5/7.
//
#include <string>
#include "libs/json/json.h"

using namespace std;

namespace appConfig {
    class DbConfig {
    public:
        DbConfig();

        const string &getHost() const;

        void setHost(const string &host);

        int getPort() const;

        void setPort(int port);

        const string &getUsername() const;

        void setUsername(const string &username);

        const string &getPassword() const;

        void setPassword(const string &password);

        const string &getDatabase() const;

        void setDatabase(const string &database);

    private:
        string host;
        int port;
        string username;
        string password;
        string database;
        void getDbConfig();

    };

    class RedisConfig {
    public:
        RedisConfig();

        RedisConfig(const string &host, int port);

        const string &getHost() const;

        void setHost(const string &host);

        int getPort() const;

        void setPort(int port);

    private:
        string host;
        int port;
        void getRedisConfig();
    };
    Json::Value config();
}