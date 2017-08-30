//
//  Init.cpp
//  SanGuoSha
//
//  Created by 张云尧 on 2017/8/29.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <unordered_map>

#include "Init.h"
#include "Hero.h"
#include "Magic.h"

unordered_map<string, pVoid> Init::magics;
unordered_map<string, HeroCard*> Init::herocards;

//初始化英雄技能
void Init::initMagics(unordered_map<string, pVoid>& magics) {
    magics[M_JIANXIONG] = jianxiong;
    magics[M_HUJIA] = hujia;
    magics[M_FANKUI] = fankui;
    magics[M_GUICAI] = guicai;
    magics[M_GANGLIE] = ganglie;
    magics[M_TUXI] = tuxi;
    magics[M_RENDE] = rende;
    magics[M_JIJIANG] = jijiang;
    magics[M_GUANXING] = guanxing;
    magics[M_KONGCHENG] = kongcheng;
    magics[M_WUSHENG] = wusheng;
    magics[M_PAOXIAO] = paoxiao;
}

//初始化英雄牌
void Init::initHeroCards(unordered_map<string, HeroCard*>& herocards) {
    initCaocaoCards(herocards);
    initSimayiCards(herocards);
    initXiahoudunCards(herocards);
    initZhangliaoCards(herocards);
    initLiubeiCards(herocards);
    initZhugeliangCards(herocards);
    initGuanyuCards(herocards);
    initZhangfeiCards(herocards);
}

//初始化杀牌
void Init::initShaCards(CardManager* cards) {
    int pos = (int)cards->cards.size();
    for (int i = 7; i <= 10; ++i) {
        GameCard* card = new BasicCard(2, C_SHA, pos++, 0, i);
        cards->cards.push_back(card);
    }
    for (int i = 8; i <= 10; ++i) {
        GameCard* card = new BasicCard(2, C_SHA, pos++, 0, i);
        cards->cards.push_back(card);
    }
    for (int i = 10; i <= 11; ++i) {
        GameCard* card = new BasicCard(2, C_SHA, pos++, 1, i);
        cards->cards.push_back(card);
    }
    for (int i = 11; i <= 11; ++i) {
        GameCard* card = new BasicCard(2, C_SHA, pos++, 1, i);
        cards->cards.push_back(card);
    }
    for (int i = 2; i <= 11; ++i) {
        GameCard* card = new BasicCard(2, C_SHA, pos++, 2, i);
        cards->cards.push_back(card);
    }
    for (int i = 8; i <= 11; ++i) {
        GameCard* card = new BasicCard(2, C_SHA, pos++, 2, i);
        cards->cards.push_back(card);
    }
    for (int i = 6; i <= 10; ++i) {
        GameCard* card = new BasicCard(2, C_SHA, pos++, 3, i);
        cards->cards.push_back(card);
    }
    for (int i = 13; i <= 13; ++i) {
        GameCard* card = new BasicCard(2, C_SHA, pos++, 3, i);
        cards->cards.push_back(card);
    }
}

//初始化闪牌
void Init::initShanCards(CardManager* cards) {
    int pos = (int)cards->cards.size();
    for (int i = 2; i <= 2; ++i) {
        GameCard* card = new BasicCard(2, C_SHAN, pos++, 1, i);
        cards->cards.push_back(card);
    }
    for (int i = 2; i <= 2; ++i) {
        GameCard* card = new BasicCard(2, C_SHAN, pos++, 1, i);
        cards->cards.push_back(card);
    }
    for (int i = 13; i <= 13; ++i) {
        GameCard* card = new BasicCard(2, C_SHAN, pos++, 1, i);
        cards->cards.push_back(card);
    }
    for (int i = 2; i <= 11; ++i) {
        GameCard* card = new BasicCard(2, C_SHAN, pos++, 3, i);
        cards->cards.push_back(card);
    }
    for (int i = 2; i <= 2; ++i) {
        GameCard* card = new BasicCard(2, C_SHAN, pos++, 3, i);
        cards->cards.push_back(card);
    }
    for (int i = 11; i <= 11; ++i) {
        GameCard* card = new BasicCard(2, C_SHAN, pos++, 3, i);
        cards->cards.push_back(card);
    }
}

//初始化桃牌
void Init::initTaoCards(CardManager* cards) {
    int pos = (int)cards->cards.size();
    for (int i = 3; i <= 4; ++i) {
        GameCard* card = new BasicCard(2, C_TAO, pos++, 1, i);
        cards->cards.push_back(card);
    }
    for (int i = 6; i <= 9; ++i) {
        GameCard* card = new BasicCard(2, C_TAO, pos++, 1, i);
        cards->cards.push_back(card);
    }
    for (int i = 12; i <= 12; ++i) {
        GameCard* card = new BasicCard(2, C_TAO, pos++, 1, i);
        cards->cards.push_back(card);
    }
    for (int i = 12; i <= 12; ++i) {
        GameCard* card = new BasicCard(2, C_TAO, pos++, 3, i);
        cards->cards.push_back(card);
    }
}

//初始化装备牌
void Init::initEquipCards(CardManager* cards) {
    //...
}

//初始化锦囊牌
void Init::initMagicCards(CardManager* cards) {
    //...
}

vector<string> c_actor = {A_ZHUGONG, A_ZHONGCHEN, A_ZHONGCHEN, A_FANZEI, A_FANZEI, A_FANZEI, A_FANZEI, A_NEIJIAN};
vector<string> c_hero = {H_CAOCAO, H_SIMAYI, H_XIAHOUDUN, H_ZHANGLIAO, H_LIUBEI, H_ZHUGELIANG, H_GUANYU, H_ZHANGFEI};

//初始化牌
CardManager* Init::initCards() {
    CardManager* cards = CardManager::getInstance();
    Init::initMagics(magics);
    Init::initHeroCards(herocards);
    Init::initShaCards(cards);
    Init::initShanCards(cards);
    Init::initTaoCards(cards);
    Init::initEquipCards(cards);
    Init::initMagicCards(cards);
    return cards;
}

//初始化玩家
vector<Player*> Init::initPlayers(int num) {
    vector<Player*> players;
    for (int i = 0; i < num; ++i) {
        Player* player = new Player();
        player->setPos(i);
        players.push_back(player);
    }
    return players;
}

//分配身份
void Init::extractActors(vector<Player*>& players) {
    int num = (int)players.size();
    random_shuffle(c_actor.begin(), c_actor.end(), myrandom);
    if (num == 8) {
        for (int i = 0; i < num; ++i) {
            ActorCard actor(0, c_actor[i]);
            players[i]->setActor(actor);
        }
    } else {
        //...
    }
}

//分配英雄
void Init::extractHeroes(vector<Player*>& players) {
    int num = (int)players.size();
    random_shuffle(c_hero.begin(), c_hero.end(), myrandom);
    if (num == 8) {
        for (int i = 0; i < num; ++i) {
            players[i]->setHero(*herocards[c_hero[i]]);
            players[i]->health = herocards[c_hero[i]]->getHealth();
        }
    } else {
        //...
    }
}

//初始化
Manager* Init::init(int num) {
    CardManager* cards = Init::initCards();
    vector<Player*> players = Init::initPlayers(num);
    Init::extractActors(players);
    Init::extractHeroes(players);
    Manager* manager = Manager::getInstance(cards, num, players);
    manager->setMagics(magics);
    manager->setHeroes(herocards);
    return manager;
}
