#include "gmock/gmock.h"

#include "move_copy_semantics.h"

namespace basic_elements
{

TEST(ConstructorTest, ShouldBeInitializedThroughImplicitConstructor)
{
    // GIVEN/WHEN
    Constructor foo;

    // THEN
    EXPECT_EQ(foo.content(), "default");
    
}

TEST(ConstructorTest, ShouldBeInitializedThroughExplicitConstructor)
{
    // GIVEN/WHEN
    Constructor foo("foo");

    // THEN
    EXPECT_EQ(foo.content(), "foo");
}

TEST(ConstructorTest, ShouldBeInitializedThroughCopyConstructor)
{
    // GIVEN
    Constructor foo("foo");

    // WHEN - copy constructor
    Constructor bar = foo;

    // THEN 
    EXPECT_EQ(foo.content(), "foo");
    EXPECT_EQ(bar.content(), "foo");
}


TEST(ConstructorTest, ShouldBeInitializedTroughMoveConstructor)
{
    // GIVEN/WHEN
    Constructor foo = Constructor("foo"); // assignment constructor

    // THEN
    EXPECT_EQ(foo.content(), "foo");
}

TEST(ConstructorTest, ShouldBeInitializedTroughMoveConstructorWithStdMove)
{
    // GIVEN
    Constructor foo("foo");

    // WHEN - move constructor
    Constructor bar = std::move(foo);

    // THEN
    EXPECT_EQ(bar.content(), "foo");
}

TEST(ConstructorTest, ShouldBeInitializedTroughCopyAssignment)
{
    // GIVENT
    Constructor foo("foo");
    Constructor bar("bar");

    // WHEN
    foo = bar; // copy assignment

    // THEN
    EXPECT_EQ(foo.content(), "bar");
    EXPECT_EQ(bar.content(), "bar");
}

TEST(ConstructorTest, ShouldBeInitializedTroughMoveAssignment)
{
    // GIVEN
    Constructor foo("foo");

    // WHEN
    foo = Constructor("baz"); // move assignment

    // THEN
    EXPECT_EQ(foo.content(), "baz");
}

TEST(ConstructorTest, ShouldBeInitializedTroughMoveAssignment2)
{
    // GIVEN
    Constructor foo("foo");
    Constructor baz("baz");

    // WHEN
    foo = std::move(baz); // move assignment

    // THEN
    EXPECT_EQ(foo.content(), "baz");
}


TEST(ConstructorTest, ShouldBeInitializedTroughMoveAssignmentAndOverload)
{
    // GIVEN
    Constructor foo("foo");
    Constructor bar("bar");

    // WHEN
    foo = foo + bar; // overloaded plus operator + move-assignment

    // THEN
    EXPECT_EQ(foo.content(), "foobar");
}

}