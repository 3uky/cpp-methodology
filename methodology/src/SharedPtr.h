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

	/*** Copy Semantics ***/
	MySharedPtr(const MySharedPtr& obj) // copy constructor: MySharedPtr<int> bar = foo;
	{
		ptr = obj.ptr; // share the underlying pointer
		refCount = obj.refCount;
		if (obj.ptr != nullptr)
			(*refCount)++; // if the pointer is not null, increment the refCount
	}

	MySharedPtr& operator=(const MySharedPtr& obj) // copy assignment: foo = bar;
	{
		Reset(); // cleanup any existing data

		// Assign incoming object's data to this object
		ptr = obj.ptr; // share the underlying pointer
		refCount = obj.refCount;
		if (obj.ptr != nullptr)
			(*refCount)++; // if the pointer is not null, increment the refCount
		return *this;
	}

	/*** Move Semantics ***/
	MySharedPtr(MySharedPtr&& dyingObj) // move constructor: MySharedPtr<int> b = MySharedPtr(new int(3));
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
		if (refCount == nullptr)
			return 0;
		return *refCount;
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

	~MySharedPtr() // destructor
	{
		Reset();
	}

private:
	void Reset()
	{
		if (refCount != nullptr)
		{
			(*refCount)--;

			if (*refCount == 0) {
				if (ptr != nullptr)
					delete ptr;
				delete refCount;
			}
		}
	}
};

}