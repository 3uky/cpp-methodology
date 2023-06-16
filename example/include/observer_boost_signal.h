#pragma once

#include <boost/signals2.hpp>

class ISubject
{
public:
	virtual void Subscribe(std::function<std::string()>) = 0;
};

class Subject : public ISubject
{
    public:
        // Signal with no arguments and a void return value
        boost::signals2::signal<void ()> sig;

        void Subscribe(std::function<std::string()> callback) override
        {
            sig.connect(callback);
        }

        void Trigger() {
            sig();
        }
};

class IObserver
{
public:
    virtual std::string Handler() = 0;
    
};
class Observer : public IObserver
{
public:
    std::string Handler() const
    {
        return "Hello, World!";
    }
};