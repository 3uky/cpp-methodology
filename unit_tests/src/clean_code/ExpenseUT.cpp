#include "gmock/gmock.h"

#include "Expense.h"

namespace clean_code
{

class ReportPrinterMock : public IReportPrinter
{
public:
	void Print(string text) override {
		printedText += text;
	}

	string GetText() {
		return printedText;
	}

private:
	string printedText = "";
};

class ExpenseTest : public testing::Test
{
protected:
	void SetUp()
	{
	}

	ExpenseReport report;
	ReportPrinterMock printer;	
};

TEST_F(ExpenseTest, printEmpty)
{
	// GIVEN / WHEN
	ExpenseReporter reporter(report, printer);

	// THEN
	reporter.PrintReport();
	ASSERT_EQ(printer.GetText(), "Expenses 2/19/2024\n"
		"\n"
		"Meal expenses $0.00\n"
		"Total $0.00");
}

TEST_F(ExpenseTest, printOneDinner)
{
	// GIVEN
	ExpenseReporter reporter(report, printer);

	// WHEN
	DinnerExpense dinner(1678);
	report.AddExpense(dinner);

	// THEN
	reporter.PrintReport();
	ASSERT_EQ(printer.GetText(), "Expenses 2/19/2024\n"
		"\tDinner\t$16.78\n"
		"\n"
		"Meal expenses $16.78\n"
		"Total $16.78");
}

}

