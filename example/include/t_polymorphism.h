// https://www.cplusplus.com/doc/tutorial/polymorphism/

#pragma once

#include <iostream>

using namespace std;

// interface definition
class I_Polygon {
    virtual void set_values (int a, int b) = 0;
};

class Polygon : public I_Polygon {
    protected:
        int width, height;
    public:
        void set_values (int a, int b) {
            width=a;
            height=b;
        }
        
        virtual int area() = 0;
};

class Rectangle: public Polygon {
    public:
        int area()
        { return width*height; }
};

class Triangle: public Polygon {
    public:
        int area()
        { return width*height/2; }
};
