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

//初始化各英雄信息
void initCaocao(unordered_map<string, HeroCard*>& herocards);
void initSimayi(unordered_map<string, HeroCard*>& herocards);
void initXiahoudun(unordered_map<string, HeroCard*>& herocards);
void initZhangliao(unordered_map<string, HeroCard*>& herocards);
void initLiubei(unordered_map<string, HeroCard*>& herocards);
void initZhugeliang(unordered_map<string, HeroCard*>& herocards);
void initGuanyu(unordered_map<string, HeroCard*>& herocards);
void initZhangfei(unordered_map<string, HeroCard*>& herocards);

#endif /* Hero_h */
