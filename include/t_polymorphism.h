// https://www.cplusplus.com/doc/tutorial/polymorphism/

#ifndef T_POLYMORPHISM_H
#define T_POLYMORPHISM_H

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
        void set_values (int a, int b)
        { width=a; height=b; }
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

class T_polymorphism
{
  public:
    static int test()
    {
        Rectangle rect;
        Triangle trgl;
        Polygon * ppoly1 = &rect;
        Polygon * ppoly2 = &trgl;
        ppoly1->set_values (4,5);
        ppoly2->set_values (4,5);
        cout << "rect: " << rect.area() << '\n';
        cout << "trgl: " << trgl.area() << '\n';

        // with use of smart pointers
        std::shared_ptr<Polygon> ppoly3 = std::make_shared<Rectangle>();
        ppoly3->set_values (4,5);
        cout << "shared ptr rect: " << rect.area() << '\n';

        return 0;
    }
};

#endif // T_POLYMORPHISM_H
