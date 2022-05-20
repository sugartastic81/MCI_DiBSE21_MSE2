// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#include <iostream>
#include "exeptions.h"
#include "warehouse.h"
#include "goods.h"

int main() {
    Warehouse warehouse;

    std::cout << std::endl;
    std::cout << "THE WENDLER SPECIAL WAREHOUSE SIMULATION STARTS!" << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;

    int i=0;
    for(i = 0; i < 10; i++) {
        int randNum = rand() % 100;
        if (randNum < 70) {
            warehouse.addGood(new standardGoods());
        } else if (randNum >= 70 && randNum < 90 ) {
            warehouse.addGood(new hazardousGoods());
        } else {
            warehouse.addGood(new frozenGoods());
        }
    }

    warehouse.conveyorSystem(3);

    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "A GIGANTIC SOLAR FLARE PARALYSES THE WAREHOUSE!" << std::endl;
    std::cout << std::endl;
}
