// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#ifndef ABGABE1_SORTIMENT_H
#define ABGABE1_SORTIMENT_H

#include <iostream>
#include "Ware.h"

using namespace std;

class Sortiment {
private:
    Ware* waren[10] = {};
public:
    Sortiment() {}

    virtual ~Sortiment()
    {
        //std::cout << "Sortiment::Destructor: " << std::endl;
    }
    void sort(int modus);
    void addWare(Ware* ware);
    void view();
};

#endif //ABGABE1_SORTIMENT_H
