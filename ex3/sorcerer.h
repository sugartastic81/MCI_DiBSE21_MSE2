//
// Created by juerg on 26.03.2022.
//

#ifndef MY_GAME_SORCERER_H
#define MY_GAME_SORCERER_H

#include <string>
#include <iostream>
#include "item.h"
#include "character.h"
#include "npc.h"

using namespace std;

class Sorcerer : public NPC {
protected:
    int magic_power;
public:
    using NPC::NPC;

    // override attac function from character class
    virtual void attack(Character* enemy) override;

    // private variable health getter & setter
    int get_magic_power() const {
        return magic_power;
    }
    void set_magic_power(int var_magic_power) {
        this->magic_power = var_magic_power;
    }
};

#endif //MY_GAME_SORCERER_H
