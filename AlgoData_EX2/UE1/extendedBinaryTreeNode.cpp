// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#include "extendedBinaryTreeNode.h"
#include <iostream>

ExtendedBinaryTreeNode::ExtendedBinaryTreeNode(Ware* key) {
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
}

ExtendedBinaryTreeNode* ExtendedBinaryTreeNode::insert(Ware* key) {
    if(key->getVerkaufspreis() > this->key->getVerkaufspreis()) {
        if(this->right == nullptr) {
            ExtendedBinaryTreeNode* temp = new ExtendedBinaryTreeNode(key);
            this->right = temp;
            return this->right;
        }
        this->right->insert(key);
    } else {
        if(this->left == nullptr) {
            ExtendedBinaryTreeNode* temp = new ExtendedBinaryTreeNode(key);
            this->left = temp;
            return this->left;
        }
        this->left->insert(key);
    }
    return this;
}

ExtendedBinaryTreeNode* ExtendedBinaryTreeNode::deleteItem(Ware* key) {
    ExtendedBinaryTreeNode* node = this;

    if(node == nullptr) {
        return this;
    } else if(key->getVerkaufspreis() < node->key->getVerkaufspreis()) {
        node->left = node->left->deleteItem(key);
    } else if(key->getVerkaufspreis() > node->key->getVerkaufspreis()) {
        node->right = node->right->deleteItem(key);
    } else {
        if(node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        } else if(node->left == nullptr) { // only children in right subtree
            ExtendedBinaryTreeNode* temp = node;
            node = node->right;
            delete temp;
        } else if(this->right == nullptr) { // only children in left subtree
            ExtendedBinaryTreeNode* temp = node;
            node = node->left;
            delete temp;
        } else { // we have to keep the BST structure, here, we look for the minimum in the right subtree (see lecture)
            ExtendedBinaryTreeNode* temp = node;;
            while(temp->left != nullptr) {
                temp = temp->left;
            }
            std::cout << "here"<<  temp->key << std::endl;
            node->key = temp->key;
            node->right = node->right->deleteItem(temp->key);
        }
    }
    return node;
}