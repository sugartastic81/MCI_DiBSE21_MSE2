// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#include "ExtendedListItem.h"

#include <iostream>
#include <sstream>

ExtendedListItem::ExtendedListItem(int key) {
    this->key = key;
    this->next = nullptr;
    this->previous = nullptr;
}

std::string ExtendedListItem::MakeItemString(void) {
    std::stringstream output;
    if(this->previous != nullptr) {
        output << this->previous->key << " << ";
    }else{
        output << "NP << ";
    }
    output << this->key;
    if(this->next != nullptr) {
        output << " >> " << this->next->key;
    }else{
        output << " >> NP";
    }
    output << std::endl;
    return output.str();
}



