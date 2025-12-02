#pragma once

namespace lsp_compliant_geometry 
{

class Shape 
{
public:
    virtual double getArea() const = 0;
};

class Rectangle : public Shape 
{
public:
    void setWidth(double w) { width = w; }
    void setHeight(double h) { height = h; }

    double getArea() const override {return width * height; }

protected:
    double width, height;
};

class Square : public Shape 
{
public:
    void setSide(double s) { side = s; }

    double getArea() const override { return side * side; }

private:
    double side;
};

}