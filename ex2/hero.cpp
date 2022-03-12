//
// Created by juerg on 20.02.2022.
//
#include <iostream>
#include "character.h"
#include "hero.h"
#include "item.h"

void Hero::initHero(const std::string &var_name, int var_health, int var_gold) {
    this->name = var_name;
    this->health = var_health;
    this->gold = var_gold;
    int i;
    for (i=0; i < INVENTORYSIZE; i++) {
        inventory[i].initItem();
    }
}

void Hero::printHeroStats() {
    int i;
    std::cout << "hero:" << name << " || health:" << health << " || gold:" << gold << " || items:";
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
    Item item;
    if (inventory[slot].getIsValid() && slot >= 0 && slot < INVENTORYSIZE ) {
        item = inventory[slot];
        inventory[slot].setIsValid(false);
    } else {
        item.initItem();
    }
    return item;
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
    if (!gear[0].getIsValid()) {
        gear[0] = item;
        return 0;
    } else if (!gear[1].getIsValid()) {
        gear[1] = item;
        return 1;
    }
    return -1;
}

Item Hero::removeEquipmentItem(int slot) {
    Item item;
    if (gear[slot].getIsValid() && slot >= 0 && slot <= 1 ) {
        item = gear[slot];
        gear[slot].setIsValid(false);
    }else{
        Item item;
        item.initItem();
    }
    return item;
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
            int dice = random_number_generator(0,INVENTORYSIZE-1);
            Item loot = enemy->removeInventarItem(dice);
            if (loot.getIsValid()) {
                if (addInventarItem(loot) == -1) {
                    std::cout << "Kein Platz mehr fuer dieses Item vorhanden!" << std::endl;
                } else {
                    std::cout << name << " erbeutet " << loot.getName() << "!" << std::endl;
                }
                break;
            }
        }
    } else {
        std::cout << enemy->getName() << " hat gewonnen!" << std::endl;
    }
    return health > 0;
}

