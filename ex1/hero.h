//
// Created by juerg on 20.02.2022.
//
#define INVENTORYSIZE 10
#define GEARSIZE 2

#ifndef PROTOTYP_HERO_H
#define PROTOTYP_HERO_H

#include <string>
#include "item.h"

struct Character_t;
struct Hero_t {
    std::string name;
    int health;
    int gold;
    Item_t inventory[INVENTORYSIZE];
    Item_t gear[GEARSIZE];
};

void initHero(Hero_t* hero, char* name, int health, int gold);
void attack(Hero_t* hero, Character_t* enemy);
void robenemy(Hero_t* hero, Character_t* enemy);
bool fight(Hero_t* hero, Character_t* enemy);
void sellItem(Hero_t* hero, int index);

#endif //PROTOTYP_HERO_H
