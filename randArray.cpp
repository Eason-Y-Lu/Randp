//
// Created by eason on 2/11/24.
//

#include "randArray.h"
#include <algorithm>
#include <random>

namespace randArray {
    randArray::randArray(int endNum) {
        currentNum = 0;
        std::random_device randomDevice;
        std::mt19937 r19937(randomDevice());
        array.reserve(endNum);
        for (int i = 0; i <= endNum; i++) {
            array.push_back(i);
        }
        std::shuffle(std::begin(array), std::end(array), r19937);
    }

    int randArray::nextNum() {
        if (currentNum + 1 > array.size()) {
            return 0;
        } else {
            int numRetrun = array.at(currentNum);
            currentNum++;
            return numRetrun;
        }
    }
} // randArray