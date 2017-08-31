//
//  Equip.h
//  SanGuoSha
//
//  Created by 张云尧 on 2017/8/31.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#ifndef Equip_h
#define Equip_h

#include <string>
#include <unordered_map>
using namespace std;

#include "Card.h"
#include "Init.h"
#include "Magic.h"

void initZhugeliannu(unordered_map<string, EquipCard*>& equipcards);

#endif /* Equip_h */
