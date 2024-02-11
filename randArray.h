//
// Created by eason on 2/11/24.
//

#ifndef RANDP_RANDARRAY_H
#define RANDP_RANDARRAY_H

#include <vector>

namespace randArray {

    class randArray {
    public:
        randArray(int endNum);

        ~randArray() = default;

        int nextNum();

    private:
        std::vector<int> array;
        int currentNum;

    };

} // randArray

#endif //RANDP_RANDARRAY_H
