#pragma once

#include "QueueFromCArray.h"

namespace containers
{

QueueFromCArray::QueueFromCArray(int size)
{
    m_arr = new int[size];
    m_capacity = size;
    m_front = 0;
    m_rear = -1;
    m_count = 0;
}

// Destructor to free memory allocated to the queue
QueueFromCArray::~QueueFromCArray() 
{
    delete[] m_arr;
}

// Utility function to dequeue the front element
void QueueFromCArray::Dequeue()
{
    // check for queue underflow
    if (IsEmpty())
        throw;

    int x = m_arr[m_front];

    m_front = (m_front + 1) % m_capacity;
    m_count--;
}

// Utility function to add an item to the queue
void QueueFromCArray::Enqueue(int item)
{
    // check for queue overflow
    if (IsFull())
        throw;

    m_rear = (m_rear + 1) % m_capacity;
    m_arr[m_rear] = item;
    m_count++;
}

// Utility function to return the front element of the queue
int QueueFromCArray::Peek() const
{
    if (IsEmpty())
        throw;

    return m_arr[m_front];
}

// Utility function to return the size of the queue
int QueueFromCArray::Size() const
{
    return m_count;
}

// Utility function to check if the queue is empty or not
bool QueueFromCArray::IsEmpty() const
{
    return (Size() == 0);
}

// Utility function to check if the queue is full or not
bool QueueFromCArray::IsFull() 
{
    return (Size() == m_capacity);
}

}
