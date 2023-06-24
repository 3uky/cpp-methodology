#pragma once

template <class T>
class MyUniquePtr
{
	T* ptr = nullptr;

public:
	MyUniquePtr() : ptr(nullptr) {}

	MyUniquePtr(T* ptr) : ptr(ptr) {}

	MyUniquePtr(const MyUniquePtr& obj) = delete; // copy constructor
	MyUniquePtr& operator=(const MyUniquePtr& obj) = delete; // copy assignment

	MyUniquePtr(MyUniquePtr&& dyingObj) // move constructor
	{
		// Transfer ownership of the memory pointed by dyingObj to this object
		this->ptr = dyingObj.ptr;
		dyingObj.ptr = nullptr; 
	}

	void operator=(MyUniquePtr&& dyingObj) // move assignment
	{
		__cleanup__(); // cleanup any existing data

		// Transfer ownership of the memory pointed by dyingObj to this object
		this->ptr = dyingObj.ptr;
		dyingObj.ptr = nullptr;
	}

	T* operator->()
	{
		return this->ptr;
	}

	T& operator*()
	{
		// if(ptr != nullptr)
		return *(this->ptr);
	}

	~MyUniquePtr()
	{
		__cleanup__();
	}

private:
	void __cleanup__()
	{
		if (ptr != nullptr)
			delete ptr;
	}
};
