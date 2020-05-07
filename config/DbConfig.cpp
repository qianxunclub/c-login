//
// Created by 张斌 on 2020/5/7.
//

#include <fstream>
#include <iostream>
#include "DbConfig.h"
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
        Json::Reader reader;
        Json::Value root;
        ifstream in("../resource/config.json", ios::binary);

        if (!in.is_open()) {
            cout << "Error opening file\n";
            return;
        }

        if (!reader.parse(in, root)) {
            cout << "Error parse file\n";
            return;
        }
        DbConfig::setHost(root["db"]["host"].asString());
        DbConfig::setPort(root["db"]["port"].asInt());
        DbConfig::setDatabase(root["db"]["database"].asString());
        DbConfig::setUsername(root["db"]["username"].asString());
        DbConfig::setPassword(root["db"]["password"].asString());
        in.close();
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
}