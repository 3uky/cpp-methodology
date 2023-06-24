#pragma once

template<typename T>
class ILinkedList
{
public:
	virtual void Insert(T value) = 0;
	virtual void Remove(int pos) = 0;
	virtual T Get(unsigned int pos) const = 0;
	virtual T Front() const = 0;
	virtual void Swap(unsigned int pos_1, unsigned int pos_2) = 0;
	virtual void Reverse() = 0;
	virtual unsigned int Count() const = 0;
};
