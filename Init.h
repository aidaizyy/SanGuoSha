//
//  Init.h
//  SanGuoSha
//
//  Created by 张云尧 on 2017/8/29.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#ifndef Init_h
#define Init_h

#include <vector>
#include <algorithm>
using namespace std;

#include "Manager.h"
#include "Card.h"
#include "Player.h"

//基本牌
#define C_SHA "杀"
#define C_SHAN "闪"
#define C_TAO "桃"

//身份
#define A_ZHUGONG "主公"
#define A_ZHONGCHEN "忠臣"
#define A_FANZEI "反贼"
#define A_NEIJIAN "内奸"

//英雄
#define H_CAOCAO "曹操"
#define H_SIMAYI "司马懿"
#define H_XIAHOUDUN "夏侯惇"
#define H_ZHANGLIAO "张辽"
#define H_LIUBEI "刘备"
#define H_ZHUGELIANG "诸葛亮"
#define H_GUANYU "关羽"
#define H_ZHANGFEI "张飞"

//英雄技能
#define M_JIANXIONG "奸雄"
#define M_HUJIA "护驾"
#define M_FANKUI "反馈"
#define M_GUICAI "鬼才"
#define M_GANGLIE "刚烈"
#define M_TUXI "突袭"
#define M_RENDE "仁德"
#define M_JIJIANG "激将"
#define M_GUANXING "观星"
#define M_KONGCHENG "空城"
#define M_WUSHENG "武圣"
#define M_PAOXIAO "咆哮"

//锦囊牌
#define J_WUZHONGSHENGYOU "无中生有"
#define J_WUXIEKEJI "无懈可击"

//装备牌
#define E_ZHUGELIANNU "诸葛连弩"

typedef vector<int>(*pVoid)();

class Init {
public:
    static Manager* init(int num);  //初始化
    static CardManager* initCards();    //初始化牌
    static vector<Player*> initPlayers(int num);    //初始化玩家
    static void extractActors(vector<Player*>&);    //分配身份
    static void extractHeroes(vector<Player*>&);    //分配英雄
    static unordered_map<string, pVoid> magics;     //字符串标识英雄技能
    static unordered_map<string, HeroCard*> herocards; //字符串标识英雄信息
    static unordered_map<string, EquipCard*> equipcards;    //字符串标识装备信息
    static unordered_map<string, MagicCard*> magiccards;    //字符串标识锦囊信息
private:
    static void initMagics(unordered_map<string, pVoid>& magics); //初始化英雄技能
    static void initHeroes(unordered_map<string, HeroCard*>& herocards); //初始化英雄信息
    static void initEquipments(unordered_map<string, EquipCard*>& equipcards); //初始化装备信息
    
    static void initGameCards(CardManager*);    //初始化游戏牌
    static void initEquipCards(CardManager*);   //初始化装备牌
    static void initMagicCards(CardManager*);   //初始化锦囊牌
    static void initBasicCards(CardManager*);   //初始化基本牌
    
    static void initShaCards(CardManager*);    //初始化杀牌
    static void initShanCards(CardManager*);    //初始化闪牌
    static void initTaoCards(CardManager*);     //初始化桃牌
    
    static void initZhugeliannuCards(CardManager*); //初始化诸葛连弩牌
    
    static void initWuzhongshengyouCards(CardManager*); //初始化无中生有牌
    static int myrandom(int i) {
        return rand() % i;
    }
};

#endif /* Init_h */
