// https://www.cplusplus.com/doc/tutorial/templates/

#pragma once


#include <iostream>

using namespace std;

namespace basic_paradigm
{

class MyVector {

public:
    MyVector() {}
    MyVector(int a, int b) : x(a), y(b) {}

    MyVector operator + (const MyVector& param) {
        MyVector temp;
        temp.x = x + param.x;
        temp.y = y + param.y;
        return temp;
    }

    int getX() const
    {
        return x;
    }
    int getY() const
    {
        return y;
    }

private:
    int x, y;
};

}