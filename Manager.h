//
//  Manager.h
//  SanGuoSha
//
//  Created by 张云尧 on 2017/8/29.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#ifndef Manager_h
#define Manager_h

#include <iostream>
using namespace std;

#include "Card.h"
#include "Player.h"

typedef vector<int>(*pVoid)();

class Manager {
private:
    CardManager* cards; //所有游戏牌
    int numPlayers;     //玩家数量
    vector<Player*> players;    //玩家信息
    int numActors[4];   //主公，忠臣，反贼，内奸的数量
    int isZhugong;  //主公的位置
    unordered_map<string, pVoid> magics;    //所有的英雄技能
    unordered_map<string, HeroCard*> heroes;    //所有的英雄信息
    static Manager* manager;
    Manager(CardManager* c, int n, vector<Player*> p) : cards(c), numPlayers(n), players(p) {};
    
    void countInfo();   //统计信息
    
    int getNumCards();  //获得所有游戏牌的数量
    void setPos(int pos);
    int getPos();
    void shuffleCards();    //洗牌
    void setExist(int pos, bool b);
    bool getExist(int pos);
    
    void addCardForOne(int player, int pos);    //某玩家增加一张牌
    void delCardForOne(int player, int pos);    //某玩家删除一张牌
    GameCard* getCardForOne(int player, int pos);   //返回某玩家的一张牌
    int getNumCardsForOne(int player);  //返回某玩家的牌的数量
    void setExistForOne(int player, int pos, bool b);
    int getNumMagic(int player, int type);  //返回某玩家某种类型的英雄技能数量
    vector<string> getMagic(int player, int type); //返回某玩家某种类型的英雄技能名词，配合heroes调用函数
    
    void printInfo();   //打印所有玩家可见信息
    void printCards(int player);    //打印某玩家的手牌情况
    void touchCards(int player);    //某玩家摸一张牌
    void useCards(int player);      //某玩家出牌
    void recv(int player, int from, int type);  //某玩家被杀或被桃
    void dead(int player);  //某玩家死亡
    void judge(int player, int type);   //判定
    
    bool useSha(int player); //出杀
    bool useTao(int player); //出桃
    bool recvSha(int player, int from); //被杀
    bool recvTao(int player, int from); //被桃
    
    bool isQuit;
    
public:
    static Manager* getInstance(CardManager* c = nullptr, int n = 0, vector<Player*> p = vector<Player*>()) {
        if (manager == nullptr)
            manager = new Manager(c, n, p);
        return manager;
    }
    CardManager* getCards() {
        return cards;
    }
    int getNumPlayers() {
        return numPlayers;
    }
    void setMagics(unordered_map<string, pVoid>& m) {
        magics = m;
    }
    void setHeroes(unordered_map<string, HeroCard*>& h) {
        heroes = h;
    }
    unordered_map<string, pVoid> getMagics() {
        return magics;
    }
    unordered_map<string, HeroCard*> getHeroes() {
        return heroes;
    }
    vector<Player*> getPlayers() {
        return players;
    }
    
    void begin();   //游戏准备
    void run();     //游戏开始
};

#endif /* Manager_h */
