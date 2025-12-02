#pragma once
#include <memory>
#include <list>

#include "i_queue.h"

namespace containers
{

class QueueFromVector : public IQueue
{
public:
	QueueFromVector() {}

	void Enqueue(int value) override
	{
		m_queue.push_back(value);
	}

	void Dequeue() override
	{
		m_queue.pop_front();
	}

	int Peek() const override
	{
		return m_queue.front();
	}

	bool IsEmpty() const override
	{
		return m_queue.empty();
	}

	int Size() const override
	{
		return static_cast<int>(m_queue.size());
	}

private:
	std::list<int> m_queue;
};
	
}
