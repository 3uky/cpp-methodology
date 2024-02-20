// business logic is separated from presentation
// is possible to add new type of expense so open-close principle is achieved
// it's not prone to new requirements - in other words modification would be needed in old code
//  e.g. add * to print report if expense during one week exceed some limit
//  e.g. add travel expense type similar to meal expense

#pragma once

#include <string>

using namespace std;

namespace clean_code
{
    class IExpense
    {
    public:
        IExpense(int amount) { m_amount = amount; }
        int GetAmount() { return m_amount; }

        virtual bool IsOverage() = 0;
        virtual bool IsMeal() = 0;
        virtual string GetName() = 0;

    protected:
        int m_amount;
    };
}