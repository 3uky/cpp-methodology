#pragma once

#include <iostream>
#include <stdexcept>

namespace containers
{

template <typename T>
class MyContainer {
public:
    T* data;
    size_t size;

    MyContainer(size_t s) : size(s) {
        data = new T[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = T();  // Initialize with default values
        }
    }

    ~MyContainer() {
        delete[] data;
    }

    // Allow access to elements
    T& operator[](size_t index) {
        if (index >= size) 
            throw std::out_of_range("Index out of range");
        return data[index];
    }

    // Begin iterator (returns an iterator to the first element)
    class Iterator {
    public:
        T* ptr;

        Iterator(T* p) : ptr(p) {}

        T& operator*() {
            return *ptr;
        }

        T* operator->() {
            return ptr;
        }

        // Increment operator (moving to the next element)
        Iterator& operator++() {
            ++ptr;
            return *this;
        }

        Iterator& operator--() {
            --ptr;
            return *this;
        }

        // Equality comparison (for iterator comparison)
        bool operator==(const Iterator& other) const {
            return ptr == other.ptr;
        }

        // Inequality comparison (for iterator comparison)
        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }
    };

    Iterator begin() {
        return Iterator(data);
    }

    Iterator end() {
        return Iterator(data + size);
    }
};

}