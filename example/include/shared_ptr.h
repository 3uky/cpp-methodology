#pragma once

namespace cpp_internals
{

typedef unsigned int uint;

template<class T>
class MySharedPtr
{
	T* ptr = nullptr;
	uint* refCount = nullptr;

public:
	MySharedPtr() : ptr(nullptr), refCount(new uint(0)) // default constructor
	{
	}

	MySharedPtr(T* ptr) : ptr(ptr), refCount(new uint(1)) // constructor
	{
	}

	/*** Copy Semantics ***/
	MySharedPtr(const MySharedPtr& obj) // copy constructor: MySharedPtr<int> bar = foo;
	{
		this->ptr = obj.ptr; // share the underlying pointer
		this->refCount = obj.refCount;
		if (obj.ptr != nullptr)
			(*this->refCount)++; // if the pointer is not null, increment the refCount
	}

	MySharedPtr& operator=(const MySharedPtr& obj) // copy assignment: foo = bar;
	{
		__cleanup__(); // cleanup any existing data

		// Assign incoming object's data to this object
		this->ptr = obj.ptr; // share the underlying pointer
		this->refCount = obj.refCount;
		if (obj.ptr != nullptr)
			(*this->refCount)++; // if the pointer is not null, increment the refCount
		return *this;
	}

	/*** Move Semantics ***/
	MySharedPtr(MySharedPtr&& dyingObj) // move constructor: MySharedPtr<int> b = MySharedPtr(new int(3));
	{
		this->ptr = dyingObj.ptr; // share the underlying pointer
		this->refCount = dyingObj.refCount;

		dyingObj.ptr = nullptr;
		dyingObj.refCount = nullptr; // clean the dying object
	}

	MySharedPtr& operator=(MySharedPtr&& dyingObj) // move assignment: bar = std::move(foo);
	{
		__cleanup__(); // cleanup any existing data

		this->ptr = dyingObj.ptr; // share the underlying pointer
		this->refCount = dyingObj.refCount;

		dyingObj.ptr = nullptr; // clean the dying object
		dyingObj.refCount = nullptr;
		return *this;
	}

	uint use_count() const
	{
		if (this->refCount == nullptr)
			return 0;
		return *refCount; // *this->refCount
	}

	T* get() const
	{
		return this->ptr;
	}

	T* operator->() const
	{
		return this->ptr;
	}

	T& operator*() const
	{
		return *(this->ptr);
	}

	~MySharedPtr() // destructor
	{
		__cleanup__();
	}

private:
	void __cleanup__()
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