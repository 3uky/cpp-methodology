#pragma once

#include <iostream>
#include <cmath>

namespace ocp_violated_geometry
{

class Circle 
{
public:
    Circle(double r) : radius(r) {}
    double getArea() const 
    {
        return M_PI * radius * radius;
    }
private:
    double radius;
};

class Rectangle 
{
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const 
    {
        return width * height;
    }
private:
    double width, height;
};

// if we need to add a new shape, we must modify this class,
// every new similar calculator would contain same overloading sub-set
// solution is polymorphism
class AreaCalculator 
{
public:
    double calculateArea(Circle& circle) 
    {
        return circle.getArea();
    }

    double calculateArea(Rectangle& rectangle) 
    {
        return rectangle.getArea();
    }
};

}