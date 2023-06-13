// https://www.cplusplus.com/doc/tutorial/classes2/

#pragma once

// copy constructor: deep copy
#include <iostream>
#include <string>
using namespace std;

class Example5 {
    string* ptr;
public:
    Example5 (const string& str) : ptr(new string(str)) {}
    ~Example5 () {delete ptr;}
    // copy constructor:
    Example5 (const Example5& x) : ptr(new string(x.content())) {}
    // access content:
    const string& content() const {return *ptr;}

    Example5& operator= (const Example5& x) {   // assignment operator
        delete ptr;                      // delete currently pointed string
        ptr = new string (x.content());  // allocate space for new string, and copy
        return *this;
    }
};

class T_copy
{
public:
    static int test () {
        Example5 foo ("Example");
        Example5 bar = foo;         // copy constructor is called
        cout << "bar's content: " << bar.content() << '\n';

        Example5 baz ("baz");
        baz = bar;                  // assignment operator is called
        cout << "baz's content: " << baz.content() << '\n';

        return 0;
    }
};

/* The deep copy performed by this copy constructor allocates storage for a new string,
 which is initialized to contain a copy of the original object. In this way, both objects (copy and original)
 have distinct copies of the content stored in different locations. */
