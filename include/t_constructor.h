#ifndef T_CONSTRUCTOR_H
#define T_CONSTRUCTOR_H

#include <iostream>
#include <string>

using namespace std;

class T_constructor
{
    string* ptr;
public:
    T_constructor (const string& str) : ptr(new string(str)) {}
    ~T_constructor () {delete ptr;}
    // copy constructor:
    T_constructor (const T_constructor& x) : ptr(new string(x.content())) {}
    // copy assignment
    T_constructor& operator= (const T_constructor& x) {
        delete ptr;                      // delete currently pointed string
        ptr = new string (x.content());  // allocate space for new string, and copy
        return *this;
    }
    // move constructor
    T_constructor (T_constructor&& x) : ptr(x.ptr) {x.ptr=nullptr;}
    // move assignment
    T_constructor& operator= (T_constructor&& x) {
        delete ptr;
        ptr = x.ptr;
        x.ptr=nullptr;
        return *this;
    }
    T_constructor operator+(const T_constructor& rhs) {
      return T_constructor(content()+rhs.content());
    }
    const string& content() const {return *ptr;}

    static void test () {
        T_constructor foo("foo");                       // default constructor
        T_constructor bar = foo;                        // copy constructor
        T_constructor baz = T_constructor("rval init"); // move constructor
        foo = bar;                                      // copy assignment
        baz = T_constructor("rval assignment");         // move assignment
        foo = foo + bar;                                // move-assignment
        cout << foo.content() << endl;
    }
};

#endif // T_CONSTRUCTOR_H
