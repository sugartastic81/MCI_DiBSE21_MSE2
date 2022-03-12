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

void Hero::printHero() {
    std::cout << "Heldin: " << name << "   Gesundheit: " << health << "   Gold: " << gold << std::endl;
}

void Hero::printHeroItems() {
    std::cout << "Items: ";
    int i;
    for (i = 0; i < INVENTORYSIZE; i++) {
        if (inventory[i].getIsValid() ) {
            std::cout << inventory[i].getName() << ", ";
        }
    }
    std::cout << std::endl;
}

int Hero::addInventarItem(const Item &item) {
    for (int i = 0; i < 10; i++) {
        if (!inventory[i].getIsValid()) {
            inventory[i] = item;
            return i;
        }
    }
    return -1;
}

Item Hero::removeInventarItem(int slot) {
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

void Hero::sellItem(int index) {
    if (index >= 0 && index < 10) {
        if (inventory[index].getIsValid()) {
            gold += inventory[index].getGold();
            inventory[index].setIsValid(false);
            std::cout << "Gegenstand " << inventory[index].getName() << " wurde verkauft. "
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
    if (slot < 0 || slot > 1) {
        Item item;
        item.initItem();
        return item;
    } else if (gear[slot].getIsValid()) {
        Item retval = gear[slot];
        gear[slot].setIsValid(false);
        return retval;
    } else {
        Item item;
        item.initItem();
        return item;
    }
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
            int dice = random_number_generator(0,9);
            Item loot = enemy->removeInventarItem(dice);
            if (loot.getIsValid()) {
                if (addInventarItem(loot) == -1) {
                    std::cout << "Kein Platz mehr vorhanden!" << std::endl;
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

