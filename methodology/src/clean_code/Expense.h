// bussiness logic is separated from presentation
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
    class Expense
    {
    public:
        Expense(int amount) { m_amount = amount; }

        int GetAmount() { return m_amount; }
        virtual bool IsOverage() = 0;
        virtual bool IsMeal() = 0;
        virtual string GetName() = 0;

    protected:
        int m_amount;
    };
        

    class DinnerExpense : public Expense
    {
    public:
        DinnerExpense(int amount) : Expense(amount) {};

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

        void TotalUpExpenses()
        {
            for (auto& expense : m_expenses)
                AddToTotal(expense); 
        }

        void AddToTotal(Expense& expense) {
            if (expense.IsMeal())
                m_mealExpense += expense.GetAmount();
            m_total += expense.GetAmount();
        }

        list<Expense>& GetExpenses()
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
        list<Expense> m_expenses = {};
        int m_total;
        int m_mealExpense;
    };

    class ExpenseReporter
    {
    public:
        ExpenseReporter(ExpenseReport& report) : m_report(report) {}

        void PrintReport(ReportPrinter& printer)
        {
            m_printer = printer;
            m_report.TotalUpExpenses();
            printExpensesAndTotals();
        }

        ReportPrinter m_printer;

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
            for (Expense& expense : m_report.GetExpenses())
                PrintExpense(expense);
        };

        void PrintExpense(Expense& expense)
        {
            m_printer.Print(std::format("{}\t{}\t{}\n",
                expense.IsOverage() ? "X" : "",
                m_namer.GetName(expense),
                PenniesToDollar(expense.GetAmount()))
            );
        }

        float PenniesToDollar(int amountInPennies)
        {
            return amountInPennies / 100.0;
        }

        int PrintTotals() 
        {
            m_printer.Print(std::format("\nMeal expenses {}", PenniesToDollar(m_report.GetMealExpenses())));
            m_printer.Print(std::format("\nTotal {}", PenniesToDollar(m_report.GetTotalExpenses())));
        }

        string GetDate()
        {
            return "2/19/2024";
        }

        ExpenseReport m_report;
        ExpenseNamer m_namer;
          
    };

    class ReportPrinter
    {
    public:
        void Print(string print)
        {
            cout << print;
        }
    };

    class IExpenseNamer
    {
    public:
        virtual string GetName(Expense& expense) = 0;
    };

    class ExpenseNamer : public IExpenseNamer
    {
    public:
        ExpenseNamer() {};
        
        string GetName(Expense& expense) override
        {
            return expense.GetName();
        }
    };
}