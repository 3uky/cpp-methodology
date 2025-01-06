#pragma once

template <class T>
class MyUniquePtr
{
	T* ptr = nullptr;

public:
	MyUniquePtr() : ptr(nullptr) {}

	MyUniquePtr(T* ptr) : ptr(ptr) {}

	MyUniquePtr(T val) : ptr(new T(val)) {}

	MyUniquePtr(const MyUniquePtr& obj) = delete; // copy constructor is prohibited
	MyUniquePtr& operator=(const MyUniquePtr& obj) = delete; // copy assignment is prohibited

	MyUniquePtr(MyUniquePtr&& dyingObj) // move constructor: MyUniquePtr object = std::move(dyingObject);
	{
		// Transfer ownership of the memory pointed by dyingObj to this object
		ptr = dyingObj.ptr;
		dyingObj.ptr = nullptr; 
	}

	MyUniquePtr& operator=(MyUniquePtr&& dyingObj) // move assignment: object = std::move(dyingObject);
	{
		__cleanup__(); // cleanup any existing data

		// Transfer ownership of the memory pointed by dyingObj to this object
		ptr = dyingObj.ptr;
		dyingObj.ptr = nullptr;

		return *this;
	}

	T* operator->()
	{
		return ptr;
	}

	T& operator*()
	{
		// if(ptr != nullptr)
		return *ptr;
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
