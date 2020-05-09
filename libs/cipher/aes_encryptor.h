//
// Created by melon on 2019/2/28.
//

#include <string>

class AES;

namespace cipher_center{

    class AesEncryptor
    {
    public:
        AesEncryptor(unsigned char* key);
        ~AesEncryptor(void);

        std::string EncryptString(std::string strInfor);
        std::string DecryptString(std::string strMessage);

    private:
        void Byte2Hex(const unsigned char* src, int len, char* dest);
        void Hex2Byte(const char* src, int len, unsigned char* dest);
        int  Char2Int(char c);

    private:
        AES* m_pEncryptor;
    };

}
