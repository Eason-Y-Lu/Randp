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
        throw std::invalid_argument(
                "Only accept 0 or 1 input(s). If no input provided default to 10,000 cycle. If provided input define cycles with in an int");
    }
    std::cout << "Target counts: " << iter << "\n";
    int totalDepth = 0;
    for (int i = 1; i <= iter; i++) {
        if (i % 1000 == 0) {
            std::printf("Currently on: %d, with total depth: %d, current avg. depth: %f \n", i, totalDepth,
                        (double) totalDepth / (double) i);
        }
        randArray::randArray mainArr(10000);
        auto *root = new binTree::binTree(mainArr.nextNum(), nullptr, nullptr, nullptr);
        for (int l = 1; l < 10000; l++) {
            auto *tempNode = new binTree::binTree(mainArr.nextNum(), nullptr, nullptr, nullptr);
            tempNode->insert(root);
        }
        std::vector<std::vector<binTree::binTree *>> vNum = root->toVector();
        totalDepth = totalDepth + (int) vNum.size() - 1;
        if (i % 500 == 0) {
            std::printf("\nSnapshot: Currently on: %d, current tree depth: %d; \n", i, (int) vNum.size() - 1);
            std::cout << "Current tree root value is: " << root->getValue() << ", root's left ptr is: "
                      << root->getLeft() << ", root's right ptr is: " << root->getRight() << "\n";
        }
        for (auto &k: vNum) {
            for (auto &j: k) {
                delete j;
            }
        }
    }
    std::printf("Number of Tree created: %d, total depth of those tree: %d, average depth of those tree: %f \n\n", iter,
                totalDepth, (float) totalDepth / (float) iter);

    return 0;
}
