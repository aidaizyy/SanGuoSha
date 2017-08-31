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
#include "Equip.h"
#include "Magic.h"

unordered_map<string, pVoid> Init::magics;
unordered_map<string, HeroCard*> Init::herocards;
unordered_map<string, EquipCard*> Init::equipcards;

//初始化英雄技能，锦囊技能，装备技能
void Init::initMagics(unordered_map<string, pVoid>& magics) {
    magics[M_JIANXIONG] = m_jianxiong;
    magics[M_HUJIA] = m_hujia;
    magics[M_FANKUI] = m_fankui;
    magics[M_GUICAI] = m_guicai;
    magics[M_GANGLIE] = m_ganglie;
    magics[M_TUXI] = m_tuxi;
    magics[M_RENDE] = m_rende;
    magics[M_JIJIANG] = m_jijiang;
    magics[M_GUANXING] = m_guanxing;
    magics[M_KONGCHENG] = m_kongcheng;
    magics[M_WUSHENG] = m_wusheng;
    magics[M_PAOXIAO] = m_paoxiao;
    
    magics[J_WUZHONGSHENGYOU] = m_wuzhongshengyou;
    
    magics[E_ZHUGELIANNU] = m_zhugeliannu;
}

//初始化英雄信息
void Init::initHeroes(unordered_map<string, HeroCard*>& herocards) {
    initCaocao(herocards);
    initSimayi(herocards);
    initXiahoudun(herocards);
    initZhangliao(herocards);
    initLiubei(herocards);
    initZhugeliang(herocards);
    initGuanyu(herocards);
    initZhangfei(herocards);
}

//初始化装备信息
void Init::initEquipments(unordered_map<string, EquipCard*>& equipcards) {
    initZhugeliannu(equipcards);
}

//初始化游戏牌
void Init::initGameCards(CardManager* cards) {
    initEquipCards(cards);
    initMagicCards(cards);
    initBasicCards(cards);
}

//初始化装备牌
void Init::initEquipCards(CardManager* cards) {
    initZhugeliannuCards(cards);
    //...其他装备
}

//初始化锦囊牌
void Init::initMagicCards(CardManager* cards) {
    initWuzhongshengyouCards(cards);
    //...其他锦囊
}

//初始化基本牌
void Init::initBasicCards(CardManager* cards) {
    initShaCards(cards);
    initShanCards(cards);
    initTaoCards(cards);
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

//初始化诸葛连弩牌
void Init::initZhugeliannuCards(CardManager* cards) {
    int pos = (int)cards->cards.size();
    //梅花A
    for (int i = 14; i <= 14; ++i) {
        GameCard* card = new EquipCard(4, E_ZHUGELIANNU, pos++, 2, i, 0, -1);
        cards->cards.push_back(card);
    }
    //方片A
    for (int i = 14; i <= 14; ++i) {
        GameCard* card = new EquipCard(4, E_ZHUGELIANNU, pos++, 3, i, 0, -1);
        cards->cards.push_back(card);
    }
}

//初始化无中生有牌
void Init::initWuzhongshengyouCards(CardManager* cards) {
    int pos = (int)cards->cards.size();
    //红桃7、8、9
    for (int i = 7; i <= 9; ++i) {
        GameCard* card = new MagicCard(4, J_WUZHONGSHENGYOU, pos++, 1, i);
        cards->cards.push_back(card);
    }
    //红桃J
    for (int i = 11; i <= 11; ++i) {
        GameCard* card = new MagicCard(4, J_WUZHONGSHENGYOU, pos++, 1, i);
        cards->cards.push_back(card);
    }
}

//身份牌
vector<string> c_actor = {A_ZHUGONG, A_ZHONGCHEN, A_ZHONGCHEN, A_FANZEI, A_FANZEI, A_FANZEI, A_FANZEI, A_NEIJIAN};

//英雄牌
vector<string> c_hero = {H_CAOCAO, H_SIMAYI, H_XIAHOUDUN, H_ZHANGLIAO, H_LIUBEI, H_ZHUGELIANG, H_GUANYU, H_ZHANGFEI};

//初始化牌
CardManager* Init::initCards() {
    CardManager* cards = CardManager::getInstance();
    initMagics(magics);
    initHeroes(herocards);
    initEquipments(equipcards);
    initGameCards(cards);
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
    manager->setEquipments(equipcards);
    return manager;
}
