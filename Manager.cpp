//
//  Manager.cpp
//  SanGuoSha
//
//  Created by 张云尧 on 2017/8/30.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include "Manager.h"
#include "Init.h"

Manager* Manager::manager = nullptr;

//游戏准备
void Manager::begin() {
    if (manager == nullptr)
        return ;
    countInfo();
    for (int i = 0; i < getNumCards(); ++i) {
        setExist(i, true);
    }
    //洗牌
    shuffleCards();
    int pos = getPos();
    //摸牌
    for (int i = 0; i < numPlayers; ++i) {
        for (int j = 0; j < 4; ++j) {
            addCardForOne(i, pos);
            setExist(pos, false);
            --pos;
        }
    }
    setPos(pos);
}

//游戏开始
void Manager::run() {
    isQuit = false;
    while (!isQuit) {
        for (int i = 0; i < numPlayers && !isQuit; ++i) {
            if (players[i]->health == 0)
                continue;
            
            //准备
            if (getNumMagic(i, 0) > 0) {
                int size = getNumMagic(i, 0);
                for (int j = 0; j < size; ++j) {
                    string magic = getMagic(i, 0)[j];
                    (*(magics[magic]))();
                }
            }
            
            //判定
            if (getNumMagic(i, 1) > 0) {
                int size = getNumMagic(i, 1);
                for (int j = 0; j < size; ++j) {
                    string magic = getMagic(i, 1)[j];
                    (*(magics[magic]))();
                }
            }
            
            //摸牌
            if (getNumMagic(i, 2) > 0) {
                int size = getNumMagic(i, 2);
                for (int j = 0; j < size; ++j) {
                    string magic = getMagic(i, 2)[j];
                    (*(magics[magic]))();
                }
            }
            touchCards(i);
            
            //出牌
            if (getNumMagic(i, 3) > 0) {
                int size = getNumMagic(i, 3);
                for (int j = 0; j < size; ++j) {
                    string magic = getMagic(i, 3)[j];
                    (*(magics[magic]))();
                }
            }
            useCards(i);
            if (isQuit)
                break;
            
            //弃牌
            if (getNumMagic(i, 4) > 0) {
                int size = getNumMagic(i, 4);
                for (int j = 0; j < size; ++j) {
                    string magic = getMagic(i, 4)[j];
                    (*(magics[magic]))();
                }
            }
            
            //结束
            if (getNumMagic(i, 5) > 0) {
                int size = getNumMagic(i, 5);
                for (int j = 0; j < size; ++j) {
                    string magic = getMagic(i, 5)[j];
                    (*(magics[magic]))();
                }
            }
        }
    }
}

//返回所有牌的数量
int Manager::getNumCards() {
    return (int)getCards()->cards.size();
}

void Manager::setPos(int pos) {
    getCards()->nowCards = pos;
}

int Manager::getPos() {
    return getCards()->nowCards;
}

//洗牌
void Manager::shuffleCards() {
    random_shuffle(getCards()->cards.begin(), getCards()->cards.end());
    int pos = getNumCards() - 1;
    setPos(pos);
}

void Manager::setExist(int pos, bool b) {
    getCards()->exist[getCards()->cards[pos]->getId()] = b;
}

bool Manager::getExist(int pos) {
    return getCards()->exist[getCards()->cards[pos]->getId()];
}


//某玩家增加一张牌
void Manager::addCardForOne(int player, int pos) {
    getPlayers()[player]->cards.push_back(getCards()->cards[pos]);
}

//某玩家删除一张牌
void Manager::delCardForOne(int player, int pos) {
    int size = (int)getPlayers()[player]->cards.size();
    for (int i = pos; i < size - 1; ++i)
        getPlayers()[player]->cards[pos] = getPlayers()[player]->cards[pos + 1];
    getPlayers()[player]->cards.erase(manager->getPlayers()[player]->cards.end() - 1);
}

//返回某玩家的一张牌
GameCard* Manager::getCardForOne(int player, int pos) {
    return getPlayers()[player]->cards[pos];
}

//返回某玩家的手牌数量
int Manager::getNumCardsForOne(int player) {
    return (int)getPlayers()[player]->cards.size();
}

