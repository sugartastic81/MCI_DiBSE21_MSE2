//
// Created by juerg on 20.02.2022.
//
#include <iostream>
#include "character.h"
#include "item.h"

void Character::initCharacter(const std::string &var_name, int var_health, int var_gold) {
    this->name = var_name;
    this->health = var_health;
    this->gold = var_gold;
    int i;
    for (i = 0; i < INVENTORYSIZE; i++) {
        inventory[i].initItem();
    }
}

void Character::printCharacterStats() {
    int i;
    std::cout << "baddie:" << name << " || health:" << health << " || gold:" << gold << " || items:";
    for (i = 0; i < INVENTORYSIZE; i++) {
        if (inventory[i].getIsValid() ) {
            std::cout << inventory[i].getName();
        }
        if(i < INVENTORYSIZE-1) {
            if (inventory[i+1].getIsValid()) std::cout << "|";
        }
    }
    std::cout << std::endl;
}

int Character::addInventarItem(const Item &item) {
    for (int i = 0; i < INVENTORYSIZE; i++) {
        if (!inventory[i].getIsValid() ) {
            inventory[i] = item;
            return i;
        }
    }
    return -1;
}

Item Character::removeInventarItem(int slot) {
    Item item;
    if (inventory[slot].getIsValid() && slot >= 0 && slot < INVENTORYSIZE ) {
        item = inventory[slot];
        inventory[slot].setIsValid(false);
    } else {
        item.initItem();
    }
    return item;
}

void Character::attack(Hero* hero) {
    int damage = random_number_generator(5,16);
    hero->setHealth( hero->getHealth() - damage);
    std::cout << name << " trifft " << hero->getName() << " fuer " << damage << " Lebenspunkte!" << std::endl;
}