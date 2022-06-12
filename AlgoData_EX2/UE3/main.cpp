// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#include <iostream>
#include "extendedAvlTree.h"

#define LISTLENGTH 60


int main() {
    srand( (unsigned) time(nullptr));

    AvlNode* firstTREE = new AvlNode(42);
    for( int i = 1; i < LISTLENGTH; i++) {
        firstTREE = firstTREE->insert(rand() % 89 + 10);
    }

    std::cout << firstTREE->printAvlTree();

    std::cout << std::endl << "DELETE RANDOM ITEMS" << std::endl;
    for( int i = 1; i < LISTLENGTH/2; i++) {
        firstTREE->deleteItem(rand() % 89 + 10);
    }

    return 0;
}
