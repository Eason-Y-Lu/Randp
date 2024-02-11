//
// Created by eason on 2/10/24.
//

#include "binTree.h"
#include <exception>

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

    bool binTree::isLeaf() {
        return (this->right == nullptr && this->left == nullptr);
    }


    void binTree::setRight(binTree *newRight) {
        this->right = newRight;
    }

    void binTree::setLeft(binTree *newLeft) {
        this->left = newLeft;
    }

    std::vector<std::vector<binTree *>> binTree::toVector() {
        std::vector<std::vector<binTree *>> returnBinTree{std::vector<binTree *>{this}};
        bool containNonLeaf = true;
        //example of a bin tree
        // 1
        // 2 3
        // 4 5 6
        //converted to a vector will be <<p1> <p2 p3> <p4 p5 p6>>
        //depth of such bin tree will be std::vector<std::vector<binTree*>>.size
        //check if last array is not an array of 0s
        while (containNonLeaf) {
            for (int i = 0; i < returnBinTree.back().size(); i++) {
                if (returnBinTree.back().at(i)->right != nullptr && returnBinTree.back().at(1)->left != nullptr) {
                    containNonLeaf = true;
                    break;
                } else {
                    containNonLeaf = false;
                }
            }
            if (containNonLeaf) {
                toVectorHelper(returnBinTree);
            }
        }
    }

    void binTree::toVectorHelper(std::vector<std::vector<binTree *>> &currentVBinTree) {
        std::vector<binTree *> pushVector(currentVBinTree.back().size() * 2);
        for (auto &i: currentVBinTree.back()) {
            binTree *lLeft;
            binTree *lRight;
            lLeft = i->left;
            lRight = i->right;
            if (lLeft != nullptr)pushVector.push_back(lLeft);
            if (lRight != nullptr)pushVector.push_back(lRight);
        }
        currentVBinTree.push_back(pushVector);
    }

    void binTree::insert(binTree *root) {
        if (this->value < root->value) {
            insertHelper(root->left);
        } else if (this->value > root->value) {
            insertHelper(root->right);
        } else {
            throw std::exception();
        }
    }

    void binTree::insertHelper(binTree *currentNode) {
        if (currentNode == nullptr) {
            this->parent = currentNode;
            return;
        }
        if (this->value < currentNode->value) {
            insertHelper(currentNode->left);
        } else if (this->value > currentNode->value) {
            insertHelper(currentNode->right);
        } else {
            throw std::exception();
        }
    }
} // binTree