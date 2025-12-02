// https://www.cplusplus.com/doc/tutorial/classes2/
/* The deep copy performed by this copy constructor allocates storage for a new string,
 which is initialized to contain a copy of the original object. In this way, both objects (copy and original)
 have distinct copies of the content stored in different locations. */

#pragma once

#include <string>

namespace cpp_basic_constructs
{

class Constructor
{
public:
    Constructor()
    {
        ptr = new std::string("default");
    }

    Constructor(const std::string& str)
    {
        ptr = new std::string(str);
    }

    ~Constructor()
    {
	    delete ptr;
    }

    // copy constructor:
    // Constructor a;
	// Constructor b = a;
    Constructor(const Constructor& x)
    {
        ptr = new std::string(x.content());
    }

    // move constructor:
    // Constructor b = std::move(a)
    // Constructor b = Constructor("foo");
    Constructor(Constructor&& x)
	{
        ptr = x.ptr;
        x.ptr = nullptr;
    }

    // copy assignment
    // Constructor foo("foo");
    // Constructor bar("bar");
    // foo = bar;
    Constructor& operator=(const Constructor& x)
	{
        delete ptr;                      // delete currently pointed string
        ptr = new std::string(x.content());   // allocate space for new string, and copy value
        return *this;
    }
    
    // move assignment
    // Constructor foo("foo");
    // foo = Constructor("baz");
    Constructor& operator=(Constructor&& x)
	{
        delete ptr;
        ptr = x.ptr;
        x.ptr = nullptr; // necessary for correct delete otherwise it happens twice for same memory and lead to undefined behavior
        return *this;
    }

    Constructor operator+(const Constructor& rhs)
	{
        return Constructor(content() + rhs.content());
    }

    const std::string& content() const
	{
        return *ptr;
    }

private:
    std::string* ptr;
};

}