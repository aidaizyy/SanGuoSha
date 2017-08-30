//
//  Player.h
//  SanGuoSha
//
//  Created by 张云尧 on 2017/8/29.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include "Card.h"

class Player {
private:
    int pos;    //座位
    ActorCard* actor;   //身份
    HeroCard* hero;     //英雄
    bool hasEquipment[3];  //是否有武器，马匹，防具
    string equipment[3]; //武器，马匹，防具具体名称
public:
    Player() {
        hasEquipment[0] = false;
        hasEquipment[1] = false;
        hasEquipment[2] = false;
    }
    void setPos(int p) {
        pos = p;
    }
    void setActor(ActorCard a) {
        actor = new ActorCard(a);
    }
    void setHero(HeroCard a) {
        hero = new HeroCard(a);
    }
    int getPos() {
        return pos;
    }
    ActorCard* getActor() {
        return actor;
    }
    HeroCard* getHero() {
        return hero;
    }
    bool* getHasEquipment() {
        return hasEquipment;
    }
    string* getEquipment() {
        return equipment;
    }
    vector<GameCard*> cards;
    int numCards;
    int health;
};

#endif /* Player_h */
