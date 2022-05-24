// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#include "Ware.h"
#include "Sortiment.h"
#include "Algorithms.h"

#include <iostream>

void quicksort_array(Sortiment* sortiment) {
    //int i = 0;
    std::cout << std::endl << "I HATE POINTERS " << sortiment << std::endl;
/*    while ( sortiment->waren[i]->getSeriennummer() > 0 ) {
        std::cout << sortiment->waren[i] << " <- ADR ___ " << sortiment->waren[i]->getBezeichnung() << ", SNR " << sortiment->waren[i]->getSeriennummer() << ", Gewicht " << this->waren[i]->getGewicht() << " kg, EP " << this->waren[i]->getEinkaufspreis() << " EUR, VP " << this->waren[i]->getVerkaufspreis()<< " EUR." << std::endl;
        i++;
    }*/
}

/*void Algorithms::quicksort() {
    int i = 0;
    while ( this->waren[i] ) {
        std::cout << this->waren[i] << " <- ADR ___ " << this->waren[i]->getBezeichnung() << ", SNR " << this->waren[i]->getSeriennummer() << ", Gewicht " << this->waren[i]->getGewicht() << " kg, EP " << this->waren[i]->getEinkaufspreis() << " EUR, VP " << this->waren[i]->getVerkaufspreis()<< " EUR." << std::endl;
        i++;
    }
}*/
