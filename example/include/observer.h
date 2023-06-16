#pragma once

#include <list>

using namespace std;

namespace design_patterns
{

class IObserver
{
public:
    virtual void OnNewValueEvent(int value) = 0;
    virtual int GetResult() const = 0;
};

class Subject
{
    std::list<IObserver*> m_views;

public:
    void Register(IObserver* obs)
	{
        m_views.push_back(obs);
    }

    void UnRegister(IObserver* obs)
    {
        m_views.remove(obs);
    }

    void Notify(int value)
    {
        for (auto observer : m_views)
            observer->OnNewValueEvent(value);
    }
};

class DivObserver : public IObserver
{
public:
    DivObserver(int div) : m_div(div) {}

    void OnNewValueEvent(int value) override
    {
        m_result = value / m_div;
        cout << value << " div " << m_div << " is " << m_result << endl;
    }

    int GetResult() const override
    {
        return m_result;
    }

private:
    int m_div;
    int m_result;
};

class ModObserver : public IObserver
{
public:
    ModObserver(int mod) : m_mod(mod) {}

    void OnNewValueEvent(int value) override
    {
        m_result = value % m_mod;
        cout << value << " mod " << m_mod << " is " << value % m_mod << endl;
    }

    int GetResult() const override
    {
        return m_result;
    }

private:
    int m_mod;
    int m_result;
};

}