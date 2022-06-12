// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#ifndef ABGABE_EXTENDEDBINARYTREE_H
#define ABGABE_EXTENDEDBINARYTREE_H

#include "extendedBinaryTreeNode.h"
#include "Ware.h"
#include <string>
#include <sstream>

#pragma once

class ExtendedBinaryTree {
public:
    ExtendedBinaryTreeNode* rootNode;

    ExtendedBinaryTree(Ware* rootNodeKey);

    ExtendedBinaryTreeNode* search(double value);
    ExtendedBinaryTreeNode* insert(Ware* key);
    ExtendedBinaryTreeNode* deleteItem(Ware* key);
    ExtendedBinaryTreeNode* findMin(ExtendedBinaryTreeNode* node);
    ExtendedBinaryTreeNode* findMax(ExtendedBinaryTreeNode* node);
    std::string printPreorder(ExtendedBinaryTreeNode* node);
    std::string printPreorder();
    std::string printPreorder(Ware* node);
    std::string printPostorder(ExtendedBinaryTreeNode* node);
    std::string printPostorder();
    std::string printPostorder(Ware* node);
    std::string printInorder(ExtendedBinaryTreeNode* node);
    std::string printInorder();
    std::string printInorder(Ware* node);
};


std::string printPreorder(ExtendedBinaryTreeNode* node);
std::string printPostorder(ExtendedBinaryTreeNode* node);
std::string printInorder(ExtendedBinaryTreeNode* node);
std::string printPreorder(Ware* node);
std::string printPostorder(Ware* node);
std::string printInorder(Ware* node);


#endif //ABGABE_EXTENDEDBINARYTREE_H
