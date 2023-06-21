#pragma once

#include <vector>

namespace exercises
{

class IFibonacci
{
public:
	virtual std::vector<int> GetSequence(int n) = 0;
	virtual int GetNumber(int nth) = 0;

};
class FibonacciVector : IFibonacci
{
public:
	// nth = 8 -> 0,1,1,2,3,5,8,13
	std::vector<int> GetSequence(int n) override
	{
		if (n == 0)
			return {};

		if (n == 1)
			return { 0 };

		std::vector<int> fib = { 0, 1 };
		for (int i = 2; i < n; i++)
			fib.push_back(fib.at(i - 2) + fib.at(i - 1));
		return fib;
	}

	int GetNumber(int nth) override
	{
		return GetSequence(nth).back();
	}
};

class Fibonacci : IFibonacci
{
public:
	std::vector<int> GetSequence(int n) override
	{
		if (n == 0)
			return {};

		std::vector<int> fib = { 0 };
		int a = 0, b = 1;
		for (int i = 1; i < n; i++)
		{
			auto c = a + b;
			a = b;
			b = c;
			fib.push_back(a);
		}
		return fib;
	}

	int GetNumber(int n) override
	{
		int a = 0, b = 1, c, i;
		if (n == 1)
			return a;
		if (n == 2)
			return b;

		for (i = 2; i < n; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		return b;
	}
};

}