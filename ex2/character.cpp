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

void Character::printCharacter() {
    std::cout << "Charakter: " << name << "   Gesundheit: " << health << "   Gold: " << gold << std::endl;
}

void Character::printCharacterItems() {
    std::cout << "Items: ";
    int i;
    for (i = 0; i < INVENTORYSIZE; i++) {
        if (inventory[i].getIsValid() ) {
            std::cout << inventory[i].getName() << ", ";
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
    if (slot < 0 || slot > 9) {
        Item item;
        item.initItem();
        return item;
    } else if (inventory[slot].getIsValid()) {
        Item retval = inventory[slot];
        inventory[slot].setIsValid(false);
        return retval;
    } else {
        Item item;
        item.initItem();
        return item;
    }
}

void Character::attack(Hero* hero) {
    int damage = random_number_generator(5,16);
    hero->setHealth( hero->getHealth() - damage);
    std::cout << name << " trifft " << hero->getName() << " fuer " << damage << " Lebenspunkte!" << std::endl;
}