//
// Created by eason on 2/10/24.
//

#include "binTree.h"
#include <exception>
#include <iostream>

namespace binTree {

    binTree::binTree(int value, binTree *parent, binTree *left, binTree *right) {

        this->value = value;
        this->parent = parent;
        this->left = left;
        this->right = right;
    }

    binTree::~binTree() = default;

    binTree *binTree::getRight() {
        return this->right;
    }

    binTree *binTree::getLeft() {
        return this->left;
    }

    binTree *binTree::getParent() {
        return this->parent;
    }

    int binTree::getValue() const {
        return this->value;
    }

    bool binTree::isLeaf() {
        return (this->right == nullptr && this->left == nullptr);
    }


    void binTree::setRight(binTree *newRight) {
        this->right = newRight;
    }

    void binTree::setLeft(binTree *newLeft) {
        this->left = newLeft;
    }

#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-loop-convert"

    std::vector<std::vector<binTree *>> binTree::toVector() {
        std::vector<std::vector<binTree *>> returnBinTree{std::vector<binTree *>{this}};

        //example of a bin tree
        // 1
        // 2 3
        // 4 5 6
        //converted to a vector will be <<p1> <p2 p3> <p4 p5 p6>>
        //depth of such bin tree will be std::vector<std::vector<binTree*>>.size -1
        //check if last array is not an empty array
        while (!returnBinTree.back().empty()) {
            toVectorHelper(returnBinTree);
        }
        return returnBinTree;
    }


    void binTree::toVectorHelper(std::vector<std::vector<binTree *>> &currentVBinTree) {
        std::vector<binTree *> temp{};
        for (int i = 0; i < currentVBinTree.back().size(); i++) {
            if (currentVBinTree.back().at(i)->left != nullptr) {
                temp.push_back(currentVBinTree.back().at(i)->left);
            }
            if (currentVBinTree.back().at(i)->right != nullptr) {
                temp.push_back(currentVBinTree.back().at(i)->right);
            }
        }
        currentVBinTree.push_back(temp);
    }

#pragma clang diagnostic pop

    void binTree::insert(binTree *root) {
        if (this->value < root->value) {
            insertHelper(root->left, root);
        } else if (this->value > root->value) {
            insertHelper(root->right, root);
        } else {
            throw std::exception();
        }
    }

    void binTree::insertHelper(binTree *currentNode, binTree *parentNode) {
        if (currentNode == nullptr) {
            this->parent = parentNode;
            if (this->value < parentNode->value) {
                parentNode->left = this;
            } else {
                parentNode->right = this;
            }
            return;
        }
        if (this->value < currentNode->value) {
            insertHelper(currentNode->left, currentNode);
        } else if (this->value > currentNode->value) {
            insertHelper(currentNode->right, currentNode);
        } else {
            throw std::exception();
        }
    }
} // binTree