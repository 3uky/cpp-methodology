#include "pch.h"
#include "SharedPtr.h"

using namespace std;

namespace cpp_internals
{

TEST(SharedPointerTest, ShouldNotIncrementReferenceDefaultConstrucorWithNullptr)
{
    // GIVEN
    constexpr int expected_reference_count = 0;

    // WHEN
    const MySharedPtr<int> implemented_ptr;

    // THEN
    EXPECT_EQ(implemented_ptr.use_count(), expected_reference_count);
}

TEST(SharedPointerTest, ShouldIncrementReferenceOnParametrizedConstructor)
{
    // GIVEN
    constexpr int expected_reference_count = 1;

    // WHEN
    const MySharedPtr implemented_ptr(10);

    // THEN
    EXPECT_EQ(implemented_ptr.use_count(), expected_reference_count);
}

TEST(SharedPointerTest, ShouldChangeReferenceCountOnCopyConstructor)
{

    // GIVEN
    constexpr int expected_reference_count = 2;

    // WHEN
    const MySharedPtr<int> implemented_ptr_1(10);
    const MySharedPtr<int> implemented_ptr_2 = implemented_ptr_1; // copy constructor

    // THEN
    EXPECT_EQ(implemented_ptr_2.use_count(), expected_reference_count);
}

TEST(SharedPointerTest, ShouldChangeReferenceCountOnMoveConstructor)
{
    // GIVEN
    constexpr int expected_reference_count = 1;

    // WHEN - move constructor
    const MySharedPtr<int> implemented_ptr = MySharedPtr(10);

    // THEN
    EXPECT_EQ(implemented_ptr.use_count(), expected_reference_count);
}

TEST(SharedPointerTest, ShouldChangeReferenceCountOnCopyAssignment)
{
    // GIVEN
    constexpr int expected_reference_count = 2;
    MySharedPtr implemented_ptr_1(21);
    MySharedPtr implemented_ptr_2(22);

    // WHEN - copy assignment
    implemented_ptr_1 = implemented_ptr_2;

    // THEN
    EXPECT_EQ(implemented_ptr_1.use_count(), expected_reference_count);
    EXPECT_EQ(implemented_ptr_2.use_count(), expected_reference_count);
}

TEST(SharedPointerTest, ShouldChangeReferenceCountOnMoveAssignment)
{
    // GIVEN
    MySharedPtr implemented_ptr_1(21);
    MySharedPtr implemented_ptr_2(21);

    // WHEN - move assignment
    implemented_ptr_1 = std::move(implemented_ptr_2);

    // THEN
    EXPECT_EQ(implemented_ptr_1.use_count(), 1);
    EXPECT_EQ(implemented_ptr_2.use_count(), 0);
}


// TEST COMPARING BEHAVIOR WITH SMART POINTER EQUIVALENT
TEST(SharedPointerTest, ShouldHaveSameBehaviorAsSmartPointerOnParametrizedConstructor)
{
    // GIVEN
    const std::shared_ptr<int> reference_ptr = std::make_shared<int>(10);

    // WHEN - move constructor
    const MySharedPtr implemented_ptr(10);

    // THEN
    EXPECT_EQ(implemented_ptr.use_count(), reference_ptr.use_count());
}

TEST(SharedPointerTest, ShouldHaveSameBehaviorAsSmartPointerOnDefaultConstructorWithNullpr)
{
    // GIVEN
    const std::shared_ptr<int> reference_ptr;

    // WHEN
    const MySharedPtr<int> implemented_ptr;

    // THEN
    EXPECT_EQ(implemented_ptr.use_count(), reference_ptr.use_count());
}

TEST(SharedPointerTest, ShouldhaveSameBehaviorAsSmartPointerOnCopyConstructor)
{
    // GIVEN
    const std::shared_ptr<int> reference_ptr_1 = std::make_shared<int>(10);
    const std::shared_ptr<int> reference_ptr_2 = reference_ptr_1;

    // WHEN - copy constructor
    const MySharedPtr<int> implemented_ptr_1(20);
    const MySharedPtr<int> implemented_ptr_2 = implemented_ptr_1; // copy constructor

    // THEN
    EXPECT_EQ(implemented_ptr_2.use_count(), reference_ptr_2.use_count());
}

TEST(SharedPointerTest, ShouldhaveSameBehaviorAsSmartPointerOnMoveConstructor)
{
    // GIVEN
    const std::shared_ptr<int> reference_ptr = std::make_shared<int>(10);

    // WHEN - move constructor
    const MySharedPtr<int> implemented_ptr = MySharedPtr(10);

    // THEN
    EXPECT_EQ(implemented_ptr.use_count(), reference_ptr.use_count());
}

TEST(SharedPointerTest, ShouldHaveSameBehaviorAsSmartPointerOnMoveAssignment)
{
    // GIVEN
    std::shared_ptr<int> reference_ptr_1 = std::make_shared<int>(11);
    std::shared_ptr<int> reference_ptr_2 = std::make_shared<int>(12);

    MySharedPtr implemented_ptr_1(21);
    MySharedPtr implemented_ptr_2(21);

    // WHEN - move assignment
    reference_ptr_1 = std::move(reference_ptr_2);
    implemented_ptr_1 = std::move(implemented_ptr_2);

    // THEN
    EXPECT_EQ(implemented_ptr_1.use_count(), reference_ptr_1.use_count());
    EXPECT_EQ(implemented_ptr_2.use_count(), reference_ptr_2.use_count());
}

TEST(SharedPointerTest, ShouldHaveSameBehaviorAsSmartPointerOnCopyAssignment)
{
    // GIVEN
    std::shared_ptr<int> reference_ptr_1 = std::make_shared<int>(11);
    std::shared_ptr<int> reference_ptr_2 = std::make_shared<int>(21);
    MySharedPtr implemented_ptr_1(21);
    MySharedPtr implemented_ptr_2(22);

    // WHEN - copy assignment
    reference_ptr_1 = reference_ptr_2;
    implemented_ptr_1 = implemented_ptr_2;

    // THEN
    EXPECT_EQ(implemented_ptr_1.use_count(), reference_ptr_1.use_count());
    EXPECT_EQ(implemented_ptr_2.use_count(), reference_ptr_2.use_count());
}

TEST(SharedPointerTest, ShouldResetSharedPointer)
{
    // GIVEN
    std::shared_ptr<int> reference_ptr_1 = std::make_shared<int>(10);
    std::shared_ptr<int> reference_ptr_2 = reference_ptr_1;

    reference_ptr_1.reset();

    EXPECT_EQ(*reference_ptr_2, 10);
    EXPECT_EQ(reference_ptr_2.use_count(), 1);
}
}
