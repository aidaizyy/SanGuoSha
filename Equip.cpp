//
//  Equip.cpp
//  SanGuoSha
//
//  Created by 张云尧 on 2017/8/31.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include "Equip.h"

//初始化各装备信息
void initZhugeliannu(unordered_map<string, EquipCard*>& equipcards) {
    EquipCard* card = new EquipCard(3, E_ZHUGELIANNU, -1, -1, -1, 0, -1);
    equipcards[E_ZHUGELIANNU] = card;
}
