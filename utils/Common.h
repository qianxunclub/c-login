//
// Created by 张斌 on 2020/5/8.
//

#include <random>
#include <aes_encryptor.h>

using namespace std;
using namespace cipher_center;


namespace utils {
    class Common {
    public:

        static void setAesEncryptor(string key);

        static string salt();

        static string random(uint count);

        static string encrypt(string username, string password, string salt);

        static string token(int id, string username);

        static bool sessionTime(string token);

    private:
        static AesEncryptor* aesEncryptor;
    };
}

