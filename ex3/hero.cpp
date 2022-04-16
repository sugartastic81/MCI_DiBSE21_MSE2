//
// Created by juerg on 20.02.2022.
//
#include <iostream>
#include "character.h"
#include "hero.h"
#include "item.h"

int Hero::addEquipmentItem(const Item &item) {
    for (int i = 0; i < GEARSIZE; i++) {
        if (!equipment[i].getIsValid() ) {
            equipment[i] = item;
            return i;
        }
    }
    std::cout << "Kein Platz mehr fuer dieses Item vorhanden!" << std::endl;
    return -1;
}

Item Hero::removeEquipmentItem(int slot) {
    Item var_item;
    if (slot >= 0 && slot < GEARSIZE && equipment[slot].getIsValid() ) {
        var_item = getInventar(slot);
        equipment[slot].setIsValid(false);
    }
    return var_item;
}

void Hero::print_equipment_list() {
    int i, starter=0;
    for (i = 0; i < GEARSIZE; i++) {
        if ( equipment[i].getIsValid() ) {
            starter = 1;
            std::cout << equipment[i].getName() << "(" << equipment[i].getGold() << ")";
        }
        if(i < GEARSIZE-1 && starter == 1) {
            if ( equipment[i+1].getIsValid()) std::cout << "|";
        }
    }
    if(starter == 0) {
        std::cout << "<empty>";
    }
}
void Hero::attack(Character* target) {
    int damage = xrand(15,25) - target->getArmor_def() ;
    if( damage < 0 ) damage = 0;
    std::cout << "Held:in " << this->getName() << " trifft " << target->getName() << " fuer " << damage << " Lebenspunkte!" << std::endl;
    if( target->getHealth() - damage > 0 ){
        target->setHealth(target->getHealth() - damage);
    }else{
        target->setHealth(0);
    }
}