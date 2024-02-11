#include <iostream>
#include "binTree.h"
int main() {
    binTree::binTree root(1, nullptr, nullptr, nullptr);
    binTree::binTree node(2, nullptr, nullptr, nullptr);
    node.insert(&root);
    std::cout << node.getParent() << "\n" << root.getLeft()<<" "<<root.getRight();

}
