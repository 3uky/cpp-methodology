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

class LegacyRectangle
{
  public:
    LegacyRectangle(Coordinate x1, Coordinate y1, Coordinate x2, Coordinate y2) : m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2)
	{
        cout << "LegacyRectangle:  create.  (" << m_x1 << "," << m_y1 << ") => (" << m_x2 << "," << m_y2 << ")" << endl;
    }

    void oldDraw()
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
        oldDraw();
    }
};

}