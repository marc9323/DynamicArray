#include <iostream>
#include "DynamicArray.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    DynamicArray d1;
    d1.add(75);
    d1.add(80);
    d1.add(32);
    d1.add(100);
    d1.add(55);
    d1.add(202);
    d1.add(493);

    d1.print();

    return 0;
}
