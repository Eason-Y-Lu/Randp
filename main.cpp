#include <iostream>
#include "randArray.h"
#include "binTree.h"

int main() {
    long long totalDepth = 0;
    for (int i = 0; i < 10000000; i++) {
        if (i % 1000 == 0) {
            std::cout << i << "\n";
        }
        randArray::randArray mainArr(10000);
        auto *root = new binTree::binTree(mainArr.nextNum(), nullptr, nullptr, nullptr);
        for (int i = 1; i < 10000; i++) {
            auto *tempNode = new binTree::binTree(mainArr.nextNum(), nullptr, nullptr, nullptr);
            tempNode->insert(root);
        }
        std::vector<std::vector<binTree::binTree *>> vNum = root->toVector();
        totalDepth = totalDepth + vNum.size() - 1;
        for (int i = 0; i < vNum.size(); i++) {
            for (int j = 0; j < vNum.at(i).size(); j++) {
                delete vNum.at(i).at(j);
            }
        }
    }
    std::cout << totalDepth << "\n";
    std::cout << totalDepth / 10000000 << "\n";

    return 0;
}
