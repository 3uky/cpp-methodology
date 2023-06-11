#include <iostream>
#include <memory>


typedef unsigned int uint;

template<class T>
class MySharedPtr
{
private:
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

	uint get_count() const
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
        if(refCount != nullptr)
        {
		    (*refCount)--;

            if (*refCount == 0)	{
                if (ptr != nullptr)
                    delete ptr;
                delete refCount;
            }
        }
	}
};

class T_shared_ptr
{
    public:
        static int test()
        {
			// std shared pointer version
			std::shared_ptr<int> bar (new int(10));
            std::shared_ptr<int> foo;

			std::cout << "MySharedPtr<int> foo; // foo.count == " << foo.use_count() << std::endl << std::endl;

			foo = bar; // copy assignment
            std::cout << "foo = bar;" << " // foo.count " << foo.use_count() << std::endl << std::endl;

            bar = std::move(foo); // move assignment
            //std::cout << "bar = std::move(foo);" << std::format(" bar.count {}; foo.count {}", bar.use_count(), foo.use_count()) std::endl;
			std::cout << "bar = std::move(foo);" << " // bar.count " <<  bar.use_count() << " foo.count " << foo.use_count() << std::endl << std::endl;
            

			// own implementation of shared pointer
            MySharedPtr<int> bar2 (new int(10));
			MySharedPtr<int> foo2;
            
			std::cout << "MySharedPtr<int> foo2;" << " // foo2.count " << foo2.get_count() << std::endl << std::endl;

            foo2 = bar2; // copy assignment
            std::cout << "foo2 = bar2;" << " // foo2.count " << foo2.get_count() << std::endl << std::endl;

            bar2 = std::move(foo2); // move assignment
			std::cout << "bar2 = std::move(foo2); // bar2.count == " << bar2.get_count() << std::endl;
			std::cout << "foo2.count == " << foo2.get_count() << std::endl;
/*
            MySharedPtr<int> a(new int(5)); // parametrized constructor
			std::cout << "a content: " << *a << '\n';

			MySharedPtr<int> b = MySharedPtr(new int(3)); // move constructor
			std::cout << "b content (after move constructor): " << *b << '\n';

*/
            return 0;
        }
};
