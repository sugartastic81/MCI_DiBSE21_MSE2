//
// Created by juerg on 20.02.2022.
//
#ifndef PROTOTYP_CHARACTER_H
#define PROTOTYP_CHARACTER_H

#include <string>
#include "item.h"

struct Hero_t;
struct Character_t {
    std::string name;
    int health;
    int gold;
    Item_t inventory[10];
};

void initCharacter(Character_t* character, char* name, int health, int gold);
void attack(Character_t* character, Hero_t* hero);

#endif //PROTOTYP_CHARACTER_H
