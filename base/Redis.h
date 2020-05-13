//
// Created by 张斌 on 2020/5/8.
//

#ifndef C_LOGIN_REDIS_H
#define C_LOGIN_REDIS_H

#include <string>
#include "../libs/hiredis/hiredis.h"

using namespace std;

namespace base {
    class Redis {

    public:
        Redis();
        static Redis *getRedis();
        bool connect(string host, int port);

        string get(string key);

        void set(string key, string value);

        void del(string key);

    private:
        redisContext *_connect;
        redisReply *_reply;
        static Redis *redis;

    };
}
#endif //C_LOGIN_REDIS_H
