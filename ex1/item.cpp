//
// Created by juerg on 20.02.2022.
//
#include <iostream>
#include <cstdlib>
#include "character.h"
#include "hero.h"
#include "item.h"

void initItem(Item_t* item) {
    item->isValid = false;
}

void initItem(Item_t* item, char* name, int gold) {
    item->name = name;
    item->gold = gold;
    item->isValid = true;
}

void sellItem(Hero_t* hero, int index) {
    if (index >= 0 && index < INVENTORYSIZE) {
        if (hero->inventory[index].isValid) {
            hero->gold += hero->inventory[index].gold;
            hero->inventory[index].isValid = false;
            std::cout << "Gegenstand " << hero->inventory[index].name << " wurde verkauft. ";
            std::cout << hero->name << " besitzt nun " << hero->gold << " Gold." << std::endl;
        }
    }
}




