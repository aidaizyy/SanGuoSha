//
//  Hero.h
//  SanGuoSha
//
//  Created by 张云尧 on 2017/8/30.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#ifndef Hero_h
#define Hero_h

#include <string>
#include <unordered_map>
using namespace std;

#include "Card.h"
#include "Init.h"

//初始化各英雄
void initCaocaoCards(unordered_map<string, HeroCard*>& c_herocards);
void initSimayiCards(unordered_map<string, HeroCard*>& c_herocards);
void initXiahoudunCards(unordered_map<string, HeroCard*>& c_herocards);
void initZhangliaoCards(unordered_map<string, HeroCard*>& c_herocards);
void initLiubeiCards(unordered_map<string, HeroCard*>& c_herocards);
void initZhugeliangCards(unordered_map<string, HeroCard*>& c_herocards);
void initGuanyuCards(unordered_map<string, HeroCard*>& c_herocards);
void initZhangfeiCards(unordered_map<string, HeroCard*>& c_herocards);

#endif /* Hero_h */
