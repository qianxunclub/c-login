//
// Created by 张斌 on 2020/5/7.
//

#include <UserRepository.h>
#include "Main.h"
#include "stdio.h"

using namespace std;
using namespace repository;


int main() {
    UserRepository userRepository;
    bool r = userRepository.isRegister();
    if(r){
        printf("已经注册");
    } else{
        printf("可以注册");
    }
}