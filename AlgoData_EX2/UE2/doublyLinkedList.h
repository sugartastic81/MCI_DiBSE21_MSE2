// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#ifndef ABGABE1_DOUBLYLINKEDLIST_H
#define ABGABE1_DOUBLYLINKEDLIST_H

#include "extendedListItem.h"
#include <iostream>

#pragma once

class DoublyLinkedList {
private:

public:
    DoublyLinkedList();

    ExtendedListItem* head;
    ExtendedListItem* tail;
    void insertSorted(int key);

    void integrates(DoublyLinkedList* integratingList);
    void append(DoublyLinkedList* appendingList);
    void splice(DoublyLinkedList* insertingList, int position);
    void insertAtStart(int key);
    void insertAtEnd(int key);
    void deleteItem(int key);
    void print();
};


#endif //ABGABE1_DOUBLYLINKEDLIST_H