void Manager::setExistForOne(int player, int pos, bool b) {
    getCards()->exist[getPlayers()[player]->cards[pos]->getId()] = b;
}

//返回某玩家的英雄技能数量
int Manager::getNumMagic(int player, int type) {
    return players[player]->getHero()->getNumMagic()[type];
}

//返回某玩家的英雄技能信息
vector<string> Manager::getMagic(int player, int type) {
    return players[player]->getHero()->getMagics()[type];
}

//统计主公位置和身份信息
void Manager::countInfo() {
    for (int i = 0; i < numPlayers; ++i) {
        if (players[i]->getActor()->getContent() == A_ZHUGONG) {
            isZhugong = i;
            ++numActors[0];
        } else if (players[i]->getActor()->getContent() == A_ZHONGCHEN)
            ++numActors[1];
        else if (players[i]->getActor()->getContent() == A_FANZEI)
            ++numActors[2];
        else if (players[i]->getActor()->getContent() == A_NEIJIAN)
            ++numActors[3];
    }
}

//打印所有玩家的可见情况
void Manager::printInfo() {
    for (int i = 0; i < numPlayers; ++i) {
        cout << "玩家" << i << ": " << players[i]->getHero()->getContent() << " 有" << getNumCardsForOne(i) << "张牌";
        if (i == isZhugong)
            cout << " (主公)" << endl;
        else
            cout << endl;
        cout << "生命: ";
        if (players[i]->health == 0)
            cout << "死亡" << " " << players[i]->getActor()->getContent() << endl;
        else
            cout << players[i]->health << endl;
        cout << "武器: ";
        if (players[i]->getHasEquipment()[0])
            cout << players[i]->getEquipment()[0] << endl;
        else
            cout << "无" << endl;
        cout << "马匹: ";
        if (players[i]->getHasEquipment()[1])
            cout << players[i]->getEquipment()[1] << endl;
        else
            cout << "无" << endl;
        cout << "防具: ";
        if (players[i]->getHasEquipment()[2])
            cout << players[i]->getEquipment()[2] << endl;
        else
            cout << "无" << endl;
            
    }
}

//打印某玩家的手牌
void Manager::printCards(int player) {
    int size = getNumCardsForOne(player);
    cout << "你(" << players[player]->getHero()->getContent() << ")现在有牌：" << endl;
    for (int i = 0; i < size; ++i) {
        cout << i << ": " << getCardForOne(player, i)->getContent() << " ";
        if (getCardForOne(player, i)->getColor() == 0)
            cout << "黑桃" << " ";
        else if (getCardForOne(player, i)->getColor() == 1)
            cout << "红桃" << " ";
        else if (getCardForOne(player, i)->getColor() == 2)
            cout << "梅花" << " ";
        else if (getCardForOne(player, i)->getColor() == 3)
            cout << "方块" << " ";
        if (getCardForOne(player, i)->getNum() <= 10)
            cout << getCardForOne(player, i)->getNum() << " ";
        else if (getCardForOne(player, i)->getNum() == 11)
            cout << "J" << " ";
        else if (getCardForOne(player, i)->getNum() == 12)
            cout << "Q" << " ";
        else if (getCardForOne(player, i)->getNum() == 13)
            cout << "K" << " ";
        else if (getCardForOne(player, i)->getNum() == 14)
            cout << "A" << " ";
        cout << endl;
    }
}

//某玩家摸一张牌
void Manager::touchCards(int player) {
    int pos = getPos();
    while (!getExist(pos)) {
        --pos;
        if (pos == -1)
            shuffleCards();
        pos = getPos();
    }
    addCardForOne(player, pos);
    --pos;
    if (pos == -1)
        shuffleCards();
    pos = getPos();
}

