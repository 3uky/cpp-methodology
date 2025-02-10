# pragma once

#include <iostream>
#include <memory>
#include <vector>

class Payment
{
public:
    void acceptCash(const int amount) 
    {
        std::cout << "Processing cash payment of " << amount << std::endl;
    }

    void acceptCard(const int amount)
    {
        std::cout << "Processing card payment of " << amount << std::endl;
    }

    void acceptBitcoin(const int amount)
    {
        std::cout << "Processing Bitcoin payment of " << amount << std::endl;
    }
};

enum PaymentMethod 
{
    CARD,
    CASH,
    BITCOIN
};

// Usage example: new payment method require modification of checkOut (and potentialy every place of payment usage)
void checkOut(std::vector<int>& items, PaymentMethod paymentMethod) 
{
    Payment payment;
    int total;

    for (const auto& item : items)
        total = total + item;

    switch(paymentMethod)
    {
        case PaymentMethod::CARD:
            payment.acceptCard(total);
        case PaymentMethod::CASH:          
            payment.acceptCash(total);
        case PaymentMethod::BITCOIN:
            payment.acceptBitcoin(total);
    }
}