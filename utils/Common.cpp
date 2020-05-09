//
// Created by 张斌 on 2020/5/8.
//

#include <aes.h>
#include <Redis.h>
#include "Common.h"
#include "sha256.h"

using namespace utils;
using namespace base;
using namespace cipher_center;

AesEncryptor *Common::aesEncryptor;

string Common::salt() {
    return Common::random(8);
}

string Common::random(uint count) {
    srand(time(0)); //产生随机化种子

    char randomChars[count + 1];
    randomChars[count] = '\0';
    for (uint i = 0; i < count; i++) {
        uint type = rand() % 3;
        switch (type) {
            case 0:
                randomChars[i] = rand() % ('9' - '0' + 1) + '0';
                break;
            case 1:
                randomChars[i] = rand() % ('Z' - 'A' + 1) + 'A';
                break;
            case 2:
                randomChars[i] = rand() % ('z' - 'a' + 1) + 'a';
                break;
            default:
                break;
        }
    }
    return randomChars;
}


string Common::encrypt(string username, string password, string salt) {
    if (username.empty() || password.empty()) {
        return "";
    }
    try {
        string sha256;
        hash256_hex_string(username, sha256);
        const char *c_account = sha256.c_str();

        const char *c_salt = salt.c_str();

        const char *c_password = password.c_str();

        size_t length = strlen(c_account) + strlen(c_salt) + strlen(c_password);
        char c_source[length + 1];
        snprintf(c_source, length + 1, "%s%s%s", c_account, c_salt, c_password);

        string sha256_enc_password;
        hash256_hex_string((string) c_source, sha256_enc_password);
        return sha256_enc_password;
    }
    catch (exception &e) {
        return "";
    }
}

string Common::token(int id, string username) {
    char strChar[256];
    snprintf(strChar, 256, "%d%s", id, username.c_str());
    string str = strChar;
    string token = Common::aesEncryptor->EncryptString(str);
    return token;
}

void Common::setAesEncryptor(string key) {
    aesEncryptor = new AesEncryptor((unsigned char *) key.c_str());
}

bool Common::sessionTime(string token) {
    string t = Redis::getRedis()->get(token);
    if (t.empty()) {
        return false;
    }
    int now = clock();
    int loginTime = atoi(t.c_str());

    if (((now - loginTime) / 1000 / 60) > 1) {
        return false;
    }
    return true;
}
