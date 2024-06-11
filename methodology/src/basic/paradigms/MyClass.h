#pragma once

#include <iostream>

using namespace std;

namespace basic_paradigm
{

class MyClass
{
public:
    MyClass(int x) : var(x) {}

    int get()
    {
        return var;
    }

private:
    int var;
};

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

}