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

TEST(DependencyInversionTest, ShouldPrintCharactersInsertedFromKeyboardUntilEOF)
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

}