#pragma once

#include <array>
#include <random>

namespace algorithms
{

class MySort
{
public:
	template<typename T>
	void Shuffle(T& a)
	{
		std::random_device rd;
		std::mt19937 g(rd());

		std::shuffle(std::begin(a), std::end(a), g);
	} 
};

}
