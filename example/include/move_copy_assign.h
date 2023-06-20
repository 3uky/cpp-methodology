#pragma once

#include <string>

using namespace std;

class Constructor
{
public:
    Constructor()
    {
        ptr = new string("default");
    }

    Constructor(const string& str)
    {
        ptr = new string(str);
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
        ptr = new string(x.content());
    }

    // move constructor:
    // Constructor b = std::move(a)
    // Constructor b = Constructor("foo");
    Constructor(Constructor&& x)
	{
        ptr = x.ptr;
        x.ptr=nullptr;
    }

    // copy assignment
    Constructor& operator= (const Constructor& x)
	{
        delete ptr;                      // delete currently pointed string
        ptr = new string(x.content());   // allocate space for new string, and copy
        return *this;
    }
    
    // move assignment
    Constructor& operator= (Constructor&& x)
	{
        delete ptr;
        ptr = x.ptr;
        x.ptr = nullptr;
        return *this;
    }

    Constructor operator+(const Constructor& rhs)
	{
        return Constructor(content() + rhs.content());
    }

    const string& content() const
	{
        return *ptr;
    }

private:
    string* ptr;
};
