//
// Created by juerg on 20.02.2022.
//
#include <iostream>
#include <cstdlib>
#include "character.h"
#include "hero.h"
#include "item.h"

void initCharacter(Character_t* character, char* name, int health, int gold) {
    character->name = name;
    character->health = health;
    character->gold = gold;
    for (int i = 0; i < INVENTORYSIZE; i++) {
        initItem(&character->inventory[i]);
    }
}

void attack(Character_t* character, Hero_t* hero) {
    int damage = 5 + std::rand() % 11;
    hero->health -= damage;
    std::cout << character->name << " trifft " << hero->name << " fuer " << damage << " Lebenspunkte!" << std::endl;
}
