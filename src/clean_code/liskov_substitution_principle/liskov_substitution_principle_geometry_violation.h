#pragma once

namespace lsp_violated_geometry 
{

class Rectangle 
{
public:
    virtual void setWidth(double w) { width = w; }
    virtual void setHeight(double h) { height = h; }
    virtual double getArea() const { return width * height; }

protected:
    double width, height;
};

// In a square, width == height
class Square : public Rectangle 
{
public:
    void setWidth(double w) override 
    {
        width = w;
        height = w; 
    }

    void setHeight(double h) override 
    {
        height = h;
        width = h;
    }
};

}