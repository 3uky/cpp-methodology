// https://www.cplusplus.com/doc/tutorial/templates/

#pragma once

using namespace std;

namespace basic_elements
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