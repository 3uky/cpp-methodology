#include <iostream>

// clients should not be forced to depend on interfaces they do not use

class Worker 
{
public:
    virtual void work() = 0;
    virtual void eat() = 0;
    virtual void sleep() = 0;
};

class Human : public Worker 
{
public:
    void work() override { std::cout << "Human working." << std::endl; }
    void eat() override { std::cout << "Human eating." << std::endl; }
    void sleep() override { std::cout << "Human sleeping." << std::endl; }
};

// A robot doesn't need to eat or sleep, but we are forced to implement it
class Robot : public Worker 
{
public:
    void work() override { std::cout << "Robot working." << std::endl; }
    void eat() override { std::cout << "Robot doesn't eat." << std::endl; }
    void sleep() override { std::cout << "Robot doesn't sleep." << std::endl; }
};
