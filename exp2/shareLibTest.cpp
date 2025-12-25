#include <iostream>
#include "shareLibTest.h"
int main() {
    std::cout << "Calling shared library function from main." << std::endl;
    testSharedLib();
    return 0;
}