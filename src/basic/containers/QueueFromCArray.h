#pragma once

#include "IQueue.h"

namespace containers
{

#define DEFAUL_QUEUE_SIZE 1000

class QueueFromCArray : public IQueue
{
public:
    QueueFromCArray(int size = DEFAUL_QUEUE_SIZE);
    ~QueueFromCArray();
 
    void Dequeue();
    void Enqueue(int x);
    int Peek() const;
    int Size() const;
    bool IsEmpty() const;
    bool IsFull();

private:
    int* m_arr; // array to store queue elements
    int m_capacity; // maximum capacity of the queue
    int m_front; // front points to the front element in the queue (if any)
    int m_rear; // rear points to the last element in the queue
    int m_count; // current size of the queue
};

}
