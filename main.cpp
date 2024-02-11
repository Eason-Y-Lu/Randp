#include <iostream>
#include "binTree.h"

int main() {
    auto *root = new binTree::binTree(1, nullptr, nullptr, nullptr);
    for (int i = 2; i < 10000; i++) {
        auto *tempnode = new binTree::binTree(i, nullptr, nullptr, nullptr);
        tempnode->insert(root);
    }
    return 0;

}
