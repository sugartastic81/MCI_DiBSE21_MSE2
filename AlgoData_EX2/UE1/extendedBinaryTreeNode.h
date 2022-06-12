// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#ifndef ABGABE_EXTENDEDBINARYTREENODE_H
#define ABGABE_EXTENDEDBINARYTREENODE_H

#include "Ware.h"

class ExtendedBinaryTreeNode {
public:
    Ware* key;
    ExtendedBinaryTreeNode* left;
    ExtendedBinaryTreeNode* right;

    ExtendedBinaryTreeNode(Ware* key);

    ExtendedBinaryTreeNode* insert(Ware* key);
    ExtendedBinaryTreeNode* deleteItem(Ware* key);
};

#endif //ABGABE_EXTENDEDBINARYTREENODE_H
