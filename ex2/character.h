//
// Created by juerg on 20.02.2022.
//
#ifndef PROTOTYP_CHARACTER_H
#define PROTOTYP_CHARACTER_H

#define NUMBER_OF_BADGUYS 3

#include <string>
#include "item.h"
#include "hero.h"

class Hero;

class Character {
private:
    std::string name;
    int health;
    int gold;
    Item inventory[INVENTORYSIZE];
public:
    void initCharacter(const std::string &name, int health, int gold);
    void printCharacterStats();

    // private variable name getter & setter
    const std::string& getName() const {
        return name;
    }
    void setName(const std::string &var_name) {
        this->name = var_name;
    }


    // private variable health getter & setter
    int getHealth() const {
        return health;
    }
    void setHealth(int var_health) {
        this->health = var_health;
    }


    // private variable gold getter & setter
    int getGold() const {
        return gold;
    }
    void setGold(int var_gold) {
        this->gold = var_gold;
    }


    // private variable inventory getter & setter
    Item getInventory(int slot) const {
        if (slot < 0 || slot > 1) {
            Item item;
            item.initItem();
            return item;
        }
        return inventory[slot];
    }
    int addInventarItem(const Item &item);
    Item removeInventarItem(int slot);

    // attacks the hero
    void attack(Hero* hero);
};

#endif //PROTOTYP_CHARACTER_H
