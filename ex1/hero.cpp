//
// Created by juerg on 20.02.2022.
//
#include <iostream>
#include <cstdlib>
#include "character.h"
#include "hero.h"
#include "item.h"

void initHero(Hero_t* hero, char* name, int health, int gold) {
    hero->name = name;
    hero->health = health;
    hero->gold = gold;
    for (int i = 0; i < INVENTORYSIZE; i++) {
        initItem(&hero->inventory[i]);
    }
    for (int i = 0; i < GEARSIZE; i++) {
        initItem(&hero->gear[i]);
    }
}

void attack(Hero_t* hero, Character_t* enemy) {
    int damage = 15 + std::rand() % 11;
    std::cout << hero->name << " trifft " << enemy->name << " fuer " << damage << " Lebenspunkte!" << std::endl;
    enemy->health -= damage;
}

void robenemy(Hero_t* hero, Character_t* enemy) {
    int i, j;
    hero->gold += enemy->gold;
    //std::cout << hero->name << " nimmt " << enemy->name << " " << enemy->gold << " Gold!" << std::endl;
    for (i = 0; i < INVENTORYSIZE; i++) {
        if (enemy->inventory[i].isValid) {
            for (j = 0; j < INVENTORYSIZE; j++) {
                if (!(hero->inventory[j].isValid)) {
                    hero->inventory[j] = enemy->inventory[i];
                    std::cout << "Gegenstand " << hero->inventory[j].name << " wurde zum Inventar der Heldin hinzugefuegt." << std::endl;
                    break;
                }
            }
        }
    }
    if(j == 10 )
        std::cout << "Heldin kann kein Inventar mehr aufnehmen." << std::endl;
}

bool fight(Hero_t* annina, Character_t* enemy) {
    while (annina->health > 0 && enemy->health > 0) {
        attack(annina, enemy);
        if (enemy->health > 0) {
            attack(enemy, annina);
        }
    }
    return annina->health > 0;
}

