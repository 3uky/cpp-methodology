#include <iostream>
#include <exception>

template <class T>
class MyUniquePtr
{
private:
	T * ptr = nullptr;

public:
	MyUniquePtr() : ptr(nullptr) {}

	MyUniquePtr(T* ptr) : ptr(ptr) {}

	MyUniquePtr(const MyUniquePtr& obj) = delete; // copy constructor is deleted
	MyUniquePtr& operator=(const MyUniquePtr & obj) = delete; // copy assignment is deleted

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

	T* operator->() // deferencing arrow operator
	{
		return this->ptr;
	}

	T& operator*()
	{
		return *(this->ptr);
	}

	~MyUniquePtr() // destructor
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

class T_unique_ptr
{
    public:
        static int test()
        {

            MyUniquePtr<int> a(new int(5)); // parametrized constructor
			std::cout << "a content: " << *a << '\n';

			MyUniquePtr<int> b = MyUniquePtr(new int(3)); // move constructor
			std::cout << "b content (after move constructor): " << *b << '\n';

			b = std::move(a); // move assigned
			std::cout << "b content (after move assigning): " << *b << '\n';
            
			// b = a; // copy assignment is deleted
			// MyUniquePtr<int> c = b; // copy constructor is deleted
            return 0;
        }
};

