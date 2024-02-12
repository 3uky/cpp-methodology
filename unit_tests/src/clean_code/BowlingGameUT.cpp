#include "gmock/gmock.h"

#include "BowlingGame.h"

namespace clean_code
{

class BowlingGameTest : public testing::Test
{
protected:
	void SetUp()
	{
	}

	void rollMany(int n, int pins)
	{
		for (int i = 0; i < n; i++)
			g.roll(pins); 
	}

	void rollSpare()
	{
		g.roll(5);
		g.roll(5);
	}

	Game g;
};

TEST_F(BowlingGameTest, gutterGame)
{
	rollMany(20, 0);
	ASSERT_EQ(g.score(), 0);
}

TEST_F(BowlingGameTest, allOnes)
{
	rollMany(20, 1);
	ASSERT_EQ(g.score(), 20);
}

TEST_F(BowlingGameTest, oneSpare)
{
	rollSpare();
	g.roll(3);
	rollMany(17, 0);
	ASSERT_EQ(g.score(), 16);
}

TEST_F(BowlingGameTest, oneStrike)
{
	g.roll(10);
	g.roll(3);
	g.roll(4);
	rollMany(16, 0);
	ASSERT_EQ(g.score(), 24);
}

TEST_F(BowlingGameTest, perfectGame)
{
	rollMany(12, 10);
	ASSERT_EQ(g.score(), 300);
}

TEST_F(BowlingGameTest, spareInLastFrame)
{
	rollMany(19, 0);
	g.roll(10);
	g.roll(1);
	ASSERT_EQ(g.score(), 11);
}

}

