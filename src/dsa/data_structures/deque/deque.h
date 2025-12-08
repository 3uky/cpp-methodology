// C++ Program to Implement Double Ended Queue
#include <iostream>
#include <stdexcept>

using namespace std;

// Template class for a doubly linked list based Deque
template <typename T> class Deque {
private:
    // Node structure representing each element in the Deque
    struct Node 
    {
        T data;
        Node* prev;
        Node* next;

        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int size;

public:
    Deque() : front(nullptr), rear(nullptr), size(0) {}

    ~Deque()
    {
        while (!is_empty()) 
            pop_front();
    }

    void push_front(T value)
    {
        Node* new_node = new Node(value);
        
        if (is_empty()) 
            front = rear = new_node;
        else 
        {
            new_node->next = front;
            front->prev = new_node;
            front = new_node;
        }
        size++;
    }

    void push_back(T value)
    {
        Node* new_node = new Node(value);
        if (is_empty()) 
            front = rear = new_node;
        else
        {
            new_node->prev = rear;
            rear->next = new_node;
            rear = new_node;
        }
        size++;
    }

    void pop_front()
    {
        if (is_empty()) 
            throw runtime_error("Deque is empty");
        
        Node* temp = front;
        
        front = front->next;
        if (front == nullptr) 
            rear = nullptr;
        else
            front->prev = nullptr;

        delete temp;
        size--;
    }

    void pop_back()
    {
        if (is_empty())
            throw runtime_error("Deque is empty");

        Node* temp = rear;
        rear = rear->prev;
        if (rear == nullptr) 
            front = nullptr;
        else
            rear->next = nullptr;

        delete temp;
        size--;
    }

    T get_front()
    {
        if (is_empty())
            throw runtime_error("Deque is empty");

        return front->data;
    }

    T get_rear()
    {
        if (is_empty())
            throw runtime_error("Deque is empty");

        return rear->data;
    }

    bool is_empty()
    {
        return size == 0;
    }

    int get_size()
    {
        return size;
    }

    void display()
    {
        Node* current = front;
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
/*
int main()
{
    // Create a Deque of integers
    Deque<int> deque;

    // Push elements to the front and back
    deque.push_front(10);
    deque.push_back(20);
    deque.push_front(5);
    deque.push_back(30);

    // Display the Deque after pushes
    cout << "Deque after pushes: ";
    deque.display();

    // Get and display the front and rear elements
    cout << "Front element: " << deque.get_front() << endl;
    cout << "Rear element: " << deque.get_rear() << endl;

    // Pop elements from the front and back
    deque.pop_front();
    deque.pop_back();

    // Display the Deque after pops
    cout << "Deque after pops: ";
    deque.display();

    // Display the size of the Deque
    cout << "Size of deque: " << deque.get_size() << endl;

    return 0;
}*/