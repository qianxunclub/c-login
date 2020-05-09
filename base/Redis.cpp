#include "Redis.h"

using namespace base;

Redis *Redis::redis = new Redis();

Redis::Redis() {

}


Redis *Redis::getRedis() {
    return redis;
}

string Redis::get(string key) {
    this->_reply = (redisReply*)redisCommand(this->_connect, "GET %s", key.c_str());
    std::string str = this->_reply->str;
    freeReplyObject(this->_reply);
    return str;
}

void Redis::set(string key, string value) {
    redisCommand(this->_connect, "SET %s %s", key.c_str(), value.c_str());
}

void Redis::del(string key) {
    redisCommand(this->_connect, "DEL %s", key.c_str());
}

bool Redis::connect(string host, int port) {
    this->_connect = redisConnect(host.c_str(), port);
    if (this->_connect != NULL && this->_connect->err) {
        printf("redis connect error: %s\n", this->_connect->errstr);
        return 0;
    }
    printf("Redis 连接成功:%s\n", host.c_str());
    return 1;
}
