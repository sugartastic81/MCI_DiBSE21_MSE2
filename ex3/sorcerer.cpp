//
// Created by juerg on 26.03.2022.
//

#include <iostream>
#include "character.h"
#include "sorcerer.h"
#include "item.h"

void Sorcerer::attack(Character* target) {
    int damage = xrand(5,10) + this->get_magic_power() - target->getMagic_def() ;
    if( damage < 0 ) damage = 0;
    std::cout << "Zauberer:in " << this->getName() << " trifft " << target->getName() << " fuer " << damage << " Lebenspunkte!" << std::endl;
    if( target->getHealth() - damage > 0 ){
        target->setHealth(target->getHealth() - damage);
    }else{
        target->setHealth(0);
    }
}
