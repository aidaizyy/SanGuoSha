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
            if (getHealthForOne(i) == 0)
                continue;
            
            //准备
            if (getNumMagicForOne(i, 0) > 0) {
                int size = getNumMagicForOne(i, 0);
                for (int j = 0; j < size; ++j) {
                    string magic = getMagicForOne(i, 0)[j];
                    (*(magics[magic]))();
                }
            }
            
            //判定
            if (getNumMagicForOne(i, 1) > 0) {
                int size = getNumMagicForOne(i, 1);
                for (int j = 0; j < size; ++j) {
                    string magic = getMagicForOne(i, 1)[j];
                    (*(magics[magic]))();
                }
            }
            
            //摸牌
            if (getNumMagicForOne(i, 2) > 0) {
                int size = getNumMagicForOne(i, 2);
                for (int j = 0; j < size; ++j) {
                    string magic = getMagicForOne(i, 2)[j];
                    (*(magics[magic]))();
                }
            }
            touchCards(i);
            touchCards(i);
            
            //出牌
            if (getNumMagicForOne(i, 3) > 0) {
                int size = getNumMagicForOne(i, 3);
                for (int j = 0; j < size; ++j) {
                    string magic = getMagicForOne(i, 3)[j];
                    (*(magics[magic]))();
                }
            }
            useCards(i);
            if (isQuit)
                break;
            
            //弃牌
            if (getNumMagicForOne(i, 4) > 0) {
                int size = getNumMagicForOne(i, 4);
                for (int j = 0; j < size; ++j) {
                    string magic = getMagicForOne(i, 4)[j];
                    (*(magics[magic]))();
                }
            }
            dropCards(i);
            
            //结束
            if (getNumMagicForOne(i, 5) > 0) {
                int size = getNumMagicForOne(i, 5);
                for (int j = 0; j < size; ++j) {
                    string magic = getMagicForOne(i, 5)[j];
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
    random_shuffle(getCards()->cards.begin(), getCards()->cards.end(), myrandom);
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
        getPlayers()[player]->cards[i] = getPlayers()[player]->cards[i + 1];
    getPlayers()[player]->cards.erase(manager->getPlayers()[player]->cards.end() - 1);
}

//返回某玩家的一张牌
GameCard* Manager::getCardForOne(int player, int pos) {
    return getPlayers()[player]->cards[pos];
}

void Manager::setExistForOne(int player, int pos, bool b) {
    getCards()->exist[getPlayers()[player]->cards[pos]->getId()] = b;
}

//返回某玩家的手牌数量
int Manager::getNumCardsForOne(int player) {
    return (int)getPlayers()[player]->cards.size();
}

//改变某玩家的生命值
void Manager::setHealthForOne(int player, int diff) {
    players[player]->health += diff;
}

//返回某玩家的生命值
int Manager::getHealthForOne(int player) {
    return getPlayers()[player]->health;
}

//返回某玩家的身份信息
string Manager::getActorContentForOne(int player) {
    return getPlayers()[player]->getActor()->getContent();
}

//返回某玩家的英雄信息
string Manager::getHeroContentForOne(int player) {
    return getPlayers()[player]->getHero()->getContent();
}

//返回某玩家的英雄国籍
int Manager::getCountryForOne(int player) {
    return getPlayers()[player]->getHero()->getCountry();
}

//返回某玩家的英雄生命上限
int Manager::getHeroHealthForOne(int player) {
    return getPlayers()[player]->getHero()->getHealth();
}

//返回某玩家的英雄技能数量
int Manager::getNumMagicForOne(int player, int type) {
    return getPlayers()[player]->getHero()->getNumMagic()[type];
}

//返回某玩家的英雄技能信息
vector<string> Manager::getMagicForOne(int player, int type) {
    return getPlayers()[player]->getHero()->getMagics()[type];
}

//返回某玩家的位置
int Manager::getPosForOne(int player) {
    return getPlayers()[player]->getPos();
}

//改变某玩家是否有装备
void Manager::setHasEquipmentForOne(int player, int type, bool b) {
    players[player]->setHasEquipment(type, b);
}

//改变某玩家的装备名称
void Manager::setEquipmentForOne(int player, int type, string s) {
    players[player]->setEquipment(type, s);
}

//返回某玩家是否有装备
bool Manager::getHasEquipmentForOne(int player, int type) {
    return getPlayers()[player]->getHasEquipment(type);
}

//返回某玩家的装备名称
string Manager::getEquipmentForOne(int player, int type) {
    return getPlayers()[player]->getEquipment(type);
}

//统计主公位置和身份信息
void Manager::countInfo() {
    for (int i = 0; i < numPlayers; ++i) {
        if (getActorContentForOne(i) == A_ZHUGONG) {
            isZhugong = i;
            ++numActors[0];
        } else if (getActorContentForOne(i) == A_ZHONGCHEN)
            ++numActors[1];
        else if (getActorContentForOne(i) == A_FANZEI)
            ++numActors[2];
        else if (getActorContentForOne(i) == A_NEIJIAN)
            ++numActors[3];
    }
}

//打印所有玩家的可见情况
void Manager::printInfo() {
    for (int i = 0; i < numPlayers; ++i) {
        cout << "玩家" << i << ": " << getHeroContentForOne(i) << " 有" << getNumCardsForOne(i) << "张牌";
        if (i == isZhugong)
            cout << " (主公)." << endl;
        else
            cout << "." << endl;
        cout << "生命: ";
        if (players[i]->health == 0)
            cout << "死亡" << " " << getActorContentForOne(i) << endl;
        else
            cout << players[i]->health << endl;
        cout << "武器: ";
        if (getHasEquipmentForOne(i, 0))
            cout << getEquipmentForOne(i, 0) << endl;
        else
            cout << "无" << endl;
        cout << "马匹: ";
        if (getHasEquipmentForOne(i, 1))
            cout << getEquipmentForOne(i, 1) << endl;
        else
            cout << "无" << endl;
        cout << "防具: ";
        if (getHasEquipmentForOne(i, 2))
            cout << getEquipmentForOne(i, 2) << endl;
        else
            cout << "无" << endl;
            
    }
}

//打印某玩家的手牌
void Manager::printCards(int player) {
    int size = getNumCardsForOne(player);
    cout << "你(" << getHeroContentForOne(player) << ", " << getActorContentForOne(player) << ")现在有牌：" << endl;
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
    setPos(pos);
}

//某玩家出一张牌
void Manager::useCards(int player) {
    printInfo();
    int countSha = 1;
    while (!isQuit) {
        printCards(player);
        int pos = -1;
        cout << "请输入id出牌，输入-1放弃出牌:" << endl;
        cin >> pos;
        while (pos < -1 || pos >= getNumCardsForOne(player)) {
            cout << "请输入id出牌，输入-1放弃出牌:" << endl;
            cin >> pos;
        }
        if (pos == -1)
            break;
        if (getCardForOne(player, pos)->getContent() == C_SHA) {
            if (countSha == 0 && (!getHasEquipmentForOne(player, 0) || getEquipmentForOne(player, 0) != E_ZHUGELIANNU)) {
                cout << "每回合只能出一次杀." << endl;
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
        } else if (getCardForOne(player, pos)->getContent() == J_WUZHONGSHENGYOU) {
            if (useWuzhongshengyou(player)) {
                setExistForOne(player, pos, false);
                delCardForOne(player, pos);
            }
        } else if (getCardForOne(player, pos)->getContent() == E_ZHUGELIANNU) {
            if (useZhugeliannu(player)) {
                setExistForOne(player, pos, false);
                delCardForOne(player, pos);
            }
        } else
            cout << "现在暂不支持出这张牌." << endl;
    }
}

void Manager::dropCards(int player) {
    if (getNumCardsForOne(player) > getHealthForOne(player)) {
        cout << "你有手牌" << getNumCardsForOne(player) << "张, " << "生命值为" << getHealthForOne(player) << ", 所以需要弃牌" << getNumCardsForOne(player) - getHealthForOne(player) << "张.";
        cout << "请输入需要丢弃的牌的id:" << endl;
        while (getNumCardsForOne(player) > getHealthForOne(player)) {
            printCards(player);
            int pos = 0;
            cin >> pos;
            while (pos < 0 || pos >= getNumCardsForOne(player)) {
                cout << "你输入的id不符合规矩，请重新输入:" << endl;
                cin >> pos;
            }
            setExistForOne(player, pos, false);
            delCardForOne(player, pos);
        }
    }
}

//某玩家被杀或被桃
void Manager::recv(int player, int from, int type) {
    //type == 0, 被杀; type == 1, 被桃; type == 2...n, 其他;
    if (getNumMagicForOne(player, 6) > 0) {
        int size = getNumMagicForOne(player, 6);
        for (int j = 0; j < size; ++j) {
            string magic = getMagicForOne(player, 6)[j];
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
void Manager::dead(int player, int from) {
    cout << "玩家" << player << ": " << getHeroContentForOne(player) << " 濒临死亡." << endl;
    int i = player;
    while (1) {
        if (getHealthForOne(i) > 0) {
            bool hasCard = false;
            for (int j = 0; j < getNumCardsForOne(i); ++j) {
                if (getCardForOne(i, j)->getContent() == C_TAO)
                    hasCard = true;
            }
            if (hasCard) {
                cout << "玩家" << i << ": " << getHeroContentForOne(i) << " 愿意救玩家" << ": " << getHeroContentForOne(player) << "吗？" << endl;
                printCards(i);
                cout << "请输入id出桃，输入-1放弃出桃:" << endl;
                int pos = -1;
                cin >> pos;
                while ((pos < -1 || pos >= getNumCardsForOne(i)) || (pos != -1 && getCardForOne(i, pos)->getContent() != C_TAO)) {
                    cout << "你输入的id不符合规矩，请重新输入:" << endl;
                    cin >> pos;
                }
                if (pos != -1) {
                    setExistForOne(i, pos, false);
                    delCardForOne(i, pos);
                    setHealthForOne(player, 1);
                    return ;
                }
            }
        }
        if (i == numPlayers - 1)
            i = -1;
        if (i == player - 1)
            break;
        ++i;
    }
    cout << "玩家" << player << ": " << getHeroContentForOne(player) << " 死亡." << endl;
    cout << "身份: " << getActorContentForOne(player) << endl;
    if (getActorContentForOne(player) == A_ZHUGONG) {
        if (numActors[2] > 0 || numActors[1] > 0)
            cout << "游戏结束，反贼胜利！" << endl;
        else
            cout << "游戏结束，内奸胜利！" << endl;
        isQuit = true;
    } else if (getActorContentForOne(player) == A_ZHONGCHEN) {
        --numActors[1];
    } else if (getActorContentForOne(player) == A_FANZEI) {
        --numActors[2];
        //杀死一个反贼摸三张牌
        touchCards(from);
        touchCards(from);
        touchCards(from);
    } else {
        --numActors[3];
    }
    if (numActors[2] == 0 && numActors[3] == 0) {
        cout << "游戏结束，主公和忠臣胜利！" << endl;
        isQuit = true;
    }
}

//某玩家需要判定
bool Manager::judge(int player, int type) {
    if (getNumMagicForOne(player, 1) > 0) {
        int size = getNumMagicForOne(player, 1);
        for (int j = 0; j < size; ++j) {
            string magic = getMagicForOne(player, 1)[j];
            (*(magics[magic]))();
        }
    }
    return false;
}

//某玩家出杀
bool Manager::useSha(int player) {
    printInfo();
    cout << "请输入你想对哪位玩家出杀(0 - " << numPlayers - 1 << "), 除了你自己(" << getHeroContentForOne(player) << "), 输入-1放弃出杀: ";
    int pos = -1;
    cin >> pos;
    while (pos < -1 || pos >= numPlayers) {
        cout << "请输入你想对哪位玩家出杀(0 - " << numPlayers - 1 << "), 除了你自己(" << getHeroContentForOne(player) << "), 输入-1放弃出杀: ";
        cin >> pos;
    }
    if (pos == -1)
        return false;
    //暂未考虑距离
    recv(pos, player, 0);
    return true;
}

//某玩家出桃
bool Manager::useTao(int player) {
    printInfo();
    cout << "请输入你想对哪位玩家出桃(0 - " << numPlayers - 1 << "), 包括你自己(" << getHeroContentForOne(player) << "), 输入-1放弃出桃: ";
    int pos = -1;
    cin >> pos;
    while (pos < -1 || pos >= numPlayers) {
        cout << "请输入你想对哪位玩家出桃(0 - " << numPlayers - 1 << "), 包括你自己(" << getHeroContentForOne(player) << "), 输入-1放弃出桃: ";
        cin >> pos;
    }
    if (pos == -1)
        return false;
    //暂未考虑距离
    recv(pos, player, 1);
    return true;
}

//某玩家被杀
bool Manager::recvSha(int player, int from) {
    if (getHasEquipmentForOne(player, 2))
        judge(player, 0);
    else {
        cout << "你(" << getHeroContentForOne(player) << ")被玩家" << from << ": " << getHeroContentForOne(player) << " 出杀，是否出闪:" << endl;
        printCards(player);
        while (1) {
            cout << "请输入id出牌，输入-1放弃出牌:" << endl;
            int pos = -1;
            cin >> pos;
            while (pos < -1 || pos >= getNumCardsForOne(player)) {
                cout << "请输入id出牌，输入-1放弃出牌:" << endl;
                cin >> pos;
            }
            if (pos == -1)
                break;
            if (getCardForOne(player, pos)->getContent() == C_SHAN) {
                setExistForOne(player, pos, false);
                delCardForOne(player, pos);
                return false;
            } else {
                cout << "你出的不是闪." << endl;
            }
        }
    }
    setHealthForOne(player, -1);
    if (getHealthForOne(player) == 0)
        dead(player, from);
    return true;
}

//某玩家被桃
bool Manager::recvTao(int player, int from) {
    if (getHealthForOne(player) < getHeroHealthForOne(player)) {
        setHealthForOne(player, 1);
        return true;
    } else
        return false;
}

bool Manager::useZhugeliannu(int player) {
    setHasEquipmentForOne(player, 0, true);
    setEquipmentForOne(player, 0, E_ZHUGELIANNU);
    return true;
}

bool Manager::useWuzhongshengyou(int player) {
    for (int i = 0; i < numPlayers; ++i) {
        if (getHealthForOne(player) == 0)
            continue;
        bool hasCard = false;
        for (int j = 0; j < getNumCardsForOne(player); ++j) {
            if (getCardForOne(player, j)->getContent() == J_WUXIEKEJI)
                hasCard = true;
        }
        if (hasCard) {
            //如果有无懈可击牌。。。没继续写
        }
    }
    touchCards(player);
    touchCards(player);
    return true;
}

