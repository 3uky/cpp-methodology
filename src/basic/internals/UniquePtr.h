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

	// move constructor: MyUniquePtr object = std::move(dyingObject);
	MyUniquePtr(MyUniquePtr&& dyingObj)
	{
		ptr = dyingObj.ptr;
		dyingObj.ptr = nullptr; 
	}

	// move assignment: object = std::move(dyingObject);
	MyUniquePtr& operator=(MyUniquePtr&& dyingObj)
	{
		Reset();

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
		return *ptr;
	}

	~MyUniquePtr()
	{
		Reset();
	}

private:
	void Reset()
	{
		delete ptr;
	}
};
