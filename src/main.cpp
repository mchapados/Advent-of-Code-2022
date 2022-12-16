/* How to use cmake:
    1. CMakeLists.txt file
    2. cmake -Bbuild -GNinja
    3. cd ./build
    4. ninja */

#include <cstdint>
#include <iostream>
#include "day10.cpp"


int main(void) {
    std::cout << day10_pt2() << '\n';

    return EXIT_SUCCESS;
}
