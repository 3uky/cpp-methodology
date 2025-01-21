#pragma once

namespace cpp_internals
{

template<class T>
class MySharedPtr
{
	T* ptr = nullptr;
	unsigned int* refCount = nullptr;

public:
	MySharedPtr() : ptr(nullptr), refCount(new unsigned int(0)) // default constructor
	{
	}

	MySharedPtr(T val) : ptr(new T(val)), refCount(new unsigned int(1)) // constructor
	{
	}

	MySharedPtr(T* ptr) : ptr(ptr), refCount(new unsigned int(1)) // constructor
	{
	}

	// copy constructor: MySharedPtr<int> bar = foo;
	MySharedPtr(const MySharedPtr& obj) 
	{
		ptr = obj.ptr;
		refCount = obj.refCount;
		if (ptr)
			(*refCount)++;
	}
	
	// copy assignment: foo = bar;
	MySharedPtr& operator=(const MySharedPtr& obj) 
	{
		Reset();

		ptr = obj.ptr;
		refCount = obj.refCount;
		if (ptr)
			(*refCount)++;

		return *this;
	}

	// move constructor: MySharedPtr<int> b = MySharedPtr(new int(3));
	MySharedPtr(MySharedPtr&& dyingObj)
	{
		ptr = dyingObj.ptr; // share the underlying pointer
		refCount = dyingObj.refCount;

		dyingObj.ptr = nullptr;
		dyingObj.refCount = nullptr; // clean the dying object
	}

	MySharedPtr& operator=(MySharedPtr&& dyingObj) // move assignment: bar = std::move(foo);
	{
		Reset(); // cleanup any existing data

		ptr = dyingObj.ptr; // share the underlying pointer
		refCount = dyingObj.refCount;

		dyingObj.ptr = nullptr; // clean the dying object
		dyingObj.refCount = nullptr;
		return *this;
	}

	unsigned int use_count() const
	{
		return refCount ? *refCount : 0;
	}

	T* get() const
	{
		return ptr;
	}

	T* operator->() const
	{
		return ptr;
	}

	T& operator*() const
	{
		return *ptr;
	}

	~MySharedPtr()
	{
		Reset();
	}

private:
	void Reset()
	{
		if (refCount && --(*refCount) == 0)
		{
			delete ptr;
			delete refCount;
		}
		ptr = nullptr;
		refCount = nullptr;
	}
};

}