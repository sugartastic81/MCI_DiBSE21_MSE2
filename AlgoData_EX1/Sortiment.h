// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#ifndef ABGABE1_SORTIMENT_H
#define ABGABE1_SORTIMENT_H

#define MAXWAREROWS 100

#include <iostream>
#include "Ware.h"

using namespace std;

class Sortiment {
private:
    int WareCounter = 0;
    Ware* waren[MAXWAREROWS] = {};
public:
    Sortiment() {}

    virtual ~Sortiment()
    {
        //std::cout << "Sortiment::Destructor: " << std::endl;
    }
    void sort(int modus);
    void swap_waren(int posA, int posB);
    void addWare(Ware* ware);
    void view();

    int getWareCounter() const;

    void setWareCounter(int wareCounter);
};

#endif //ABGABE1_SORTIMENT_H
