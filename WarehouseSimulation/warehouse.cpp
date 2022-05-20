// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#include <unistd.h>
#include <iostream>
#include <cstdlib>

#include "warehouse.h"
#include "goods.h"
#include "exeptions.h"

using namespace std;

// adds a good
int Warehouse::addGood(Good* good) {
    int id = goodREFid++;
    goods.insert(std::pair<int, Good *>(id, good));
    std::cout << "Pallet has been packed and RFID tagged with ID " << goods[id] << "." << std::endl;
    return id;
}

// Returns a good
Good* Warehouse::getGood(int id) {
    if (goods.find(id) != goods.end()) {
        return goods[id];
    } else {
        return nullptr;
    }
}

// Deletes a good
void Warehouse::deleteGood(int id) {
    goods.erase(id);
}

void Warehouse::conveyorSystem(int iterations){
    int statusCount = 0;
    int iterationCount = 0;
    std::cout << std::endl << "Conveyor system starts." << std::endl << std::endl;

    while (iterations == 0 || iterations > iterationCount ) {

        for (auto &good: goods) {
            try {
                int level = good.second->scanGood();
                std::cout << "Load this pallet onto the truck at the gate " << level << std::endl;
            } catch (DefectiveGoodExceptions &e) {
                std::cout << e.what() << std::endl;
                break;
            } catch (ScanErrorExceptions &e) {
                std::cout << e.what() << std::endl;
            }
            sleep(1);
        }

        iterationCount++;
    }
}