//
//  Card.h
//  SanGuoSha
//
//  Created by 张云尧 on 2017/8/29.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#ifndef Card_h
#define Card_h

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//牌
class Card {
private:
    int type;   //0:Actor; 1:Hero; 2:Basic; 3:Equipment; 4:Magic;
    string content; //内容
public:
    Card(int t, string c) : type(t), content(c) {};
    int getType() {
        return type;
    }
    string getContent() {
        return content;
    }
};

//身份牌
class ActorCard : public Card {
public:
    ActorCard(int t, string c) : Card(t, c) {};
};

//英雄牌
class HeroCard : public Card {
private:
    int country;    //0:魏; 1:蜀
    int health;     //生命
    int numMagic[8];    //0:准备; 1:判定; 2:摸排; 3:出牌; 4:弃牌; 5:结束; 6:被动; 7:锁定;
    vector<vector<string>> magics;
public:
    HeroCard(int t, string c, int co, int h, int n[8], vector<vector<string>>& m) : Card(t, c), magics(m), country(co), health(h) {
        for (int i = 0; i < 8; ++i)
            numMagic[i] = n[i];
    };
    int getCountrt() {
        return country;
    }
    int getHealth() {
        return health;
    }
    int* getNumMagic() {
        return numMagic;
    }
    vector<vector<string>> getMagics() {
        return magics;
    }
};

//游戏牌
class GameCard : public Card {
private:
    int id;     //唯一id，用作洗牌
    int color;   //黑桃 = 0, 红心 = 1, 梅花 = 2, 方块 = 3
    int num;    //2 - 14, 11 = J, 12 = Q, 13 = K, 14 = A
public:
    GameCard(int t, string c, int i, int co, int n) : Card(t, c), id(i), color(co), num(n) {};
    int getId() {
        return id;
    }
    int getColor() {
        return color;
    }
    int getNum() {
        return num;
    }
};

//基本牌
class BasicCard : public GameCard {
public:
    BasicCard(int t, string c, int i, int co, int n) : GameCard(t, c, i, co, n) {};
};

//装备牌
class EquipCard : public GameCard {
private:
    int equipment;  //0:武器; 1:马匹; 2:防具;
    int distance;   //加成的距离
public:
    EquipCard(int t, string c, int i, int co, int n, int e, int d) : GameCard(t, c, i, co, n), equipment(e), distance(d) {};
    int getEquipment() {
        return equipment;
    }
    int getDistance() {
        return distance;
    }
};

//锦囊牌
class MagicCard : public GameCard {
public:
    MagicCard(int t, string c, int i, int co, int n) : GameCard(t, c, i, co, n) {};
};

//...
class CardManager {
private:
    static CardManager* manager;
    CardManager() {};
public:
    static CardManager* getInstance() {
        if (manager == nullptr)
            manager = new CardManager();
        return manager;
    }
    int nowCards;
    vector<GameCard*> cards;
    unordered_map<int, bool> exist;
};

#endif /* Card_h */
