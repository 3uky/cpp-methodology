// business logic is separated from presentation
// is possible to add new type of expense so open-close principle is achieved
// it's not prone to new requirements - in other words modification would be needed in old code
//  e.g. add * to print report if expense during one week exceed some limit
//  e.g. add travel expense type similar to meal expense

#include "i_expense.h"

using namespace std;

namespace clean_code::solid
{

class ExpenseReport
{
public:
    ExpenseReport() : m_total(0), m_mealExpense(0) {}

    void AddExpense(IExpense& expense)
    {
        m_expenses.push_back(expense);
    }

    void TotalUpExpenses()
    {
        for (auto& expense : m_expenses)
            AddToTotal(expense);
    }

    void AddToTotal(IExpense& expense) {
        if (expense.IsMeal())
            m_mealExpense += expense.GetAmount();
        m_total += expense.GetAmount();
    }

    list<reference_wrapper<IExpense>>& GetExpenses()
    {
        return m_expenses;
    }

    int GetMealExpenses()
    {
        return m_mealExpense;
    }

    int GetTotalExpenses()
    {
        return m_total;
    }

private:
    list<reference_wrapper<IExpense>> m_expenses;
    int m_total;
    int m_mealExpense;
};

}