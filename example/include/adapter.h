// https://refactoring.guru/design-patterns/adapter
// Adapter is a structural design pattern that allows objects with incompatible interfaces to collaborate.
// The Adapter pattern lets you create a middle - layer class that serves as a translator between your code and a legacy class, a 3rd - party class or any other class with a weird interface.
// When the adapter receives a call to any of its methods, it translates parameters to the appropriate format and then directs the call to one or several methods of the wrapped object.

#pragma once

#include <iostream>

typedef int Coordinate;
typedef int Dimension;

using namespace std;

namespace design_patterns
{

class IRectangle
{
public:
    virtual void Draw() = 0;
};

class ILegacyRectangle
{
public:
    virtual void OldDraw() = 0;
};

class LegacyRectangle : ILegacyRectangle
{
  public:
    LegacyRectangle(Coordinate x1, Coordinate y1, Coordinate x2, Coordinate y2) : m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2)
	{
        cout << "LegacyRectangle:  create.  (" << m_x1 << "," << m_y1 << ") => (" << m_x2 << "," << m_y2 << ")" << endl;
    }

    void OldDraw()
	{
        cout << "LegacyRectangle:  oldDraw.  (" << m_x1 << "," << m_y1 << ") => (" << m_x2 << "," << m_y2 << ")" << endl;
    }

  private:
    Coordinate m_x1;
    Coordinate m_y1;
    Coordinate m_x2;
    Coordinate m_y2;
};

// Adapter wrapper
class RectangleAdapter: public IRectangle, private LegacyRectangle
{
  public:
    RectangleAdapter(Coordinate x, Coordinate y, Dimension w, Dimension h) : LegacyRectangle(x, y, x + w, y + h)
	{
        cout << "RectangleAdapter: create.  (" << x << "," << y << "), width = " << w << ", height = " << h << endl;
    }

    void Draw() override
    {
        cout << "RectangleAdapter: draw." << endl;
        OldDraw();
    }
};

}