//某玩家出一张牌
void Manager::useCards(int player) {
    printInfo();
    int countSha = 1;
    while (1) {
        printCards(player);
        cout << "请输入id出牌，输入-1放弃出牌" << endl;
        int pos = -1;
        cin >> pos;
        if (pos == -1)
            break;
        if (getCardForOne(player, pos)->getContent() == C_SHA) {
            if (countSha == 0) {
                cout << "每回合只能出一次杀" << endl;
                continue;
            }
            if (useSha(player)) {
                setExistForOne(player, pos, false);
                delCardForOne(player, pos);
                --countSha;
            }
        } else if (getCardForOne(player, pos)->getContent() == C_TAO) {
            if (useTao(player)) {
                setExistForOne(player, pos, false);
                delCardForOne(player, pos);
            }
        } else {
            cout << "现在暂不支持出这张票" << endl;
        }
    }
}

//某玩家被杀或被桃
void Manager::recv(int player, int from, int type) {
    //type == 0, 被杀; type == 1, 被桃; type == 2...n, 其他;
    if (getNumMagic(player, 6) > 0) {
        int size = getNumMagic(player, 6);
        for (int j = 0; j < size; ++j) {
            string magic = getMagic(player, 6)[j];
            (*(magics[magic]))();
        }
    }
    if (type == 0) {
        recvSha(player, from);
    } else if (type == 1) {
        recvTao(player, from);
    }
}

//某玩家死亡
void Manager::dead(int player) {
    cout << "玩家" << player << ": " << players[player]->getHero()->getContent() << " 死亡" << endl;
    cout << "身份: " << players[player]->getActor()->getContent() << endl;
    if (players[player]->getActor()->getContent() == A_ZHUGONG) {
        if (numActors[2] > 0 || numActors[1] > 0)
            cout << "游戏结束，反贼胜利！" << endl;
        else
            cout << "游戏结束，内奸胜利！" << endl;
        isQuit = true;
    } else if (players[player]->getActor()->getContent() == A_ZHONGCHEN)
        --numActors[1];
    else if (players[player]->getActor()->getContent() == A_FANZEI)
        --numActors[2];
    else
        --numActors[3];
    if (numActors[2] == 0 && numActors[3] == 0) {
        cout << "游戏结束，主公和忠臣胜利！" << endl;
        isQuit = true;
    }
}

//某玩家需要判定
void Manager::judge(int player, int type) {
    if (getNumMagic(player, 1) > 0) {
        int size = getNumMagic(player, 1);
        for (int j = 0; j < size; ++j) {
            string magic = getMagic(player, 1)[j];
            (*(magics[magic]))();
        }
    }
}

//某玩家出杀
bool Manager::useSha(int player) {
    printInfo();
    cout << "请输入你想对哪位玩家出杀(0 - " << numPlayers - 1 << "), 除了你自己(" << players[player]->getHero()->getContent() << "), 输入-1放弃出杀: ";
    int pos = -1;
    cin >> pos;
    if (pos == -1)
        return false;
    //暂未考虑距离
    recv(pos, player, 0);
    return true;
}

//某玩家出桃
bool Manager::useTao(int player) {
    printInfo();
    cout << "请输入你想对哪位玩家出桃(0 - " << numPlayers - 1 << "), 包括你自己(" << players[player]->getHero()->getContent() << "), 输入-1放弃出桃: ";
    int pos = -1;
    cin >> pos;
    if (pos == -1)
        return false;
    //暂未考虑距离
    recv(pos, player, 1);
    return true;
}

//某玩家被杀
bool Manager::recvSha(int player, int from) {
    if (players[player]->getHasEquipment()[2])
        judge(player, 0);
    else {
        cout << "你(" << players[player]->getHero()->getContent() << ")被玩家" << from << ": " << players[from]->getHero()->getContent() << " 出杀，是否出闪" << endl;
        printCards(player);
        while (1) {
            cout << "请输入id出牌，输入-1放弃出牌" << endl;
            int pos = -1;
            cin >> pos;
            if (pos == -1)
                break;
            if (getCardForOne(player, pos)->getContent() == C_SHAN) {
                setExistForOne(player, pos, false);
                delCardForOne(player, pos);
                return false;
            } else {
                cout << "你出的不是闪" << endl;
            }
        }
    }
    --(players[player]->health);
    if (players[player]->health == 0)
        dead(player);
    return true;
}

//某玩家被桃
bool Manager::recvTao(int player, int from) {
    if (players[player]->health < players[player]->getHero()->getHealth()) {
        ++(players[player]->health);
        return true;
    } else
        return false;
}

