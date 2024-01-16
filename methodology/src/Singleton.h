#pragma once

#include <memory>

using namespace std;

namespace design_patterns
{

class Singleton
{
public:
    int GetValue() const {
        return m_value;
    }

    void SetValue(int v) {
        m_value = v;
    }

protected:
	int m_value = 0;
};

class SingletonPtr : public Singleton
{
public:
	~SingletonPtr() { delete s_instance; }

    static SingletonPtr* instance()
	{
        if(!s_instance)
	        s_instance = new SingletonPtr;
        return s_instance;
    }

protected:
    SingletonPtr() {};

private:
	static SingletonPtr* s_instance;
};


// Allocating and initializing GlobalClass's
// static data member.  The pointer is being
// allocated - not the object inself.
SingletonPtr* SingletonPtr::s_instance = 0;


class SingletonRef : public Singleton
{
public:
    static SingletonRef& instance()
	{
        static SingletonRef s_instance;
        return s_instance;
    }
};


class SingletonShared : public Singleton
{
public:
    static shared_ptr<SingletonShared> instance()
	{
        static shared_ptr<SingletonShared> shared_instance = std::make_shared<SingletonShared>();
        return shared_instance;
    }
};

class SingletonUnique : public Singleton
{
public:
    static unique_ptr<SingletonUnique>& instance()
    {
        static unique_ptr<SingletonUnique> unique_instance = std::make_unique<SingletonUnique>();
        return unique_instance;
    }
};

}