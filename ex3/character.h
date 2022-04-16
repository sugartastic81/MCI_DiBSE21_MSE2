//
// Created by juerg on 20.02.2022.
//
#ifndef PROTOTYP_CHARACTER_H
#define PROTOTYP_CHARACTER_H

#define NUMBER_OF_FIGHTER 2
#define NUMBER_OF_SOURCERER 2

#include <string>
#include <iostream>
#include "item.h"

class Hero;
class NPC;

class Character {
protected:
    std::string name;
    int health;
    int gold;
    int armor_def;
    int magic_def;
    Item inventory[INVENTORYSIZE];
public:
    // Constructoren
    Character() : health(0),gold(0), armor_def(0), magic_def(0) {
        //std:cout << "initialized -> name: " << name << " health: " << health << " gold: " << gold << std::endl;
    }
    Character(const std::string &name, int health, int gold, int armor_def, int magic_def) : name(name),health(health),gold(gold), armor_def(armor_def), magic_def(magic_def) {
        //std:cout << "initialized -> name: " << name << " health: " << health << " gold: " << gold << std::endl;
    };
    // Desctructor
    virtual ~Character() = default;;

    virtual void attack(Character* target) = 0;

    bool fight(Character* target);

    void sellItem(int slot);

    // protected  variable name getter & setter
    const std::string & getName() const {
        return name;
    }
    void setName(const std::string &var_name) {
        this->name = var_name;
    }

    // protected variable health getter & setter
    int getHealth() const {
        return health;
    }
    void setHealth(int var_health) {
        this->health = var_health;
    }

    // protected variable gold getter & setter
    int getArmor_def() const {
        return armor_def;
    }
    void setArmor_def(int var_armor_def) {
        this->armor_def = var_armor_def;
    }

    // protected variable gold getter & setter
    int getMagic_def() const {
        return magic_def;
    }
    void setMagic_def(int var_magic_def) {
        this->magic_def = var_magic_def;
    }

    // protected variable gold getter & setter
    int getGold() const {
        return gold;
    }
    void setGold(int var_gold) {
        this->gold = var_gold;
    }

    // protected variable inventory getter & setter
    int addInventarItem(const Item &item);

    Item removeInventarItem(int slot);
    Item retrieveRandomLoot();

    Item getInventar(int slot) const {
        if (slot < 0 || slot >= INVENTORYSIZE) {
            Item item;
            return item;
        }else{
            return inventory[slot];
        }
    }
};

std::ostream &operator<<(std::ostream &output, const Character &character);

std::ostream &operator<<(std::ostream &output, std::string & getName() );



#endif //PROTOTYP_CHARACTER_H
