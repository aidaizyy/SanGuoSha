//
//  main.cpp
//  SanGuoSha
//
//  Created by 张云尧 on 2017/8/29.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

#include "Init.h"

int main(int argc, const char * argv[]) {
    srand((unsigned)time(0));
    Manager* manager = Init::init(8);
    manager->begin();
    manager->run();
    return 0;
}
