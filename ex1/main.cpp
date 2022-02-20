//
// Created by juerg on 20.02.2022.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "character.h"
#include "hero.h"
#include "item.h"

int main() {
    std::srand(time(0)+1512);

    // Initialisiert die Held:in mit 300 Lebenspunkten.
    Hero_t annina;
    initHero(&annina, (char*)"Annina", 300, 20);

    // Initialisiert den Gegenspieler mit 50 Lebenspunkten
    Character_t matthias;
    initCharacter(&matthias, (char*)"Matthias", 50, 80);
    initItem(&matthias.inventory[0], (char*)"Zaubertrank", 50);

    // Initialisiert den Gegenspieler mit 100 Lebenspunkten
    Character_t pascal;
    initCharacter(&pascal, (char*)"Pascal", 100, 100);
    initItem(&pascal.inventory[0], (char*)"Schwert", 30);

    // Initialisiert den Gegenspieler mit 150 Lebenspunkten
    Character_t peter;
    initCharacter(&peter, (char*)"Peter", 150, 60);
    initItem(&peter.inventory[0], (char*)"Keule", 15);
    initItem(&peter.inventory[1], (char*)"Ruestung", 20);
    initItem(&peter.inventory[2], (char*)"Bogen", 25);
    initItem(&peter.inventory[4], (char*)"Axt", 15);
    initItem(&peter.inventory[5], (char*)"Schild", 20);
    initItem(&peter.inventory[6], (char*)"Speer", 25);
    initItem(&peter.inventory[7], (char*)"Morgenstern", 25);
    initItem(&peter.inventory[8], (char*)"Borat-Suit", 50000);

    if (fight(&annina, &matthias)) {
        std::cout << matthias.name << " fiel in Ohnmacht! " << annina.name << " hat noch " << annina.health << " Lebenspunkte uebrig!" << std::endl;
        robenemy(&annina, &matthias);
    } else {
        std::cout << annina.name << " fiel in Ohnmacht! Sie ruht sich nun aus." << std::endl;
        return 0;
    }

    if (fight(&annina, &pascal)) {
        std::cout << pascal.name << " fiel in Ohnmacht! " << annina.name << " hat noch " << annina.health << " Lebenspunkte uebrig!" << std::endl;
        robenemy(&annina, &pascal);
    } else {
        std::cout << annina.name << " fiel in Ohnmacht! Sie ruht sich nun aus." << std::endl;
        return 0;
    }

    if (fight(&annina, &peter)) {
        std::cout << peter.name << " fiel in Ohnmacht! " << annina.name << " hat noch " << annina.health << " Lebenspunkte uebrig!" << std::endl;
        robenemy(&annina, &peter);
    } else {
        std::cout << annina.name << " fiel in Ohnmacht! Sie ruht sich nun aus." << std::endl;
        return 0;
    }

    for( int i = 0; i < INVENTORYSIZE; i++ )
        sellItem(&annina, i);
    return 0;
}






