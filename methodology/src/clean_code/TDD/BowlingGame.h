// example from clean code with uncle bob ep. 6

#pragma once

#include <array>

namespace clean_code::TDD
{

class Game
{
public:
	void roll(int pins)
	{
		rolls[currentRoll++] = pins;
	}

	int score()
	{
		int score = 0;
		int firstInFrame = 0;
		for (int frame=0; frame < 10; frame++)
		{
			if(isStrike(firstInFrame))
			{
				score += 10 + nextTwoBallsForStrike(firstInFrame);
				firstInFrame++;
			}
			else if(isSpare(firstInFrame))
			{
				score += 10 + nextBallForSpare(firstInFrame);
				firstInFrame += 2;
			}
			else
			{
				score += twoBallsInFrame(firstInFrame);
				firstInFrame += 2;
			}
		}
		return score;
	}

private:
	bool isStrike(int firstInFrame)
	{
		return rolls[firstInFrame] == 10 ? true : false;
	}

	int nextTwoBallsForStrike(int firstInFrame)
	{
		return rolls[firstInFrame + 1] + rolls[firstInFrame + 2];
	}

	bool isSpare(int firstInFrame)
	{
		return rolls[firstInFrame] + rolls[firstInFrame + 1] == 10 ? true : false;
	}

	int nextBallForSpare(int firstInFrame)
	{
		return rolls[firstInFrame + 2];
	}

	int twoBallsInFrame(int firstInFrame)
	{
		return rolls[firstInFrame] + rolls[firstInFrame + 1];
	}

	std::array<int, 21> rolls = {0};
	int currentRoll = 0;
};

}