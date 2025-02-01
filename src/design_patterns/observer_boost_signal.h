#pragma once

#include <boost/signals2.hpp>

class ISubject
{
public:
	virtual void Subscribe(std::function<std::string(int eventValue)>) = 0;
};

class Subject : public ISubject
{
    public:
        // Signal with one arguments and a void return value
        boost::signals2::signal<void (int eventValue)> sig;

        void Subscribe(std::function<std::string(int eventValue)> callback) override
        {
            sig.connect(callback);
        }

        void Trigger(int eventValue) {
            sig(eventValue);
        }
};

class IObserver
{
public:
    virtual std::string Handler(int eventValue) = 0;
    
};

class Observer : public IObserver
{
public:
    std::string Handler(int eventValue) const
    {
        return "Event occur with parameter value: " + std::to_string(eventValue);
    }
};