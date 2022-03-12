//
// Created by juerg on 20.02.2022.
//
#include <iostream>
#include <random>
#include "character.h"
#include "hero.h"
#include "item.h"

using namespace std;

struct BADDIE {
    Character baddieCharacter;
    Item baddieItems[4];
};

int random_number_generator(int valstart, int valend) {
    int randomnumber;
    std::mt19937 charMT(clock() + 42);
    std::uniform_int_distribution<int> randMT(valstart,valend );
    randomnumber = randMT(charMT);
    return randomnumber;
}

int main() {
    // Initialisiert die Schurken und die möglichen Items
    string badguys[4] = {"Pascal", "Matthias", "Peter", "Gundula"};
    int sum_badguys = sizeof(badguys)/sizeof(badguys[0]);
    string possibleitems[STARTINGINVENTORY][DIFFERENTINVENTORIES] = {"Schwert", "Dolch", "Bogen", "Armbrust","Speer","Laserschwert",
                       "Lederruestung", "Blechruestung", "Schwere Stahlruestung", "Tarnanzug",
                       "Leichte Stahlruestung","Borat Swimsuit", "Holzschild", "Verstaerkter Holzschild",
                       "Blechschild", "Verstaerkter Blechschild","Stahlschild","Kraftfeld",
                       "Opal", "Rubin", "Diamant", "Bergkristall","Amethyst","Swarovski Kristall"};

    std::cout << "\nDAS SPIEL STARTET UND DIE SPIELFIGUREN WERDEN INITIALISIERT \n" << std::endl;

    // Initialisiert die Held:in mit 300 Lebenspunkten, aber arm
    Hero thehero;
    thehero.initHero("Annina", 300, 1);
    thehero.printHero();
    thehero.printHeroItems();

    // Initialisiert die Schurken
    int i, j, itemset;
    struct BADDIE baddies[sum_badguys];
    for(i=0; i < sum_badguys; i++){
        baddies[i].baddieCharacter.initCharacter(badguys[i], random_number_generator(50,150), random_number_generator(80,200) );
        baddies[i].baddieCharacter.printCharacter();
        itemset = random_number_generator(0,DIFFERENTINVENTORIES-1); // Zufallszahl für das Ausrüstungsset
        for(j=0; j < STARTINGINVENTORY; j++) {
            baddies[i].baddieItems[j].initItem(possibleitems[j][itemset], random_number_generator(10,60) );
            baddies[i].baddieCharacter.addInventarItem(baddies[i].baddieItems[j]);
        }
        baddies[i].baddieCharacter.printCharacterItems();
    }

    i=0;
    while(thehero.getHealth() > 0 && i < sum_badguys ) {
        std::cout << "\n" << thehero.getName() << " kaempft gegen den Schurken " << baddies[i].baddieCharacter.getName() << "\n";
        thehero.fight(&baddies[i].baddieCharacter);
        i++;
    }

    if (thehero.getHealth() > 0) {
        std::cout << "\nHeld " << thehero.getName() << " hat erfolgreich alle Schurken besiegt.\n" << std::endl;

        for (i = 0; i < 10; i++) {
            thehero.sellItem(i);
        }
    }else{
        std::cout << "\nHeld " << thehero.getName() << "  wurde von den Schurken besiegt.\n" << std::endl;
    }

    return 0;
}