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
};

}
