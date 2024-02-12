#include <iostream>
#include <string>
#include "randArray.h"
#include "binTree.h"

int main(int argc, char *argv[]) {
    int iter;
    if (argc == 1) {
        iter = 10000;
    } else if (argc == 2) {
        std::string arg1(argv[1]);
        iter = stoi(arg1);
    } else {
        throw std::invalid_argument("Only 0 or 1 input.");
    }
    std::cout << "Target counts: " << iter << "\n";
    long long totalDepth = 0;
    for (int i = 0; i < iter; i++) {
        if (i % 1000 == 0) {
            std::cout << "Currently on: " << i << "\n";
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
    std::cout << "totalDepth: " << totalDepth << "\n";
    double avg = totalDepth / iter;
    std::cout << "averageDepth: " << avg << "\n";

    return 0;
}
