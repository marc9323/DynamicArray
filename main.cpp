#include <iostream>
#include "DynamicArray.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    DynamicArray d1;

    std::cout << "Capacity: " << d1.getCapacity() << std::endl;

    d1.add(75);
    d1.add(80);
    d1.add(32);
    d1.add(100);
    d1.add(55);
    d1.add(202);

    std::cout << "Capacity: " << d1.getCapacity() << std::endl;

    d1.add(493);
    d1.add(908);
    d1.add(1232);

    d1.add(12, 4);

    d1.print();

    std::cout << "Capacity: " << d1.getCapacity() << std::endl;

    std::cout << "Copy COnstructor called!" << std::endl;
    DynamicArray d2(d1); // copy constructor, shallow copy

    d1.add(100, 0);

    d1.print();
    d2.print();

    std::cout << "Copy Assignment opertor called!" << std::endl;
    DynamicArray d3;
    d3 = d1; // copy assignment operator called, shallow copy

    d1.add(100, 0);
    d1.print(); // change in d1 is reflected in d2 and d3
    d2.print();
    d3.print();

    return 0;
}
