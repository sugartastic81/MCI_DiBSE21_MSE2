//
// Created by juerg on 26.03.2022.
//
#ifndef PROTOTYP_FIGHTER_H
#define PROTOTYP_FIGHTER_H

#include <string>
#include <iostream>
#include "item.h"
#include "character.h"
#include "npc.h"

using namespace std;

class Fighter : public NPC {
protected:
    int muscle_strength;
public:
    using NPC::NPC;

    // override attac function from character class
    virtual void attack(Character* enemy) override;

    // private variable health getter & setter
    int get_muscle_strength() const {
        return muscle_strength;
    }
    void set_muscle_strength(int var_muscle_strength) {
        this->muscle_strength = var_muscle_strength;
    }
};


#endif //PROTOTYP_FIGHTER_H
