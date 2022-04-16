//
// Created by juerg on 26.03.2022.
//

#include <iostream>
#include "character.h"
#include "fighter.h"
#include "item.h"

void Fighter::attack(Character* target) {
    int damage = xrand(5,10) + this->get_muscle_strength() - target->getArmor_def() ;
    if( damage < 0 ) damage = 0;
    std::cout << "Kaempfer:in " << this->getName() << " trifft " << target->getName() << " fuer " << damage << " Lebenspunkte!" << std::endl;
    if( target->getHealth() - damage > 0 ){
        target->setHealth(target->getHealth() - damage);
    }else{
        target->setHealth(0);
    }
}
