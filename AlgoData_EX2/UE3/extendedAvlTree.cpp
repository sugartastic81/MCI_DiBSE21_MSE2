// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#include <string>
#include <iostream>
#include <sstream>
#include "extendedAvlTree.h"

AvlNode::AvlNode(int key) {
    this->left = NULL;
    this->right = NULL;
    this->key = key;
    this->height = 1;
}

AvlNode* AvlNode::deleteItem(int key) {
    // to be defined
}

int AvlNode::max(int n1, int n2) {
    return (n1> n2) ? n1 : n2;
}

int AvlNode::min(int n1, int n2) {
    return (n1 < n2) ? n1 : n2;
}

int AvlNode::getHeightDifference() {
    int diff;
    AvlNode* node = this;
    if(node == NULL) {
        diff = 0;
    } else {
        diff = this->left->getHeight() - this->right->getHeight();
    }
    return diff;
}

int AvlNode::getHeight() {
    AvlNode* node = this;
    if(node == NULL) {
        return 0;
    } else {
        return node->height;
    }
}

AvlNode* AvlNode::insert(int key) {
    AvlNode* node = this;
    if(node == NULL) {
        AvlNode* newNode = new AvlNode(key);
        return newNode;
    } else if(key > this->key) {
        this->right = this->right->insert(key);
    } else if(key < this->key) {
        this->left = this->left->insert(key);
    } else {
        return this;
    }
    this->height = 1 + this->max(this->left->getHeight(), this->right->getHeight());

    int diff = this->getHeightDifference();
    if(diff > 1) {
        if(key > this->left->key){
            this->left = this->left->leftRotation();
            return this->rightRotation();

        } else if(key < this->left->key) {
            return this->rightRotation();
        }
    } else if(diff < -1) {
        if(key > this->right->key) {
            return this->leftRotation();
        } else if(key < this->right->key) {
            this->right = this->right->rightRotation();
            return this->leftRotation();
        }
    }
    return this;
}


AvlNode* AvlNode::leftRotation() {
    std::cout << "Do a left rotation on node " << this->key << "\n";
    AvlNode* rightNode = this->right;
    AvlNode* leftOfRightNode = rightNode->left;
    rightNode->left = this;
    this->right = leftOfRightNode;
    this->height = this->max(this->left->getHeight(), this->right->getHeight()) + 1;
    rightNode->height = this->max((rightNode->left->getHeight()), rightNode->right->getHeight()) + 1;
    return rightNode;

}

AvlNode* AvlNode::rightRotation() {
    std::cout << "Do a right rotation on node " << this->key << "\n";
    AvlNode* leftNode = this->left;
    AvlNode* rightOfLeftNode = leftNode->right;
    leftNode->right = this;
    this->left = rightOfLeftNode;
    this->height = this->max(this->left->getHeight(), this->right->getHeight()) + 1;
    leftNode->height = this->max(leftNode->left->getHeight(), leftNode->right->getHeight()) + 1;
    return leftNode;
}

std::string AvlNode::printAvlTree() {
    std::stringstream output;
    output << this->key << " = key\t\t";
    output << this->getHeight() << " = height\t\t";
    output << this->getHeightDifference() << " = difference" << std::endl;
    if(this->left != NULL) {
        output << this->left->printAvlTree();
    }
    if(this->right != NULL) {
        output << this->right->printAvlTree();
    }
    return output.str();
}
