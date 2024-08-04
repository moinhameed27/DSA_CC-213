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
    Node *mover = head;
    while (mover)
    {
        Node *nextNode = mover->next;
        delete mover;
        mover = nextNode;
    }
    head = nullptr;
    last = nullptr;
}

// Enqueue: Add an item to the queue (sorted insertion in decreasing order)
void Queue::enqueue(int item)
{
    Node *newNode = new Node(item);
    // Empty Linked List
    if (head == nullptr) 
        head = last = newNode;
    
    // Insertion at the first Node
    else if (head->data <= item)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else 
    {
        Node *mover = head;
        while (mover->next && mover->next->data > item)
            mover = mover->next;

        newNode->next = mover->next;
        if (mover->next)
            newNode->next->prev = newNode;
        else 
            last = newNode;

        mover->next = newNode;
        newNode->prev = mover;
    }
}

// Dequeue: Remove and return the item from the front of the queue
int Queue::dequeue()
{
    if (head == nullptr)
        return -923; 
        
    int data = head->data;
    Node *nodeToDelete = head;
    head = head->next;
    if (head)
        head->prev = nullptr;
    else
        last = nullptr;
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
    int count = 0;
    Node *mover = head;
    while (mover)
    {
        count++;
        mover = mover->next;
    }
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
    while (mover)
    {
        cout << mover->data << " ";
        mover = mover->next;
    }
    cout << endl;
}

#endif
