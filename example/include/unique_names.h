#pragma once

#include <set>
#include <vector>
#include <string>

using namespace std;

namespace exercises
{

class UniqueNames
{
public:
	static std::vector<std::string> GetUniqueNames(const std::vector<std::string>& names1, const std::vector<std::string>& names2)
	{
	    std::set<std::string> result;

	    for (auto name : names1)
	    {
	        result.insert(name);
	    }
	    for (auto name : names2)
	    {
	        result.insert(name);
	    }

	    vector<std::string> result_v(result.begin(), result.end());

	    return result_v;
	}
};

}