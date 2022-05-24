// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#include "Ware.h"
#include "Sortiment.h"
#include "Algorithms.h"
#include "exceptions.h"
#include <unistd.h>



void Sortiment::sort(int modus) {
    if( modus == 1) { // int modus == 1: Sortierung nach Seriennummer mithilfe des quicksort-Algorithmus
        std::cout << std::endl << "------------------------------------" << std::endl << "SORTIEREN IM MODUS " << modus << std::endl << "------------------------------------";
        std::cout << std::endl << "vorher" << std::endl;
        this->view();
        std::cout << std::endl << "int modus == " << modus << ": Sortierung nach Seriennummer mithilfe des quicksort-Algorithmus." << std::endl;
        this->quicksort_seriennummer(0,9);
        std::cout << std::endl << "nachher" << std::endl;
        this->view();
        std::cout << std::endl << "------------------------------------" << std::endl << "* * * * * ENDE " << modus << std::endl << "------------------------------------" << std::endl << std::endl;
    } else if( modus == 2) { // int modus == 2: Sortierung nach Gewicht mithilfe des bubblesort-Algorithmus.
        std::cout << std::endl << "------------------------------------" << std::endl << "SORTIEREN IM MODUS " << modus << std::endl << "------------------------------------";
        std::cout << std::endl << "vorher" << std::endl;
        this->view();
        std::cout << std::endl << "int modus == " << modus << ": Sortierung nach Gewicht mithilfe des bubblesort-Algorithmus." << std::endl;
        this->quicksort_seriennummer(0,9);
        std::cout << std::endl << "nachher" << std::endl;
        this->view();
        std::cout << std::endl << "------------------------------------" << std::endl << "* * * * * ENDE " << modus << std::endl << "------------------------------------" << std::endl << std::endl;
    }else if( modus == 3) { // int modus == 3: Sortierung alphabetisch nach Bezeichnung mihilfe des mergesort-Algorithmus.
        std::cout << std::endl << "------------------------------------" << std::endl << "SORTIEREN IM MODUS " << modus << std::endl << "------------------------------------";
        std::cout << std::endl << "vorher" << std::endl;
        this->view();
        std::cout << std::endl << "int modus == " << modus << ": Sortierung alphabetisch nach Bezeichnung mihilfe des mergesort-Algorithmus." << std::endl;
        this->quicksort_seriennummer(0,9);
        std::cout << std::endl << "nachher" << std::endl;
        this->view();
        std::cout << std::endl << "------------------------------------" << std::endl << "* * * * * ENDE " << modus << std::endl << "------------------------------------" << std::endl << std::endl;
    }else if( modus == 4) { // int modus == 4: Sortierung nach Einkaufspreis mithilfe des insertionsort-Algorithmus in seiner Basisvariante.
        std::cout << std::endl << "------------------------------------" << std::endl << "SORTIEREN IM MODUS " << modus << std::endl << "------------------------------------";
        std::cout << std::endl << "vorher" << std::endl;
        this->view();
        std::cout << std::endl << "int modus == " << modus << ": Sortierung nach Einkaufspreis mithilfe des insertionsort-Algorithmus in seiner Basisvariante." << std::endl;
        this->quicksort_seriennummer(0,9);
        std::cout << std::endl << "nachher" << std::endl;
        this->view();
        std::cout << std::endl << "------------------------------------" << std::endl << "* * * * * ENDE " << modus << std::endl << "------------------------------------" << std::endl << std::endl;
    }else if( modus == 5) { // int modus == 5: Sortierung nach Verkaufspreis mithilfe des insertionsort-Algorithmus in seiner Basisvariante.
        std::cout << std::endl << "------------------------------------" << std::endl << "SORTIEREN IM MODUS " << modus << std::endl << "------------------------------------";
        std::cout << std::endl << "vorher" << std::endl;
        this->view();
        std::cout << std::endl << "int modus == " << modus << ": Sortierung nach Verkaufspreis mithilfe des insertionsort-Algorithmus in seiner Basisvariante." << std::endl;
        this->quicksort_seriennummer(0,9);
        std::cout << std::endl << "nachher" << std::endl;
        this->view();
        std::cout << std::endl << "------------------------------------" << std::endl << "* * * * * ENDE " << modus << std::endl << "------------------------------------" << std::endl << std::endl;
    }else {
        std::cout << "Sortieralgorythmus unbekannt." << std::endl;
    }
}

