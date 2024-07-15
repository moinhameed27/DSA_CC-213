#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
#include "Node.h"

class Queue
{
    Node *front;
    Node *rear;

public:
    Queue();
    ~Queue();
    void enqueue(int);
    int dequeue();
    void add_front(int);
    int remove_rear();
    int peek_front();
    int peek_rear();
    bool is_empty();
    int size();
    void print();
};

// Constructor
Queue::Queue() : front(nullptr), rear(nullptr) {}

// Destructor
Queue::~Queue()
{
    Node *mover = front;
    while (front)
    {
        front = front->next;
        delete mover;
        mover = front;
    }
    rear = nullptr;
}

// Add an item to the end of the queue
void Queue::enqueue(int val)
{
    Node *newNode = new Node(val);
    if (rear == nullptr)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

// Remove and return the item from the front of the queue
int Queue::dequeue()
{
    if (front == nullptr)
        return -923;
    int val = front->data;
    Node *nodeToDelete = front;
    front = front->next;
    // If only one node in the queue
    if (front == nullptr)
        rear = nullptr;
    delete nodeToDelete;
    return val;
}

// Add an item to the front of the queue
void Queue::add_front(int val)
{
    Node *newNode = new Node(val);
    if (front == nullptr)
        front = rear = newNode;
    else
    {
        newNode->next = front;
        front = newNode;
    }
}

// Remove and return the item from the rear of the queue
int Queue::remove_rear()
{
    if (rear == nullptr)
        return -923;
    // If only one node in the queue
    if (front == rear)
    {
        int val = rear->data;
        delete rear;
        front = rear = nullptr;
        return val;
    }
    Node *mover = front;
    // Stop at the second last node
    while (mover->next != rear)
        mover = mover->next;
    int val = rear->data;
    delete rear;
    rear = mover;
    rear->next = nullptr;
    return val;
}

// Return the item at the front of the queue without removing it
int Queue::peek_front()
{
    if (front == nullptr)
        return -923;
    return front->data;
}

// Return the item at the rear of the queue without removing it
int Queue::peek_rear()
{
    if (rear == nullptr)
        return -923;
    return rear->data;
}

// Check if the queue is empty
bool Queue::is_empty()
{
    return front == nullptr;
}

// Return the number of items in the queue
int Queue::size()
{
    Node *mover = front;
    int count = 0;
    while (mover)
    {
        count++;
        mover = mover->next;
    }
    return count;
}

// Prints the items in the queue
void Queue::print()
{
    if (front == nullptr)
    {
        cout << "Empty Queue" << endl;
        return;
    }
    cout << "Queue: ";
    Node *mover = front;
    while (mover)
    {
        cout << mover->data << " ";
        mover = mover->next;
    }
    cout << endl;
}

#endif
