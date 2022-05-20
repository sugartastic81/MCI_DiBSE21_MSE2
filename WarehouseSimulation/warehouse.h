// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#ifndef DAYONE_WAREHOUSE_H
#define DAYONE_WAREHOUSE_H

#include <map>
#include "goods.h"
#include "exeptions.h"

class Warehouse {
private:
    std::map<int, Good*> goods;
    int goodREFid = 0;
public:
    virtual ~Warehouse() {
        for (int i = 0; i < goods.size(); ++i) {
            //std::cout << "Delete good number " << i << "." << std::endl;
            delete goods[i];
        }
    };

    // adds a good
    int addGood(Good* good);

    // Returns a good
    Good* getGood(int id);

    // Deletes a good
    void deleteGood(int id);

    void conveyorSystem(int iterations);
};

#endif //DAYONE_WAREHOUSE_H
