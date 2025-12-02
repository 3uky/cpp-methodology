#pragma once

namespace containers
{

class IQueue
{
public:
	virtual void Enqueue(int value) = 0; //Enqueue : Inserts a new element at the rear of the queue.
	virtual void Dequeue() = 0; //Dequeue : Removes the front element of the queue and returns it.
	virtual int Peek() const = 0;	//Peek : Returns the front element present in the queue without dequeuing it.
	virtual bool IsEmpty() const = 0; //IsEmpty : Checks if the queue is empty.
	virtual int Size() const = 0; //Size : Returns the total number of elements present in the queue.
};

}
