#include "pch.h"
#include "constructor.h"

namespace basic_elements
{
// IMPLICIT CONSTRUCTOR
TEST(ConstructorTest, ShouldBeInitializedThroughImplicitConstructor)
{
    // GIVEN/WHEN
    Constructor foo;

    // THEN
    EXPECT_EQ(foo.content(), "default");
}

// EXPLICIT CONSTRUCTOR
TEST(ConstructorTest, ShouldBeInitializedThroughExplicitConstructor)
{
    // GIVEN/WHEN
    Constructor foo("foo");

    // THEN
    EXPECT_EQ(foo.content(), "foo");
}

// COPY CONSTRUCTOR
TEST(ConstructorTest, ShouldBeInitializedThroughCopyConstructor)
{
    // GIVEN
    Constructor foo("foo"); // default constructor

    // WHEN
    Constructor bar = foo; // copy constructor

    // THEN 
    EXPECT_EQ(foo.content(), "foo");
    EXPECT_EQ(bar.content(), "foo");
}

// COPY ASSIGNMENT
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

// MOVE CONSTRUCTOR
TEST(ConstructorTest, ShouldBeInitializedTroughMoveConstructor)
{
    // GIVEN/WHEN
    Constructor foo = Constructor("foo"); // move constructor

    // THEN
    EXPECT_EQ(foo.content(), "foo");
}

// MOVE ASSIGNMENT
TEST(ConstructorTest, ShouldBeInitializedTroughMoveAssignment)
{
    // GIVEN
    Constructor foo("foo");
    Constructor bar("bar");

    // WHEN
    foo = Constructor("baz"); // move assignment

    // THEN
    EXPECT_EQ(foo.content(), "baz");
}

TEST(ConstructorTest, ShouldBeInitializedTroughMoveAssignmentAndOverload)
{
    // GIVEN
    Constructor foo("foo");
    Constructor bar("bar");

    // WHEN
    foo = foo + bar; // move-assignment + overloaded operator

    // THEN
    EXPECT_EQ(foo.content(), "foobar");
}

}