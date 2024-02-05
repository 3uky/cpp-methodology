#include "gmock/gmock.h"

#include "DependencyInversion.h"

using ::testing::Return;
using ::testing::_;

namespace solid
{

class MockKeyboard : public Keyboard {
public:
    MOCK_METHOD(int, Getchar, (), (override));
};

class MockPrinter : public Printer {
public:
    MOCK_METHOD(void, Putchar, (int c), (override));
};

TEST(DependencyInversionTest, PrinterShouldPrintUntilEOF)
{
    // GIVEN
    MockKeyboard keyboard;
	MockPrinter printer;
    Worker worker;    

    // WHEN
	EXPECT_CALL(keyboard, Getchar())
        .Times(2)
        .WillOnce(Return('c'))
        .WillOnce(Return(EOF));
    EXPECT_CALL(printer, Putchar(_))
        .Times(1);

    // THEN
    worker.Copy(keyboard, printer);
}

TEST(DependencyInversionTest, PrinterShouldPrintCharactersInsertedFromKeyboard)
{
    // GIVEN
    MockKeyboard keyboard;
    Printer printer;
    Worker worker;

    // WHEN
    EXPECT_CALL(keyboard, Getchar())
        .Times(6)
        .WillOnce(Return('h'))
        .WillOnce(Return('e'))
        .WillOnce(Return('l'))
        .WillOnce(Return('l'))
        .WillOnce(Return('o'))
        .WillOnce(Return(EOF));

    // THEN
    testing::internal::CaptureStdout();
    worker.Copy(keyboard, printer);
    ASSERT_EQ("hello", testing::internal::GetCapturedStdout());
}

}