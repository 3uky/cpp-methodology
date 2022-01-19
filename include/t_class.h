#ifndef T_CLASS_H
#define T_CLASS_H

#include <iostream>
using namespace std;

namespace t_class {
    class Rectangle {
      int width, height;
    public:
      Rectangle(int x, int y) : width(x), height(y) {}
      int area(void) { return width * height; }
    };
}

class Parent
{
public:
    Parent() {
        cout << "Constructor: Inside base class" << endl;
    }
    ~Parent() {
        cout << "Destructor: Inside base class" << endl;
    }
};

class Child : public Parent
{
public:
    Child() {
        cout << "Constructor: Inside sub class" << endl;
    }
    ~Child() {
        cout << "Destructor: Inside sub class" << endl;
    }
};

class T_class
{
public:
    static void test() {
        test_constructor_destructor_order();
    }

    static int test_new() {
        t_class::Rectangle obj (3, 4);
        t_class::Rectangle * foo, * bar, * baz;
        foo = &obj;
        bar = new t_class::Rectangle (5, 6);
        baz = new t_class::Rectangle[2] { {2,5}, {3,6} };
        cout << "obj's area: " << obj.area() << '\n';
        cout << "*foo's area: " << foo->area() << '\n';
        cout << "*bar's area: " << bar->area() << '\n';
        cout << "baz[0]'s area:" << baz[0].area() << '\n';
        cout << "baz[1]'s area:" << baz[1].area() << '\n';
        delete bar;
        delete[] baz;
        return 0;
    }

    static void test_constructor_destructor_order() {
        Child obj;
    }
};

#endif // T_CLASS_H
