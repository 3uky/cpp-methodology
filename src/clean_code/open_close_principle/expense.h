// business logic is separated from presentation
// is possible to add new type of expense so open-close principle is achieved
// it's not prone to new requirements - in other words modification would be needed in old code
//  e.g. add * to print report if expense during one week exceed some limit
//  e.g. add travel expense type similar to meal expense

#include <string>

#include "i_expense.h"

using namespace std;

namespace clean_code::solid
{
    class DinnerExpense : public IExpense
    {
    public:
        DinnerExpense(int amount) : IExpense(amount) {};

    private:
        bool IsOverage() override {
            return m_amount > 5000;
        };
        bool IsMeal() override {
            return true;
        }
        string GetName() override {
            return "Dinner";
        }
    };

    class BreakfastExpense : public IExpense
    {
    public:
        BreakfastExpense(int amount) : IExpense(amount) {};

    private:
        bool IsOverage() override {
            return m_amount > 1000;
        };
        bool IsMeal() override {
            return true;
        }
        string GetName() override {
            return "Breakfast";
        }
    };

    class CarRentalExpense : public IExpense
    {
    public:
        CarRentalExpense(int amount) : IExpense(amount) {};

    private:
        bool IsOverage() override {
            return false;
        };
        bool IsMeal() override {
            return false;
        }
        string GetName() override {
            return "Car Rental";
        }
    };
}