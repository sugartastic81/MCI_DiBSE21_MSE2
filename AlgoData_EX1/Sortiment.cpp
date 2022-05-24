// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#include "Ware.h"
#include "Sortiment.h"
#include "Algorithms.h"
#include "exceptions.h"

void Sortiment::sort(int modus) {
    if( modus == 1) { // int modus == 1: Sortierung nach Seriennummer mithilfe des quicksort-Algorithmus
        std::cout << std::endl << "------------" << std::endl;
        std::cout << std::endl << "int modus == " << modus << ": Sortierung nach Seriennummer mithilfe des quicksort-Algorithmus." << std::endl;
        std::cout << std::endl << "VIEW SORTIMENT BEFORE SORT" << std::endl;
        this->view();
        quicksort_array(this);
        std::cout << std::endl << "VIEW SORTIMENT AFTER SORT" << std::endl;
        this->view();
        std::cout << std::endl << "------------" << std::endl;
    } else if( modus == 2) { // int modus == 2: Sortierung nach Gewicht mithilfe des bubblesort-Algorithmus
        std::cout << "int modus == " << modus << ": Sortierung nach Gewicht mithilfe des bubblesort-Algorithmus." << std::endl;
    }else if( modus == 3) { // int modus == 3: Sortierung alphabetisch nach Bezeichnung mihilfe des mergesort-Algorithmus
        std::cout << "int modus == " << modus << ": Sortierung alphabetisch nach Bezeichnung mihilfe des mergesort-Algorithmus." << std::endl;
    }else if( modus == 4) { // int modus == 4: Sortierung nach Einkaufspreis mithilfe des insertionsort-Algorithmus in seiner Basisvariante.
        std::cout << "int modus == " << modus << ": Sortierung nach Einkaufspreis mithilfe des insertionsort-Algorithmus in seiner Basisvariante.." << std::endl;
    }else if( modus == 5) { // int modus == 5: Sortierung nach Verkaufspreis mithilfe des insertionsort-Algorithmus in seiner Basisvariante.
        std::cout << "int modus == " << modus << ": Sortierung nach Verkaufspreis mithilfe des insertionsort-Algorithmus in seiner Basisvariante.." << std::endl;
    }else {
        std::cout << "Sortieralgorythmus unbekannt." << std::endl;
    }
}

void Sortiment::addWare(Ware* ware) {
    int i = 0, success = 0;
    for (i = 0; i < 10; i++) {
        if ( !this->waren[i] ) {
            this->waren[i] = ware;
            std::cout << "Add Bezeichnung " << this->waren[i]->getBezeichnung() << " mit SNR " << this->waren[i]->getSeriennummer() << ", Gewicht " << this->waren[i]->getGewicht() << " kg, EP " << this->waren[i]->getEinkaufspreis() << " EUR, VP " << this->waren[i]->getVerkaufspreis()<< " EUR." << std::endl;
            success = 1;
            break;
        }
    }
    if( success != 1 ) {
        // throw FullSortimentException("Sortiment ist voll. Kein Platz mehr!");
        std::cout << "Sortiment ist voll. Kein Platz mehr!" << std::endl;
    }
}

void Sortiment::view() {
    int i = 0;
    while ( this->waren[i] ) {
        std::cout << this->waren[i] << " <- ADR ___ " << this->waren[i]->getBezeichnung() << ", SNR " << this->waren[i]->getSeriennummer() << ", Gewicht " << this->waren[i]->getGewicht() << " kg, EP " << this->waren[i]->getEinkaufspreis() << " EUR, VP " << this->waren[i]->getVerkaufspreis()<< " EUR." << std::endl;
        i++;
    }
}