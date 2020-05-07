//
// Created by 张斌 on 2020/5/7.
//
#include <string>

using namespace std;

namespace model {
    class User {
    public:
        int getId() const;

        void setId(int id);

        const string &getUsername() const;

        void setUsername(const string &username);

        const string &getPassword() const;

        void setPassword(const string &password);

        const string &getSalt() const;

        void setSalt(const string &salt);

    private:
        int id;
        string username;
        string password;
        string salt;
    };
}