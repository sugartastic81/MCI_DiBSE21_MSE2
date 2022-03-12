//
// Created by juerg on 20.02.2022.
//
#include <iostream>
#include "character.h"
#include "hero.h"
#include "item.h"

void Hero::initHero(const std::string &var_name, int var_health, int var_gold) {
    this->setName(var_name);
    this->setHealth(var_health);
    this->setGold(var_gold);
    int i;
    for (i=0; i < INVENTORYSIZE; i++) {
        inventory[i].initItem();
    }
    for (i=0; i < GEARSIZE; i++) {
        gear[i].initItem();
    }
}

void Hero::printHeroStats() {
    int i;
    std::cout << "hero:" << this->getName() << " || health:" << this->getHealth() << " || gold:" << this->getGold() << " || items:";
    for (i = 0; i < INVENTORYSIZE; i++) {
        if (inventory[i].getIsValid() ) {
            std::cout << inventory[i].getName();
        }
        if(i < INVENTORYSIZE-1) {
            if (inventory[i+1].getIsValid()) std::cout << "|";
        }
    }
    std::cout << " || gear:";
    for (i = 0; i < GEARSIZE; i++) {
        if (gear[i].getIsValid() ) {
            std::cout << gear[i].getName();
        }
        if(i < GEARSIZE-1) {
            if (gear[i+1].getIsValid()) std::cout << "|";
        }
    }
    std::cout << std::endl;
}

int Hero::addInventarItem(const Item &item) {
    for (int i = 0; i < INVENTORYSIZE; i++) {
        if (!inventory[i].getIsValid()) {
            inventory[i] = item;
            return i;
        }
    }
    return -1;
}

Item Hero::removeInventarItem(int slot) {
    Item var_item;
    if (inventory[slot].getIsValid() && slot >= 0 && slot < INVENTORYSIZE ) {
        var_item = getInventory(slot);
        inventory[slot].setIsValid(false);
    } else {
        var_item.initItem();
    }
    return var_item;
}

void Hero::sellItem(int slot) {
    if (slot >= 0 && slot < INVENTORYSIZE) {
        if (inventory[slot].getIsValid()) {
            gold += inventory[slot].getGold();
            inventory[slot].setIsValid(false);
            std::cout << "Gegenstand " << inventory[slot].getName() << " wurde verkauft. "
                      << name << " besitzt nun " << gold << " Gold." << std::endl;
        }
    }
}

int Hero::addEquipmentItem(const Item &item) {
     for (int i = 0; i < GEARSIZE; i++) {
        if (!gear[i].getIsValid()) {
            gear[i] = item;
            return i;
        }
    }
    return -1;
}

Item Hero::removeEquipmentItem(int slot) {
    Item var_item;
    if (gear[slot].getIsValid() && slot >= 0 && slot < GEARSIZE ) {
        var_item = getEquipment(slot);
        gear[slot].setIsValid(false);
    } else {
        var_item.initItem();
    }
    return var_item;
}

void Hero::attack(Character* enemy) {
    int damage = random_number_generator(15,26);
    std::cout << name << " trifft " << enemy->getName() << " fuer " << damage << " Lebenspunkte!" << std::endl;
    enemy->setHealth(enemy->getHealth() - damage);
}

bool Hero::fight(Character* enemy) {
    while (health > 0 && enemy->getHealth() > 0) {
        attack(enemy);
        if (enemy->getHealth() > 0) {
            enemy->attack(this);
        }
    }
    if (health > 0) {
        std::cout << name << " hat gewonnen!" << std::endl;
        for (int i = 0; i < 10; i++) {
            int shuffeling = random_number_generator(0,INVENTORYSIZE-1);
            Item var_item = enemy->removeInventarItem(shuffeling);
            if (var_item.getIsValid()) {
                if (addInventarItem(var_item) == -1) {
                    std::cout << "Kein Platz mehr fuer dieses Item vorhanden!" << std::endl;
                } else {
                    std::cout << name << " erbeutet " << var_item.getName() << "!" << std::endl;
                }
                break;
            }
        }
    } else {
        std::cout << enemy->getName() << " hat gewonnen!" << std::endl;
    }
    return health > 0;
}

