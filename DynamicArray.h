//
// Created by marc d. holman on 3/2/2021.
//

#ifndef DYNAMICARRAY_DYNAMICARRAY_H
#define DYNAMICARRAY_DYNAMICARRAY_H

#include <iostream>


class DynamicArray {

    int *data{};
    int nextIndex{};
    int capacity{}; // total size of array
    int size{};

public:
//    DynamicArray() {
//        data = new int[5];
//        nextIndex = 0;
//        capacity = 5;
//        //size = nextIndex;
//    }

    DynamicArray():nextIndex{}, capacity(5) {
        data = new int[5];
    }

    DynamicArray(int capacity) {
        data = new int[capacity];
        nextIndex = 0;
        this->capacity = capacity;
    }

    // copy contructor - produce deep copy
    DynamicArray(DynamicArray const &d) {
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;

        // this line yields a shallow copy and is
        // the way the default copy constructor operates
        // this->data = d.data;

        // deep copy
        // deep copy procedure:  create new array, copy old values
        this->data = new int[d.capacity];
        for(size_t index = 0; index < d.nextIndex; index++) {
            this->data[index] = d.data[index];
        }
    }

    void operator=(DynamicArray const &d) {
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;

        this->data = new int[d.capacity];
        for(size_t index = 0; index < d.nextIndex; index++) {
            this->data[index] = d.data[index];
        }
    }

    void add(int element) {
        if(nextIndex == capacity) {
            int *newData = new int[2 * capacity];
            for(int i = 0; i < capacity; i++) {
                newData[i] = data[i];
            }

            delete []data;
            data = newData;

            capacity *= 2;
        }

        data[nextIndex] = element;
        nextIndex++;

    }

    void add(int element, int i) {
        if(i < nextIndex) {
            data[i] = element;
        } else if(i == nextIndex) {
            add(element);
        } else {
            std::cout << "Index is not valid. Throw Error." << std::endl;
            return;
        }
    }

    int get_element(int i) const{
        // peek
        // -1 means invalid index
        if(i >= 0 && i < nextIndex) {
            return data[i];
        } else {
            return -1;
        }
    }

    void print() const {
        for(int i = 0; i < nextIndex; i++) {
            std::cout << data[i] << " ";
        }

        std::cout << std::endl;
    }

    size_t getCapacity() const {
        return capacity;
    }

};


#endif //DYNAMICARRAY_DYNAMICARRAY_H
