#pragma once

#include <string>
#include <unordered_set>

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
	static std::string GetLongestUniqueSubstring(std::string& s)
	{
		std::unordered_set<char> seen;
		int start = 0, left = 0, right =0, maxLength = 0;

		while (right < s.size()) 
		{
			if(seen.count(s[right]))
			{
				seen.erase(s[left]);
				left++;
			}
			else
			{
				seen.insert(s[right]);
				
				if (right - left + 1 > maxLength) 
				{
                	maxLength = right - left + 1;
                	start = left;
            	}

				right++;
			}
		}		
		return s.substr(start, maxLength);
	}
};

}