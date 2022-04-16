//
// Created by juerg on 20.02.2022.
//
#include <iostream>
#include "character.h"
#include "item.h"

void Character::attack(Character* target) {
    int damage = xrand(15,26);
    std::cout << this->getName() << " trifft " << target->getName() << " fuer " << damage << " Lebenspunkte!" << std::endl;
    (target->getHealth() - damage > 0 ) ? target->setHealth(target->getHealth() - damage) : target->setHealth(0);
}

bool Character::fight(Character* target) {
    while (this->getHealth() > 0 && target->getHealth() > 0) {
        attack(target);
        if (target->getHealth() > 0) {
            target->attack(this);
        }
    }
    if (this->getHealth() > 0) {
        std::cout << this->getName() << " hat gewonnen!" << std::endl;
        Item var_item = target->retrieveRandomLoot();
        if (var_item.getIsValid()) {
            std::cout << getName() << " erbeutet " << var_item.getName() << "!" << std::endl;
            addInventarItem(var_item);
        }
    } else {
        std::cout << target->getName() << " hat gewonnen!" << std::endl;
    }
    return this->getHealth() > 0;
}

int Character::addInventarItem(const Item &item) {
    for (int i = 0; i < INVENTORYSIZE; i++) {
        if (!inventory[i].getIsValid() ) {
            inventory[i] = item;
            return i;
        }
    }
    std::cout << "Kein Platz mehr fuer dieses Item vorhanden!" << std::endl;
    return -1;
}

Item Character::removeInventarItem(int slot) {
    Item var_item;
    if (slot >= 0 && slot < INVENTORYSIZE && inventory[slot].getIsValid() ) {
        var_item = getInventar(slot);
        inventory[slot].setIsValid(false);
    }
    return var_item;
}

Item Character::retrieveRandomLoot() {
    int slot;
    slot = xrand(0,INVENTORYSIZE-1);
    return removeInventarItem(slot);

}

void Character::sellItem(int slot) {
    if (slot >= 0 && slot < INVENTORYSIZE) {
        if (inventory[slot].getIsValid()) {
            std::cout << "Gegenstand " << inventory[slot].getName() << " wird um " << inventory[slot].getGold() << " verkauft. ";
            gold += inventory[slot].getGold();
            inventory[slot].setIsValid(false);
            std::cout << getName() << " besitzt nun " << getGold() << " Gold." << std::endl;
        }
    }
}

std::ostream &operator<<(std::ostream &output, const Character &character) {
    int i, starter=0;
    std::cout << character.getName() << " || health:" << character.getHealth() << " || gold:" << character.getGold() << " || armor:" << character.getArmor_def() << " || magic resistance:" << character.getMagic_def() << " || items:";
    for (i = 0; i < INVENTORYSIZE; i++) {
        if ( character.getInventar(i).getIsValid() ) {
            starter = 1;
            std::cout << character.getInventar(i);
        }
        if(i < INVENTORYSIZE-1 && starter == 1) {
            if ( character.getInventar(i+1).getIsValid()) std::cout << "|";
        }
    }
    if(starter == 0) {
        std::cout << "<empty>";
    }
    return output;
}