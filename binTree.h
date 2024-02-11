//
// Created by eason on 2/10/24.
//

#ifndef RANDP_BINTREE_H
#define RANDP_BINTREE_H
#include <vector>
namespace binTree {

    class binTree {
    public:
        binTree(int value,binTree* parent,binTree* left,binTree* right);
        ~binTree();
        void insert(binTree *root);
        binTree* getRight();
        binTree* getLeft();
        binTree* getParent();

        void setRight(binTree* newRight);
        void setLeft(binTree* newLeft);
        bool isLeaf();
        std::vector<std::vector<binTree*>> toVector ();

    private:
        binTree* parent;
        binTree* left;
        binTree* right;
        int value;
        static void toVectorHelper(std::vector<std::vector<binTree*>>& currentVBinTree);
        void insertHelper(binTree *currentNode);
    };

} // binTree

#endif //RANDP_BINTREE_H
