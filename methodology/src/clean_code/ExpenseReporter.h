// business logic is separated from presentation
// is possible to add new type of expense so open-close principle is achieved
// it's not prone to new requirements - in other words modification would be needed in old code
//  e.g. add * to print report if expense during one week exceed some limit
//  e.g. add travel expense type similar to meal expense

#pragma once

#include <string>
#include <format>

#include "ExpenseReport.h"
#include "IReportPrinter.h"

using namespace std;

namespace clean_code
{
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
        }

        void PrintHeader() {
            m_printer.Print(std::format("Expenses {}\n", GetDate()));
        }
        void PrintExpenses() {
            for (IExpense& expense : m_report.GetExpenses())
                PrintExpense(expense);
        }

        void PrintExpense(IExpense& expense)
        {
            m_printer.Print(std::format("{}\t{}\t${:.02F}\n",
                expense.IsOverage() ? "X" : " ",
                expense.GetName(),
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
    };
}