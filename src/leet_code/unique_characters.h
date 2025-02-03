#pragma once

#include <string>

using namespace std;

namespace leet_code
{

class UniqueCharacters
{
public:
	static std::string GetStringWithUniqueCharacters(std::string& s)
	{
		string temp = { s.at(0) };

		for (auto c : s) 
		{
			if (temp.find(c) == string::npos)
				temp += c;
		}
		return temp;
	}
};

}