//
// Created by juerg on 20.02.2022.
//

#ifndef PROTOTYP_HERO_H
#define PROTOTYP_HERO_H

#include <string>
#include "item.h"

class Character;

class Hero {
private:
    std::string name;
    int health;
    int gold;
    Item inventory[INVENTORYSIZE];
    Item gear[GEARSIZE];
public:
    void initHero(const std::string &name, int health, int gold);

    void printHeroStats();

    void attack(Character* enemy);

    bool fight(Character* enemy);


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
    int addInventarItem(const Item& item);
    Item removeInventarItem(int slot);

    // private variable gear getter & setter
    Item getEquipment(int slot) const {
        if (slot < 0 || slot > 1) {
            Item item;
            item.initItem();
            return item;
        }
        return gear[slot];
    }
    int addEquipmentItem(const Item& item);
    Item removeEquipmentItem(int slot);



    void sellItem(int index);
};

#endif //PROTOTYP_HERO_H
