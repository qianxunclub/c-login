//
// Created by 张斌 on 2020/5/7.
//

#include <fstream>
#include <iostream>
#include "AppConfig.h"
#include <json/json.h>


namespace appConfig {

    using std::cout;
    using std::endl;
    using std::ifstream;

    DbConfig::DbConfig() {
        try {
            getDbConfig();
        } catch (const std::exception &e) {
            cout << e.what() << endl;
        }
    }

    void DbConfig::getDbConfig() {
        Json::Value root = config();
        DbConfig::setHost(root["db"]["host"].asString());
        DbConfig::setPort(root["db"]["port"].asInt());
        DbConfig::setDatabase(root["db"]["database"].asString());
        DbConfig::setUsername(root["db"]["username"].asString());
        DbConfig::setPassword(root["db"]["password"].asString());
    }

    Json::Value config() {
        Json::Reader reader;
        Json::Value root;
        ifstream in("../resource/config.json", ios::binary);

        if (!in.is_open()) {
            cout << "Error opening file\n";
            return "";
        }

        if (!reader.parse(in, root)) {
            cout << "Error parse file\n";
            return "";
        }
        in.close();
        return root;
    }

    const string &DbConfig::getHost() const {
        return host;
    }

    void DbConfig::setHost(const string &host) {
        DbConfig::host = host;
    }

    int DbConfig::getPort() const {
        return port;
    }

    void DbConfig::setPort(int port) {
        DbConfig::port = port;
    }

    const string &DbConfig::getUsername() const {
        return username;
    }

    void DbConfig::setUsername(const string &username) {
        DbConfig::username = username;
    }

    const string &DbConfig::getPassword() const {
        return password;
    }

    void DbConfig::setPassword(const string &password) {
        DbConfig::password = password;
    }

    const string &DbConfig::getDatabase() const {
        return database;
    }

    void DbConfig::setDatabase(const string &database) {
        DbConfig::database = database;
    }

    RedisConfig::RedisConfig(const string &host, int port) : host(host), port(port) {}

    const string &RedisConfig::getHost() const {
        return host;
    }

    void RedisConfig::setHost(const string &host) {
        RedisConfig::host = host;
    }

    int RedisConfig::getPort() const {
        return port;
    }

    void RedisConfig::setPort(int port) {
        RedisConfig::port = port;
    }

    void RedisConfig::getRedisConfig() {
        Json::Value root = config();
        RedisConfig::setHost(root["redis"]["host"].asString());
        RedisConfig::setPort(root["redis"]["port"].asInt());
    }

    RedisConfig::RedisConfig() {
        try {
            getRedisConfig();
        } catch (const std::exception &e) {
            cout << e.what() << endl;
        }
    }
}