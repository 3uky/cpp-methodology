#pragma once

#include <string>

namespace exercises
{

class UtilString
{
public:
	static void Reverse(std::string& str)
	{
		std::reverse(str.begin(), str.end());
	}

	static void ReverseC(char str[])
	{
		const auto length = strlen(str) - 1;

		for(int i = 0; i < length / 2; i++)
		{
			char c = str[length - i];
			str[length - i] = str[i];
			str[i] = c;
		}
	}
};

}
