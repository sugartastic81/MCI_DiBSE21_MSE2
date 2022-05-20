// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#include "warehouse.h"
#include "goods.h"
#include "exeptions.h"

int standardGoods::scanGood() {
    int randNum = rand() % 100;
    if (randNum < 3) {
        throw DefectiveGoodExceptions("Attention! These standard goods on this pallet may be defective!");
    } else if (randNum >= 98) {
        throw ScanErrorExceptions("Alert! Error during the scanning process of a standard good!");
    } else {
        return rand() % 4 + 1;
    }
}

int hazardousGoods::scanGood() {
    int randNum = rand() % 100;
    if (randNum < 5) {
        throw DefectiveGoodExceptions("Attention! These hazardous goods on this pallet may be defective!");
    } else if (randNum >= 95) {
        throw ScanErrorExceptions("Alert! Error during the scanning process of a hazardous good!");
    } else {
        return rand() % 4 + 1;
    }
}

int frozenGoods::scanGood() {
    int randNum = rand() % 100;
    if (randNum < 10) {
        throw DefectiveGoodExceptions("Attention! These frozen goods on this pallet may be defective!");
    } else if (randNum >= 90) {
        throw ScanErrorExceptions("Alert!  Error during the scanning process of a frozen good!");
    } else {
        return rand() % 4 + 1;
    }
}