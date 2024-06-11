// https://sourcemaking.com/design_patterns/decorator

// Add behavior to core object at run. Inheritance is not feasible because it is static and applies to an entire class.
// Client can dynamically compose permutations, instead of the architect statically wielding multiple inheritance

#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace design_patterns
{

class I
{
public:
    virtual ~I() {}
    virtual string do_it() = 0;
};

class A : public I // core
{
public:
    ~A() { cout << "A dtor" << '\n'; }
    string do_it() override { return "A"; }
};

class D : public I // decorator
{
public:
    D(I* inner) { m_wrappee = inner; }
    ~D() { delete m_wrappee; }
    string do_it() override { return m_wrappee->do_it(); }
private:
    I* m_wrappee;
};

class X : public D // embellishment
{
public:
    X(I* core) : D(core) {}
    ~X() { cout << "X dtor" << "   "; }
    string do_it() override { return D::do_it() + 'X'; }
};

class Y : public D // embellishment
{
public:
    Y(I* core) : D(core) {}
    ~Y() { cout << "Y dtor" << "   "; }
    string do_it() override { return D::do_it() + 'Y'; }
};

class Z : public D // embellishment
{
public:
    Z(I* core) : D(core) {}
    ~Z() { cout << "Z dtor" << "   "; }
    string do_it() override { return D::do_it() + 'Z'; }
};

}