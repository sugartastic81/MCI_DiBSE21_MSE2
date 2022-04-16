//
// Created by juerg on 26.03.2022.
//

#ifndef PROTOTYP_NPC_H
#define PROTOTYP_NPC_H

#include <string>
#include <iostream>
#include "item.h"
#include "character.h"

using namespace std;

class NPC : public Character {
public:
    using Character::Character;

    // Destructor
    ~NPC() override {
        cout << "Feind:in " << name << " geht zurueck ans MCI." << std::endl;
    };
};

#endif //PROTOTYP_NPC_H
