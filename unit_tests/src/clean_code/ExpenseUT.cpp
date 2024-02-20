#include "gmock/gmock.h"

#include "Expense.h"
#include "ExpenseReport.h"
#include "ExpenseReporter.h"
#include "IReportPrinter.h"

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
	string printedText;
};

class ExpenseTest : public testing::Test
{
protected:

	ExpenseTest() : reporter(report, printer) {}

	void SetUp() {}
	
	ExpenseReport report;
	ReportPrinterMock printer;
	ExpenseReporter reporter;
};

TEST_F(ExpenseTest, printEmpty)
{
	// GIVEN / WHEN
	reporter.PrintReport();

	// THEN
	ASSERT_EQ(printer.GetText(), "Expenses 2/19/2024\n"
		"\n"
		"Meal expenses $0.00\n"
		"Total $0.00");
}

TEST_F(ExpenseTest, printOneDinner)
{
	// GIVEN
	DinnerExpense dinner(1678);

	// WHEN
	report.AddExpense(dinner);

	// THEN
	reporter.PrintReport();
	ASSERT_EQ(printer.GetText(), "Expenses 2/19/2024\n"
		" \tDinner\t$16.78\n"
		"\n"
		"Meal expenses $16.78\n"
		"Total $16.78");
}

TEST_F(ExpenseTest, printTwoMeals)
{
	// GIVEN
	DinnerExpense dinner(1000);
	BreakfastExpense breakfast(500);

	// WHEN
	report.AddExpense(dinner);
	report.AddExpense(breakfast);
	reporter.PrintReport();

	// THEN	
	ASSERT_EQ(printer.GetText(), "Expenses 2/19/2024\n"
		" \tDinner\t$10.00\n"
		" \tBreakfast\t$5.00\n"
		"\n"
		"Meal expenses $15.00\n"
		"Total $15.00");
}

TEST_F(ExpenseTest, printTwoMealsAndCarRental)
{
	// GIVEN
	DinnerExpense dinner(1000);
	BreakfastExpense breakfast(500);
	CarRentalExpense carRental(50000);

	// WHEN
	report.AddExpense(dinner);
	report.AddExpense(breakfast);
	report.AddExpense(carRental);
	reporter.PrintReport();

	// THEN
	ASSERT_EQ(printer.GetText(), "Expenses 2/19/2024\n"
		" \tDinner\t$10.00\n"
		" \tBreakfast\t$5.00\n"
		" \tCar Rental\t$500.00\n"
		"\n"
		"Meal expenses $15.00\n"
		"Total $515.00");
}

TEST_F(ExpenseTest, printOverages)
{
	// GIVEN
	BreakfastExpense breakfast(1000);
	BreakfastExpense breakfast2(1001);
	DinnerExpense dinner(5000);
	DinnerExpense dinner2(5001);

	// WHEN
	report.AddExpense(breakfast);
	report.AddExpense(breakfast2);
	report.AddExpense(dinner);
	report.AddExpense(dinner2);
	reporter.PrintReport();

	// THEN
	ASSERT_EQ(printer.GetText(), "Expenses 2/19/2024\n"
		" \tBreakfast\t$10.00\n"
		"X\tBreakfast\t$10.01\n"
		" \tDinner\t$50.00\n"
		"X\tDinner\t$50.01\n"
		"\n"
		"Meal expenses $120.02\n"
		"Total $120.02");
}

}