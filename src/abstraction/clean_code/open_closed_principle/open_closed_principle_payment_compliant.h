# pragma once

#include <iostream>
#include <memory>
#include <vector>

class IPayment 
{
public:
    virtual void processPayment(const int amount) = 0;
};

class CardPayment : public IPayment
{
public:
    void processPayment(const int amount) override {
        std::cout << "Processing card payment of " << amount << std::endl;
    }
};

class CashPayment : public IPayment
{
public:
    void processPayment(const int amount) override {
        std::cout << "Processing cash payment of " << amount << std::endl;
    }
};

class BitcoinPayment : public IPayment
{
public:
    void processPayment(const int amount) override {
        std::cout << "Processing Bitcoin payment of " << amount << std::endl;
    }
};


// Usage example: new payment method doesnt require modification
void checkOut(std::vector<int>& items, std::shared_ptr<IPayment> paymentMethod) 
{
    int total;

    for (const auto& item : items)
        total = total + item;

    paymentMethod->processPayment(total);  // polymorphic payment processing
}