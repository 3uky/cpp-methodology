#pragma once

#include <iostream>
#include <cmath>

class Shape
{
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape 
{
public:
    Circle(double r) : radius(r) {}
    
    double getArea() const override
    {
        return M_PI * radius * radius;
    }
private:
    double radius;
};

class Rectangle : public Shape
{
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double getArea() const override 
    {
        return width * height;
    }
private:
    double width, height;
};

// new shape added (e.g., Triangle)
class Triangle : public Shape 
{
public:
    Triangle(double b, double h) : base(b), height(h) {}
    
    double getArea() const override 
    {
        return 0.5 * base * height;
    }
private:
    double base, height;
};

// AreaCalculator class (unchanged)
class AreaCalculator 
{
public:
    double calculateArea(const Shape& shape) 
    {
        return shape.getArea();
    }
};