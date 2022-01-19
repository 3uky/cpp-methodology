// https://www.codespeedy.com/static_cast-and-dynamic_cast-in-cpp/
// In C++, a derived class reference/pointer can be treated as a base class pointer.
// This is called upcasting in C++. The opposite process, called downcasting, is not allowed in C++.
// So, dynamic_cast is used to promote safe downcasting in C++.
// It is always performed with polymorphic classes having at least one virtual function inside the class.
#ifndef T_TYPE_CONVERSIONS_H
#define T_TYPE_CONVERSIONS_H

#include<iostream>
using namespace std;

class base
{
  public:
    virtual void fn() {
        cout << "base" << endl;
    }
};

class derived : public base
{
  public:
    void fn() {
        cout << "derived" << endl;
    }
};


class A {};

class B {
public:
  // conversion from A (constructor): is prohibited with explicit
  explicit B (const A& x) {}
  // conversion from A (assignment):
  B& operator= (const A& x) {return *this;}
  // conversion to A (type-cast operator)
  operator A() {return A();}
};

void fn (B x) {}

class T_type_conversions
{
public:
    static void test() {
        test_dynamic();
        //test_explicit();
    }
    static void test_dynamic() {
        base *b = new derived;
        derived *d;
        //d=b; //base class pointer assigned to the derived class pointer
        d = dynamic_cast<derived*>(b);      //to promote downcasting
        d->fn();
    }

    static void test_explicit() {
        A foo;
        B bar (foo);
        bar = foo;
        foo = bar;

        // fn (foo);  // not allowed for explicit ctor.
        fn (bar);
    }
};

#endif // T_TYPE_CONVERSIONS_H
