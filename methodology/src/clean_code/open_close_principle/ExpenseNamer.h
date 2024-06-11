#pragma once

#include <string>

#include "Expense.h"

using namespace std;

namespace clean_code
{
    class IExpenseNamer
    {
    public:
        virtual string GetName(IExpense& expense) = 0;
    };

    class ExpenseNamer : public IExpenseNamer
    {
    public:
        ExpenseNamer() {};

        string GetName(IExpense& expense) override
        {
            return expense.GetName();
        }
    };
}