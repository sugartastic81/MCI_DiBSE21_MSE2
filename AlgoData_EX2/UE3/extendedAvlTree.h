// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#ifndef ABGABE1_EXTENDEDAVLTREE_H
#define ABGABE1_EXTENDEDAVLTREE_H

#include <string>

#pragma once

class AvlNode {
private:

public:
    int key;
    int height;
    AvlNode* left;
    AvlNode* right;

    AvlNode(int key);

    int max(int n1, int n2);
    int min(int n1, int n2);
    int getHeightDifference();
    int getHeight();

    AvlNode* insert(int key);
    AvlNode* deleteItem(int key);

    AvlNode* leftRotation();
    AvlNode* rightRotation();

    std::string printAvlTree();
};


#endif //ABGABE1_EXTENDEDAVLTREE_H