void Sortiment::addWare(Ware* ware) {
    int i = 0, success = 0;
    for (i = 0; i < MAXELEMENTS; i++) {
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
    while ( i < MAXELEMENTS ) {
        std::cout << this->waren[i] << " <- ADR ___ " << this->waren[i]->getBezeichnung() << ", SNR " << this->waren[i]->getSeriennummer() << ", Gewicht " << this->waren[i]->getGewicht() << " kg, EP " << this->waren[i]->getEinkaufspreis() << " EUR, VP " << this->waren[i]->getVerkaufspreis()<< " EUR." << std::endl;
        i++;
    }
}

// https://www.softwaretestinghelp.com/quick-sort/#C_Example
int Sortiment::quicksort_pivot(int low, int high)
{
    int pivot = this->waren[high]->getSeriennummer();
    int i = low-1;

    for (int j = low; j <= high- 1; j++)
    {
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (waren[j]->getSeriennummer() <= pivot)
        {
            i++;    // increment index of smaller element
            swap_waren(i, j);
        }
    }
    swap_waren(i+1, high);
    return i+1;
}


void Sortiment::quicksort_seriennummer(int low, int high) {
    if (low < high)
    {
        //partition the array
        int pivot = quicksort_pivot(low, high);

        //sort the sub arrays independently
        quicksort_seriennummer(low, pivot - 1);
        quicksort_seriennummer(pivot + 1, high);
    }

    // return pivotIndex;

/*    while ( this->waren[i] && i < 9 ) {
        std::cout << this->waren[i]->getSeriennummer() << " > " << this->waren[i+1]->getSeriennummer() << std::endl;
        if( this->waren[i]->getSeriennummer() > this->waren[i+1]->getSeriennummer() ) {
            std::cout << "SWAP" << std::endl;
            this->swap_waren(i, i+1);
        }else{
            std::cout << "NO SWAP" << std::endl;
            i++;
        }
    }*/
}


void Sortiment::swap_waren(int posA, int posB) {
    Ware warendummy;
    //std::cout << " Ware 1 ::: " << this->waren[posA]->getBezeichnung() << ", SNR " << this->waren[posA]->getSeriennummer() << ", Gewicht " << this->waren[posA]->getGewicht() << " kg, EP " << this->waren[posA]->getEinkaufspreis() << " EUR, VP " << this->waren[posA]->getVerkaufspreis()<< " EUR." << std::endl;
    //std::cout << " Ware 2 ::: " << this->waren[posB]->getBezeichnung() << ", SNR " << this->waren[posB]->getSeriennummer() << ", Gewicht " << this->waren[posB]->getGewicht() << " kg, EP " << this->waren[posB]->getEinkaufspreis() << " EUR, VP " << this->waren[posB]->getVerkaufspreis()<< " EUR." << std::endl;

    warendummy.setBezeichnung( this->waren[posA]->getBezeichnung() );
    warendummy.setSeriennummer( this->waren[posA]->getSeriennummer() );
    warendummy.setGewicht( this->waren[posA]->getGewicht() );
    warendummy.setEinkaufspreis( this->waren[posA]->getEinkaufspreis() );
    warendummy.setVerkaufspreis( this->waren[posA]->getVerkaufspreis() );

    this->waren[posA]->setBezeichnung( this->waren[posB]->getBezeichnung() );
    this->waren[posA]->setSeriennummer( this->waren[posB]->getSeriennummer() );
    this->waren[posA]->setGewicht( this->waren[posB]->getGewicht() );
    this->waren[posA]->setEinkaufspreis( this->waren[posB]->getEinkaufspreis() );
    this->waren[posA]->setVerkaufspreis( this->waren[posB]->getVerkaufspreis() );

    this->waren[posB]->setBezeichnung( warendummy.getBezeichnung() );
    this->waren[posB]->setSeriennummer( warendummy.getSeriennummer() );
    this->waren[posB]->setGewicht( warendummy.getGewicht() );
    this->waren[posB]->setEinkaufspreis( warendummy.getEinkaufspreis() );
    this->waren[posB]->setVerkaufspreis( warendummy.getVerkaufspreis() );

    //std::cout << " Ware 1 ::: " << this->waren[posA]->getBezeichnung() << ", SNR " << this->waren[posA]->getSeriennummer() << ", Gewicht " << this->waren[posA]->getGewicht() << " kg, EP " << this->waren[posA]->getEinkaufspreis() << " EUR, VP " << this->waren[posA]->getVerkaufspreis()<< " EUR." << std::endl;
    //std::cout << " Ware 2 ::: " << this->waren[posB]->getBezeichnung() << ", SNR " << this->waren[posB]->getSeriennummer() << ", Gewicht " << this->waren[posB]->getGewicht() << " kg, EP " << this->waren[posB]->getEinkaufspreis() << " EUR, VP " << this->waren[posB]->getVerkaufspreis()<< " EUR." << std::endl;

}