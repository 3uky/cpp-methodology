#include <iostream>
#include <stdexcept>

#include "iterator.h"

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

    MyContainer(MyContainer& origin)
    {
        size = origin.size;
        data = new T[size];
        for (size_t i = 0; i < size; ++i) 
        {
            data[i] = origin.data[i];
        }        
    }

    ~MyContainer() {
        Cleanup();
    }
    
    void Cleanup()
    {
        delete[] data;
    }

    MyContainer& operator=(const MyContainer& origin)
    {
        Cleanup();
        size = origin.size;
        data = new T[size];
        for (size_t i = 0; i < size; ++i) 
        {
            data[i] = origin.data[i];
        }        
        return *this;
    }

    // Allow access to elements
    T& operator[](size_t index) {
        if (index >= size) 
            throw std::out_of_range("Index out of range");
        return data[index];
    }

    Iterator<T> begin() {
        return Iterator<T>(data);
    }

    Iterator<T> end() {
        return Iterator<T>(data + size);
    }
    
};

}