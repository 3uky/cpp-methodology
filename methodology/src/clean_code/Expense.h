// business logic is separated from presentation
// is possible to add new type of expense so open-close principle is achieved
// it's not prone to new requirements - in other words modification would be needed in old code
//  e.g. add * to print report if expense during one week exceed some limit
//  e.g. add travel expense type similar to meal expense

#pragma once

#include <iostream>
#include <list>
#include <string>
#include <format>

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

        list<std::reference_wrapper<IExpense>>& GetExpenses()
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
        list<std::reference_wrapper<IExpense>> m_expenses;
        int m_total;
        int m_mealExpense;
    };

    class IReportPrinter
    {
    public:
        virtual void Print(string print) = 0;
    };

    class ReportPrinter : public IReportPrinter
    {
    public:
        void Print(string print) override
        {
            cout << print;
        }
    };

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

    class ExpenseReporter
    {
    public:
        ExpenseReporter(ExpenseReport& report, IReportPrinter& printer) : m_report(report), m_printer(printer) {}

        void PrintReport()
        {            
            m_report.TotalUpExpenses();
            printExpensesAndTotals();
        }

    private:
        void printExpensesAndTotals() {
            PrintHeader();
            PrintExpenses();
            PrintTotals();
        };

        void PrintHeader() {
            m_printer.Print(std::format("Expenses {}\n", GetDate()));
        }
        void PrintExpenses() {
            for (IExpense& expense : m_report.GetExpenses())
                PrintExpense(expense);
        };

        void PrintExpense(IExpense& expense)
        {
            m_printer.Print(std::format("{}\t{}\t${:.02F}\n",
                expense.IsOverage() ? "X" : "",
                m_namer.GetName(expense),
                PenniesToDollar(expense.GetAmount()))
            );
        }

        double PenniesToDollar(int amountInPennies)
        {
            return amountInPennies / 100.0;
        }

        void PrintTotals() 
        {
            m_printer.Print(std::format("\nMeal expenses ${:.02F}", PenniesToDollar(m_report.GetMealExpenses())));
            m_printer.Print(std::format("\nTotal ${:.02F}", PenniesToDollar(m_report.GetTotalExpenses())));
        }

        string GetDate()
        {
            return "2/19/2024";
        }

        ExpenseReport& m_report;
        IReportPrinter& m_printer;
        ExpenseNamer m_namer;
    };

    

}