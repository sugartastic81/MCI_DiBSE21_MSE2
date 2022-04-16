//
// Created by juerg on 20.02.2022.
//
#include <iostream>
#include "character.h"
#include "hero.h"
#include "npc.h"
#include "fighter.h"
#include "sorcerer.h"
#include "item.h"

using namespace std;

int main() {
    int i, j;
    srand( (unsigned) time(nullptr));

    // START PART: values vor random definition
    string goodguys[3] = {"Annina", "Lukas", "Victor"};
    int sum_goodguys = sizeof(goodguys)/sizeof(goodguys[0]);
    string badguys[9] = {"Pascal", "Matthias", "Peter", "Gundula", "Stephan", "Gerhard", "Catherine", "Alexander", "MONZTER"};
    int sum_badguys = sizeof(badguys)/sizeof(badguys[0]);
    string possibleitems[STARTINGINVENTORY][DIFFERENTINVENTORIES] = {"Schwert", "Dolch", "Bogen", "Armbrust","Speer","Laserschwert",
                                                                     "Lederruestung", "Blechruestung", "Schwere Stahlruestung", "Tarnanzug",
                                                                     "Leichte Stahlruestung","Borat Swimsuit", "Holzschild", "Verstaerkter Holzschild",
                                                                     "Blechschild", "Verstaerkter Blechschild","Stahlschild","Kraftfeld",
                                                                     "Opal", "Rubin", "Diamant", "Bergkristall","Amethyst","Swarovski Kristall"};
    // END PART: values vor random definition

    std::cout << "\nDAS SPIEL STARTET UND DIE SPIELFIGUREN WERDEN INITIALISIERT \n" << std::endl;

    // START PART: initializing the characters
    // Initialisiert die Held:in mit Zufallsnamen, 300 Lebenspunkten und 1 Goldtaler
    Hero thehero(goodguys[xrand(0,sum_goodguys-1)], 300, 1, xrand(1,8), xrand(1,8));
    thehero.addInventarItem(Item("Steinschleuder", 600));
    thehero.addInventarItem(Item("Murmeln", 60));
    thehero.addInventarItem(Item("Lupe", 60));

    // Initialisiert n Kämpfer mit Zufallswerten
    Fighter fighter[NUMBER_OF_FIGHTER];
    for(i=0; i < NUMBER_OF_FIGHTER; i++){
        fighter[i].setName(badguys[xrand(0,sum_badguys-1)]);
        fighter[i].setHealth(xrand(50,100));
        fighter[i].setGold(xrand(80,200));
        fighter[i].setArmor_def(xrand(0,5));
        fighter[i].setMagic_def(xrand(0,5));
        fighter[i].set_muscle_strength(xrand(0,10));
        for(j=0; j < STARTINGINVENTORY; j++) {
            fighter[i].addInventarItem(Item(possibleitems[j][xrand(0,DIFFERENTINVENTORIES-1)], xrand(10,60)));
        }
    }
    // Initialisiert n Zauberer mit Zufallswerten
    Sorcerer magicians[NUMBER_OF_SOURCERER];
    for(i=0; i < NUMBER_OF_SOURCERER; i++){
        magicians[i].setName(badguys[xrand(0,sum_badguys-1)]);
        magicians[i].setHealth(xrand(50,100));
        magicians[i].setGold(xrand(80,200));
        magicians[i].setArmor_def(xrand(0,5));
        magicians[i].setMagic_def(xrand(0,5));
        magicians[i].set_magic_power(xrand(0,10));
        for(j=0; j < STARTINGINVENTORY; j++) {
            magicians[i].addInventarItem(Item(possibleitems[j][xrand(0,DIFFERENTINVENTORIES-1)], xrand(10,60)));
        }
    }

    // Overview of the initialized characters
//    std::cout << "CHARAKTERE UEBERSICHT." << std::endl;
//    std::cout << "Held:in " << thehero << " || equipment: ";  thehero.print_equipment_list();  std::cout << std::endl;
//    for(i=0; i < NUMBER_OF_FIGHTER; i++){
//        std::cout << "Kaempfer:in " << fighter[i] << " || strength: " << fighter[i].get_muscle_strength() << std::endl;
//    }
//    for(i=0; i < NUMBER_OF_SOURCERER; i++){
//        std::cout << "Zauberer:in " << magicians[i] << " || magic power: " << magicians[i].get_magic_power() << std::endl;
//    }
    // END PART: initializing the characters


    // START PART: fighting between characters
    std::cout << "\nDIE KAEMPFE BEGINNEN.";
    // hero fights against enemies
    i=0;
    while(thehero.getHealth() > 0 && i < NUMBER_OF_FIGHTER ) {
        std::cout << "\n" << thehero.getName() << " kaempft gegen Kaempfer:in " << fighter[i].getName() << "\n";
        thehero.fight(&fighter[i]);
        i++;
    }
    i=0;
    while(thehero.getHealth() > 0 && i < NUMBER_OF_SOURCERER ) {
        std::cout << "\n" << thehero.getName() << " kaempft gegen Zauberer:in " << magicians[i].getName() << "\n";
        thehero.fight(&magicians[i]);
        i++;
    }

//    std::cout << "\nCHARAKTERE UEBERSICHT." << std::endl;
//    std::cout << "Held:in " << thehero << std::endl;
//    for(i=0; i < NUMBER_OF_FIGHTER; i++){
//        std::cout << "Kaempfer:in " << fighter[i] << " || strength: " << fighter[i].get_muscle_strength() << std::endl;
//    }
//    for(i=0; i < NUMBER_OF_SOURCERER; i++){
//        std::cout << "Zauberer:in " << magicians[i] << " || magic power: " << magicians[i].get_magic_power() << std::endl;
//    }

    if (thehero.getHealth() > 0) {
        std::cout << "\nHeld:in " << thehero.getName() << " hat erfolgreich alle Feind:innen besiegt." << std::endl;
    }else{
        std::cout << "\nHeld:in " << thehero.getName() << " wurde von den Feinden besiegt." << std::endl;
    }
    std::cout << "\nDIE KAEMPFE SIND BEENDET. \n" << std::endl;
    // END PART: fighting between characters

    if (thehero.getHealth() > 0) {
        for (i = 0; i < INVENTORYSIZE; i++) {
            thehero.sellItem(i);
        }
    }

    // START PART: destroy the characters
//    std::cout << "\nCHARAKTERE UEBERSICHT." << std::endl;
//    std::cout << "Held:in " << thehero << std::endl;
//    for(i=0; i < NUMBER_OF_FIGHTER; i++){
//        for(j=0; j < INVENTORYSIZE; j++) {
//            fighter[i].removeInventarItem(j);
//        }
//        std::cout << "Kaempfer:in " << fighter[i] << " || strength: " << fighter[i].get_muscle_strength() << std::endl;
//    }
//    for(i=0; i < NUMBER_OF_SOURCERER; i++){
//        for(j=0; j < INVENTORYSIZE; j++) {
//            magicians[i].removeInventarItem(j);
//        }
//        std::cout << "Zauberer:in " << magicians[i] << " || magic power: " << magicians[i].get_magic_power() << std::endl;
//    }
    std::cout << std::endl;
    std::cout << "CHARAKTERE VERSTREUEN SICH.\n" << std::endl;
    // END PART: destroy the characters


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

    return 0;
}