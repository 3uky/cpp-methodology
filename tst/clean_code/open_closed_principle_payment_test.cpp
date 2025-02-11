#include <gtest/gtest.h>
#include <memory>
#include <iostream>

#include "open_closed_principle_payment_violation.h"
#include "open_closed_principle_payment_compliant.h"

// new payment method require modification of switch (and potentialy every usage)
TEST(OpenClosedPrincipleTest, TestPrincipleViolationPayment)
 {
    // GIVEN
    int total = 50;
    auto paymentMethod = PaymentMethod::CARD;
    Payment payment;
    testing::internal::CaptureStdout();  

    // WHEN
    switch(paymentMethod)
    {
        case PaymentMethod::CARD:
            payment.acceptCard(total);
            break;
        case PaymentMethod::CASH:     
            payment.acceptCash(total);
            break;
        case PaymentMethod::BITCOIN:
            payment.acceptBitcoin(total);
            break;
    }

    // THEN
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "Processing card payment of 50\n");
}

// new payment method doesnt require modification of usage
TEST(OpenClosedPrincipleTest, TestPrincipleComplyPayment) 
{
    // GIVEN
    int totalPrice = 50;
    std::unique_ptr<IPayment> paymentMethod = std::make_unique<CardPayment>();
    testing::internal::CaptureStdout();   

    // WHEN
    paymentMethod->processPayment(totalPrice);  

    // THEN
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "Processing card payment of 50\n");
}