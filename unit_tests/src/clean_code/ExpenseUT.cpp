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
		" \tDinner\t$16.78\n"
		"\n"
		"Meal expenses $16.78\n"
		"Total $16.78");
}

TEST_F(ExpenseTest, printTwoMeals)
{
	// GIVEN
	ExpenseReporter reporter(report, printer);

	// WHEN
	DinnerExpense dinner(1000);
	BreakfastExpense breakfast(500);

	report.AddExpense(dinner);
	report.AddExpense(breakfast);

	// THEN
	reporter.PrintReport();
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
	ExpenseReporter reporter(report, printer);

	// WHEN
	DinnerExpense dinner(1000);
	BreakfastExpense breakfast(500);
	CarRentalExpense carRental(50000);

	report.AddExpense(dinner);
	report.AddExpense(breakfast);
	report.AddExpense(carRental);

	// THEN
	reporter.PrintReport();
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
	ExpenseReporter reporter(report, printer);

	// WHEN
	BreakfastExpense breakfast(1000);
	BreakfastExpense breakfast2(1001);
	DinnerExpense dinner(5000);
	DinnerExpense dinner2(5001);

	report.AddExpense(breakfast);
	report.AddExpense(breakfast2);
	report.AddExpense(dinner);
	report.AddExpense(dinner2);

	// THEN
	reporter.PrintReport();
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