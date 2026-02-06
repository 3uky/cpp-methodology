#pragma once

namespace cpp_internals
{

template<class T>
class MySharedPtr
{
	T* ptr = nullptr;
	unsigned int* refCount = nullptr;

public:
	MySharedPtr() : ptr(nullptr), refCount(nullptr) {}
	MySharedPtr(T val) : ptr(new T(val)), refCount(new unsigned int(1)) {}
	MySharedPtr(T* ptr) = delete;

	// copy constructor
	// 1. MySharedPtr<int> bar = foo; // copy existing object during initialization
	// 2. MySharedPtr<int> bar(foo); // equivalent to 1.
	// 3. MySharedPtr myFunction() {
	//	  return bar; } // copy when returning from function
	// 4. void myFunction(MySharedPtr in) {} // copy when object is passed to function as value
	//    myFunction(bar);
	
	MySharedPtr(const MySharedPtr& obj) 
	{
		ptr = obj.ptr;
		refCount = obj.refCount;
		if (ptr)
			(*refCount)++;
	}
	
	
	// copy assignment : foo = bar; 
	// assignment is always working with existing aleready initialized object
	MySharedPtr& operator=(const MySharedPtr& obj) 
	{
		Reset();

		ptr = obj.ptr;
		refCount = obj.refCount;
		if (ptr)
			(*refCount)++;

		return *this;
	}

	// move constructor: 
	// MySharedPtr<int> b = std::move(foo);
	// MySharedPtr<int> b = MySharedPtr(3);
	MySharedPtr(MySharedPtr&& dyingObj)
	{
		ptr = dyingObj.ptr; // share the underlying pointer
		refCount = dyingObj.refCount;

		dyingObj.ptr = nullptr;
		dyingObj.refCount = nullptr; // clean the dying object
	}

	// move assignment: 
	// bar = std::move(foo); // move existing object
	// bar = MySharedPtr<int>(99);  // init with temporary object
	MySharedPtr& operator=(MySharedPtr&& dyingObj) 
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
		if (refCount == nullptr)
			return 0;
		else
			return *refCount;

		//return  ? *refCount : 0;
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
		if (ptr)
		{
            if (--(*refCount) == 0)
			{
                delete ptr;
                delete refCount;
            }
            ptr = nullptr;
            refCount = nullptr;
        }
	}
};

}