#pragma once

#include <array>
namespace algorithms
{

class MySort
{
public:
	template<typename T>
	void Shuffle(T& a)
	{
		std::random_shuffle(std::begin(a), std::end(a));
	} 
};

}
