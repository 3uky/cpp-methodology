#pragma once

#include <iostream>
#include <stdexcept>

namespace containers
{

// Begin iterator (returns an iterator to the first element)
template <typename T>
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

}