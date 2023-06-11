// https://www.cplusplus.com/doc/tutorial/polymorphism/

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

class T_polymorphism
{
  public:
    static int test()
    {
        // poly with static initialization
        Rectangle rect;
        Triangle trgl;
        Polygon* ppoly1 = &rect;
        Polygon* ppoly2 = &trgl;
        ppoly1->set_values (4, 5);
        ppoly2->set_values (4, 5);
        cout << "static init rect(4x5): " << ppoly1->area() << endl;
        cout << "static init trgl(4x5): " << ppoly2->area() << endl;

        // poly with dynamic initialization
        Polygon* ppoly4 = new Rectangle();
        ppoly4->set_values(3, 3);
        cout << "dynamic init rect(3x3): " << ppoly4->area() << endl;
        delete ppoly4;

        // with use of smart pointers
        std::shared_ptr<Polygon> ppoly3 = std::make_shared<Rectangle>();
        ppoly3->set_values (4, 5);
        cout << "shared ptr rect(4x5): " << rect.area() << endl;


        return 0;
    }
};
