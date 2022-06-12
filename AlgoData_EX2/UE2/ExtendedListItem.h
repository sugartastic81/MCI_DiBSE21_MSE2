// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#ifndef ABGABE1_EXTENDEDLISTITEM_H
#define ABGABE1_EXTENDEDLISTITEM_H

#include <string>

#pragma once

class ExtendedListItem {
private:

public:
    ExtendedListItem(int key);
    std::string MakeItemString();
    ExtendedListItem* next;
    ExtendedListItem* previous;
    int key;

};


#endif //ABGABE1_EXTENDEDLISTITEM_H
