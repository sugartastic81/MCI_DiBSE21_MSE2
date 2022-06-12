// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#include "extendedBinaryTree.h"
#include <iostream>

ExtendedBinaryTree::ExtendedBinaryTree(Ware* rootNodeKey) {
    ExtendedBinaryTreeNode* root = new ExtendedBinaryTreeNode(rootNodeKey);
    this->rootNode = root;
}

ExtendedBinaryTreeNode* ExtendedBinaryTree::insert(Ware* key) {
    return this->rootNode->insert(key);
}

ExtendedBinaryTreeNode* ExtendedBinaryTree::search(double value) {
    ExtendedBinaryTreeNode* node = this->rootNode;
    while(value != node->key->getVerkaufspreis() && node != nullptr) {
        if(value > node->key->getVerkaufspreis()) {
            node = node->right;
        } else {
            node = node->left;
        }
    }
    return node;
}

ExtendedBinaryTreeNode* ExtendedBinaryTree::deleteItem(Ware* key) {
    return this->rootNode->deleteItem(key);
}

ExtendedBinaryTreeNode* ExtendedBinaryTree::findMin(ExtendedBinaryTreeNode* node) {
    while(node->left != nullptr) {
        node = node->left;
    }
    return node;
}

ExtendedBinaryTreeNode* ExtendedBinaryTree::findMax(ExtendedBinaryTreeNode* node) {
    while(node->right != nullptr) {
        node = node->right;
    }
    return node;
}

// function to print a tree in pre-order: (sub)root, left (sub)tree, right (sub)tree
std::string ExtendedBinaryTree::printPreorder(ExtendedBinaryTreeNode* node) {
    std::stringstream output;

    output << node->key->getVerkaufspreis() << "  ";
    //node->key->printWare();

    if(node->left != nullptr) {
        output << this->printPreorder(node->left);
    }
    if(node->right != nullptr) {
        output << this->printPreorder(node->right);
    }
    return output.str();
}

std::string ExtendedBinaryTree::printPreorder(Ware* node) {
    return this->printPreorder(search(node->getVerkaufspreis()));
}

std::string ExtendedBinaryTree::printPreorder() {
    return this->printPreorder(this->rootNode);
}

// function to print a tree in pre-order: (sub)root, left (sub)tree, right (sub)tree
std::string ExtendedBinaryTree::printPostorder(ExtendedBinaryTreeNode* node) {
    std::stringstream output;

    if(node->left != nullptr) {
        output << this->printPostorder(node->left);
    }
    if(node->right != nullptr) {
        output << this->printPostorder(node->right);
    }

    output << node->key->getVerkaufspreis() << "  ";
    //node->key->printWare();

    return output.str();
}

std::string ExtendedBinaryTree::printPostorder(Ware* node) {
    return this->printPostorder(search(node->getVerkaufspreis()));
}

std::string ExtendedBinaryTree::printPostorder() {
    return this->printPostorder(this->rootNode);
}

// function to print a tree in pre-order: (sub)root, left (sub)tree, right (sub)tree
std::string ExtendedBinaryTree::printInorder(ExtendedBinaryTreeNode* node) {
    std::stringstream output;
    if(node->left != nullptr) {
        output << this->printInorder(node->left);
    }

    output << node->key->getVerkaufspreis() << "  ";

    if(node->right != nullptr) {
        output << this->printInorder(node->right);
    }

    return output.str();
}

std::string ExtendedBinaryTree::printInorder(Ware* node) {
    return this->printInorder(search(node->getVerkaufspreis()));
}

std::string ExtendedBinaryTree::printInorder() {
    return this->printInorder(this->rootNode);
}



