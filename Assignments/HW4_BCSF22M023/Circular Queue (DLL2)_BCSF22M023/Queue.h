#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;
#include "Node.h"

class Queue
{
    Node *head;
    Node *last;

public:
    Queue();
    ~Queue();
    void enqueue(int item);
    int dequeue();
    int peek_front();
    int size();
    void print();
};

// Constructor
Queue::Queue() : head(nullptr), last(nullptr) {}

// Destructor
Queue::~Queue()
{
    if (head)
    {
        Node *mover = head;
        do
        {
            Node *next = mover->next;
            delete mover;
            mover = next;
        } while (mover != head);
    }
    head = nullptr;
    last = nullptr;
}

// Enqueue: Add an item to the end of the queue
void Queue::enqueue(int item)
{
    Node *newNode = new Node(item);
    // Empty Linked List
    if (head == nullptr)
    {
        head = newNode;
        last = newNode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        last = newNode;
    }
}

// Dequeue: Remove and return the item from the front of the queue
int Queue::dequeue()
{
    if (head == nullptr)
        return -923;
    int data = head->data;
    Node *nodeToDelete = head;
    // Single Node
    if (head == last)
    {
        head = nullptr;
        last = nullptr;
    }
    else
    {
        head = head->next;
        head->prev = last;
        last->next = head;
    }
    delete nodeToDelete;
    return data;
}

// Peek front: Return the item at the front of the queue without removing it
int Queue::peek_front()
{
    if (head == nullptr)
    {
        cout << "Queue is empty" << endl;
        return -923;
    }
    return head->data;
}

// Size: Return the number of items in the queue
int Queue::size()
{
    if (head == nullptr)
        return 0;
    Node *mover = head;
    int count = 0;
    do
    {
        count++;
        mover = mover->next;
    } while (mover != head);
    return count;
}

// Print: Prints the items in the queue
void Queue::print()
{
    if (head == nullptr)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    Node *mover = head;
    do
    {
        cout << mover->data << " ";
        mover = mover->next;
    } while (mover != head);
    cout << endl;
}

#endif