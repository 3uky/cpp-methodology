// https://www.codespeedy.com/static_cast-and-dynamic_cast-in-cpp/
// In C++, a derived class reference/pointer can be treated as a base class pointer.
// This is called upcasting in C++. The opposite process, called downcasting, is not allowed in C++.
// So, dynamic_cast is used to promote safe downcasting in C++.
// It is always performed with polymorphic classes having at least one virtual function inside the class.

#pragma once

namespace basic_elements
{

enum ObjectType
{
    BaseObject,
    DerivedObject
};

class Base
{
public:
    virtual ObjectType GetType()
	{
        return BaseObject;
    }
};

class Derived : public Base
{
public:
    ObjectType GetType() override
	{
        return DerivedObject;
    }
};

class A
{
};

class B
{
public:
    // conversion from C (constructor): is prohibited with explicit
    explicit B(const A& x) {}

	// conversion from A (assignment):
    B& operator= (const A& x)
    {
	    return *this;
    }

	// conversion to A (type-cast operator)
    operator A()
    {
	    return A();
    }
};

class C
{
public:
    operator B()
    {
        // ConversionFunction(o_C); // impossible conversion because: class B - explicit B(const A& x) {}
        //return B(); 
    }
};

void ConversionFunction(B x) 
{	
}

}