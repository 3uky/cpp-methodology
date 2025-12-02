// https://www.cplusplus.com/doc/tutorial/polymorphism/

#pragma once

namespace oop_paradigm
{

class IPolygon
{
    virtual void set_values(int a, int b) = 0;
};

class Polygon : public IPolygon {
protected:
    int width, height;

public:
    void set_values(int a, int b)
    {
        width = a;
        height = b;
    }

    virtual int area() = 0;
};

class Rectangle : public Polygon {
public:
    int area()
    {
        return width * height;
    }
};

class Triangle : public Polygon {
public:
    int area()
    {
        return (width * height) / 2;
    }
};

}