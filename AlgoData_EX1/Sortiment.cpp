// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#include "Ware.h"
#include "Sortiment.h"
#include "Algorithms.h"
#include "exceptions.h"
#include "PerformanceTest.h"

void Sortiment::sort(int modus) {
    PerformanceTest* pt = new PerformanceTest();
    if( modus == 1) { // int modus == 1: Sorting by serial number with the QuickSort algorithm.
        pt->setAlgorithmName("QuickSort");
        auto startTime = std::chrono::high_resolution_clock::now();
        quicksort_seriennummer(this->waren, 0, this->getWareCounter()-1);
        auto endTime = std::chrono::high_resolution_clock::now();
        pt->processResult(startTime, endTime);
        std::cout << "------------------------------------" << std::endl << "modus == " << modus << ": Sorting by serial number (SNR) with the quicksort algorithm." << std::endl << "------------------------------------" << std::endl;
        std::cout  << "execution time " << pt->getTotalExecutionTime() << "sec." << std::endl;
    } else if( modus == 2) { // int modus == 2: Sorting by weight with the bubblesort algorithm.
        pt->setAlgorithmName("BubbleSort");
        auto startTime = std::chrono::high_resolution_clock::now();
        bubblesort_gewicht(this->waren, this->getWareCounter());
        auto endTime = std::chrono::high_resolution_clock::now();
        pt->processResult(startTime, endTime);
        std::cout << "------------------------------------" << std::endl << "modus == " << modus << ": Sorting by weight with the bubblesort algorithm." << std::endl << "------------------------------------" << std::endl;
        std::cout  << "execution time " << pt->getTotalExecutionTime() << "sec." << std::endl;
    }else if( modus == 3) { // int modus == 3: Sorting alphabetically by name using the mergesort algorithm.
        pt->setAlgorithmName("MergeSort");
        auto startTime = std::chrono::high_resolution_clock::now();
        mergesort_bezeichnung(this->waren, 0, this->getWareCounter()-1);
        auto endTime = std::chrono::high_resolution_clock::now();
        pt->processResult(startTime, endTime);
        std::cout << "------------------------------------" << std::endl << "modus == " << modus << ": Sorting alphabetically by item name using the mergesort algorithm." << std::endl << "------------------------------------" << std::endl;
        std::cout << "execution time " << pt->getTotalExecutionTime() << "sec." << std::endl;
    }else if( modus == 4) { // int modus == 4: Sorting by buy price using the insertionsort algorithm in its base variant.
        pt->setAlgorithmName("insertionSortBase");
        auto startTime = std::chrono::high_resolution_clock::now();
        insertionSortBase_buyprice(this->waren, this->getWareCounter());
        auto endTime = std::chrono::high_resolution_clock::now();
        pt->processResult(startTime, endTime);
        std::cout << "------------------------------------" << std::endl << "modus == " << modus << ": Sorting by buy price using the insertionsort algorithm in its base variant." << std::endl << "------------------------------------" << std::endl;
        std::cout << "execution time " << pt->getTotalExecutionTime() << "sec." << std::endl;
    }else if( modus == 5) { // int modus == 5: Sorting by sell price using the insertionsort algorithm in its optimized variant.
        pt->setAlgorithmName("insertionSortOptimized");
        auto startTime = std::chrono::high_resolution_clock::now();
        insertionSortOptimized_sellprice(this->waren, this->getWareCounter());
        auto endTime = std::chrono::high_resolution_clock::now();
        pt->processResult(startTime, endTime);
        std::cout << "------------------------------------" << std::endl << "modus == " << modus << ": Sorting by sell price using the insertionsort algorithm in its base variant." << std::endl << "------------------------------------" << std::endl;

        std::cout << "execution time " << pt->getTotalExecutionTime() << "sec." << std::endl;
    }else {
        std::cout << "Modus unknown/undefined." << std::endl;
    }
}

void Sortiment::addWare(Ware* ware) {
    int i = 0, success = 0;
    for (i = 0; i < MAXWAREROWS; i++) {
        if ( !this->waren[i] ) {
            this->waren[i] = ware;
            //std::cout << "add " << this->waren[i]->getBezeichnung() << ", SNR " << this->waren[i]->getSeriennummer() << ", " << this->waren[i]->getGewicht() << " kg, buy " << this->waren[i]->getEinkaufspreis() << " EUR, sell " << this->waren[i]->getVerkaufspreis()<< " EUR." << std::endl;
            success = 1;
            this->setWareCounter((this->getWareCounter()+1));
            break;
        }
    }
    if( success != 1 ) {
        // throw FullSortimentException("No more space to add item!");
        std::cout << "No more space to add item!" << std::endl;
    }
}

void Sortiment::view() {
    int i = 0;
    while ( i < this->getWareCounter() ) {
        string bezeichnung = waren[i]->getBezeichnung();
        std::cout << bezeichnung;
        if( bezeichnung.size() < 16 ) {
            std::cout << "\t";
        }
        if( bezeichnung.size() < 8 ) {
            std::cout << "\t";
        }
        std::cout << "\tSNR " << this->waren[i]->getSeriennummer() << "    \tweight " << this->waren[i]->getGewicht() << " kg\tbuy " << this->waren[i]->getEinkaufspreis() << " EUR\tsell " << this->waren[i]->getVerkaufspreis()<< " EUR" << std::endl;
        i++;
    }
}

int Sortiment::getWareCounter() const {
    return WareCounter;
}

void Sortiment::setWareCounter(int wareCounter) {
    WareCounter = wareCounter;
}

