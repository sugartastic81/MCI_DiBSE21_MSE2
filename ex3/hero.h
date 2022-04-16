//
// Created by juerg on 20.02.2022.
//

#ifndef PROTOTYP_HERO_H
#define PROTOTYP_HERO_H

#include <string>
#include <iostream>
#include "item.h"
#include "character.h"

using namespace std;

class Hero : public Character {
protected:
    Item equipment[GEARSIZE];
public:
    using Character::Character;

    // Destructor
    ~Hero() override {
        cout << "Held:in " << getName() << " reitet dem Sonnenuntergang entgegen." << std::endl;
    };

    // override attac function from character class
    virtual void attack(Character* enemy) override;

    // protected variable inventory getter & setter
    int addEquipmentItem(const Item &item);

    Item removeEquipmentItem(int slot);

    Item getEquipmentItem(int slot) const {
        if (slot < 0 || slot >= GEARSIZE) {
            Item item;
            return item;
        }else{
            return equipment[slot];
        }
    }

    void print_equipment_list();
};


#endif //PROTOTYP_HERO_H
