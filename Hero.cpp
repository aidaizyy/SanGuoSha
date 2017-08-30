//
//  Hero.cpp
//  SanGuoSha
//
//  Created by 张云尧 on 2017/8/30.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include "Hero.h"

//初始化各英雄
void initCaocaoCards(unordered_map<string, HeroCard*>& c_herocards) {
    int numMagic[8];
    for (int i = 0; i < 8; ++i)
        numMagic[i] = 0;
    vector<vector<string>> magics(8);
    numMagic[6] = 2;
    magics[6].push_back(M_JIANXIONG);
    magics[6].push_back(M_HUJIA);
    HeroCard* hero = new HeroCard(1, H_CAOCAO, 0, 4, numMagic, magics);
    c_herocards[H_CAOCAO] = hero;
}

void initSimayiCards(unordered_map<string, HeroCard*>& c_herocards) {
    int numMagic[8];
    for (int i = 0; i < 8; ++i)
        numMagic[i] = 0;
    vector<vector<string>> magics(8);
    numMagic[1] = 1;
    numMagic[6] = 1;
    magics[1].push_back(M_GUICAI);
    magics[6].push_back(M_FANKUI);
    HeroCard* hero = new HeroCard(1, H_SIMAYI, 0, 3, numMagic, magics);
    c_herocards[H_SIMAYI] = hero;
}

void initXiahoudunCards(unordered_map<string, HeroCard*>& c_herocards) {
    int numMagic[8];
    for (int i = 0; i < 8; ++i)
        numMagic[i] = 0;
    vector<vector<string>> magics(8);
    numMagic[6] = 1;
    magics[6].push_back(M_GANGLIE);
    HeroCard* hero = new HeroCard(1, H_XIAHOUDUN, 0, 4, numMagic, magics);
    c_herocards[H_XIAHOUDUN] = hero;
}

void initZhangliaoCards(unordered_map<string, HeroCard*>& c_herocards) {
    int numMagic[8];
    for (int i = 0; i < 8; ++i)
        numMagic[i] = 0;
    vector<vector<string>> magics(8);
    numMagic[2] = 1;
    magics[2].push_back(M_TUXI);
    HeroCard* hero = new HeroCard(1, H_ZHANGLIAO, 0, 4, numMagic, magics);
    c_herocards[H_ZHANGLIAO] = hero;
}

void initLiubeiCards(unordered_map<string, HeroCard*>& c_herocards) {
    int numMagic[8];
    for (int i = 0; i < 8; ++i)
        numMagic[i] = 0;
    vector<vector<string>> magics(8);
    numMagic[3] = 1;
    numMagic[6] = 1;
    magics[3].push_back(M_RENDE);
    magics[6].push_back(M_JIJIANG);
    HeroCard* hero = new HeroCard(1, H_LIUBEI, 1, 4, numMagic, magics);
    c_herocards[H_LIUBEI] = hero;
}

void initZhugeliangCards(unordered_map<string, HeroCard*>& c_herocards) {
    int numMagic[8];
    for (int i = 0; i < 8; ++i)
        numMagic[i] = 0;
    vector<vector<string>> magics(8);
    numMagic[0] = 1;
    numMagic[6] = 1;
    magics[0].push_back(M_GUANXING);
    magics[6].push_back(M_KONGCHENG);
    HeroCard* hero = new HeroCard(1, H_ZHUGELIANG, 1, 3, numMagic, magics);
    c_herocards[H_ZHUGELIANG] = hero;
}
void initGuanyuCards(unordered_map<string, HeroCard*>& c_herocards) {
    int numMagic[8];
    for (int i = 0; i < 8; ++i)
        numMagic[i] = 0;
    vector<vector<string>> magics(8);
    numMagic[3] = 1;
    magics[3].push_back(M_WUSHENG);
    HeroCard* hero = new HeroCard(1, H_GUANYU, 1, 4, numMagic, magics);
    c_herocards[H_GUANYU] = hero;
}
void initZhangfeiCards(unordered_map<string, HeroCard*>& c_herocards) {
    int numMagic[8];
    for (int i = 0; i < 8; ++i)
        numMagic[i] = 0;
    vector<vector<string>> magics(8);
    numMagic[3] = 1;
    magics[3].push_back(M_PAOXIAO);
    HeroCard* hero = new HeroCard(1, H_ZHANGFEI, 1, 4, numMagic, magics);
    c_herocards[H_ZHANGFEI] = hero;
}
