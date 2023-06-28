#pragma once
#include <memory>
#include <list>

namespace containers
{

class QueueElement
{
public:
	QueueElement(int value) : data(value) {}

	int data;
	std::unique_ptr<QueueElement> next = nullptr;
};

class IQueue
{
public:
	virtual void Enqueue(int value) = 0; //Enqueue : Inserts a new element at the rear of the queue.
	virtual void Dequeue() = 0; //Dequeue : Removes the front element of the queue and returns it.
	virtual int Peek() const = 0;	//Peek : Returns the front element present in the queue without dequeuing it.
	virtual bool IsEmpty() const = 0; //IsEmpty : Checks if the queue is empty.
	virtual int Size() const = 0; //Size : Returns the total number of elements present in the queue.
};

class Queue : public IQueue
{
public:
	Queue() {};
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