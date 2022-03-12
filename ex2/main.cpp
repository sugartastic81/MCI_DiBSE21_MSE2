//
// Created by juerg on 20.02.2022.
//
#include <iostream>
#include "character.h"
#include "hero.h"
#include "item.h"

using namespace std;

struct BADDIE {
    Character baddieCharacter;
    Item baddieItems[STARTINGINVENTORY];
};


int main() {
    int i, j;
    srand( (unsigned) time(nullptr));

    // Initialisiert die Schurken und die möglichen Items
    string goodguys[3] = {"Annina", "Lukas", "Victor"};
    int sum_goodguys = sizeof(goodguys)/sizeof(goodguys[0]);
    string badguys[9] = {"Pascal", "Matthias", "Peter", "Gundula", "Stephan", "Gerhard", "Catherine", "Alexander", "MONZTER"};
    int sum_badguys = sizeof(badguys)/sizeof(badguys[0]);
    string possibleitems[STARTINGINVENTORY][DIFFERENTINVENTORIES] = {"Schwert", "Dolch", "Bogen", "Armbrust","Speer","Laserschwert",
                       "Lederruestung", "Blechruestung", "Schwere Stahlruestung", "Tarnanzug",
                       "Leichte Stahlruestung","Borat Swimsuit", "Holzschild", "Verstaerkter Holzschild",
                       "Blechschild", "Verstaerkter Blechschild","Stahlschild","Kraftfeld",
                       "Opal", "Rubin", "Diamant", "Bergkristall","Amethyst","Swarovski Kristall"};

    std::cout << "\nDAS SPIEL STARTET UND DIE SPIELFIGUREN WERDEN INITIALISIERT \n" << std::endl;

    // Initialisiert die Held:in mit 300 Lebenspunkten und 1 Goldtaler
    Hero thehero;
    thehero.initHero(goodguys[xrand(0,sum_goodguys-1)], 300, 1);
    Item dummyequipment;
    dummyequipment.initItem("Murmeln", xrand(10,60) );
    thehero.addEquipmentItem(dummyequipment);
    dummyequipment.initItem("Steinschleuder", xrand(10,600) );
    thehero.addEquipmentItem(dummyequipment);
    thehero.printHeroStats();

    // Initialisiert die Schurken mit Zufallswerten
    struct BADDIE baddies[NUMBER_OF_BADGUYS];
    for(i=0; i < NUMBER_OF_BADGUYS; i++){
        baddies[i].baddieCharacter.initCharacter(badguys[xrand(0,sum_badguys-1)], xrand(50,150), xrand(80,200) );

        for(j=0; j < STARTINGINVENTORY; j++) {
            baddies[i].baddieItems[j].initItem(possibleitems[j][xrand(0,DIFFERENTINVENTORIES-1)], xrand(10,60) );
            baddies[i].baddieCharacter.addInventarItem(baddies[i].baddieItems[j]);
        }
        baddies[i].baddieCharacter.printCharacterStats();
    }

    // Held kämpft gegen alle Schurken
    i=0;
    while(thehero.getHealth() > 0 && i < NUMBER_OF_BADGUYS ) {
        std::cout << "\n" << thehero.getName() << " kaempft gegen den Schurken " << baddies[i].baddieCharacter.getName() << "\n";
        thehero.fight(&baddies[i].baddieCharacter);
        i++;
    }

    if (thehero.getHealth() > 0) {
        std::cout << "\nHeld " << thehero.getName() << " hat erfolgreich alle Schurken besiegt.\n" << std::endl;

        for (i = 0; i < INVENTORYSIZE; i++) {
            thehero.sellItem(i);
        }
    }else{
        std::cout << "\nHeld " << thehero.getName() << " wurde von den Schurken besiegt.\n" << std::endl;
    }

/*
    // Diverse Spielereien

    for(i=0; i < NUMBER_OF_BADGUYS; i++){
        baddies[i].baddieCharacter.printCharacterStats();
    }

    std::cout << "\nDie Schurken werden leergeraeumt. \n" << std::endl;

    for(i=0; i < NUMBER_OF_BADGUYS; i++){
        for (j = 0; j < 10; j++) {
            baddies[i].baddieCharacter.removeInventarItem(j);
        }
        baddies[i].baddieCharacter.printCharacterStats();
    }

    */

    std::cout << "\nDAS SPIEL IST BEENDET. \n" << std::endl;

    return 0;
}