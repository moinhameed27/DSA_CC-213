#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;
    Node *prev;

public:
    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
    friend class Queue;
};

class Queue
{
    Node *head;
    Node *last;

public:
    Queue();
    ~Queue();
    void pushFront(int item);
    void pushMiddle(int item);
    void pushBack(int item);
    int popFront();
    int popMiddle();
    int popBack();
    int size();
    void print();
};

// Constructor
Queue::Queue() : head(nullptr), last(nullptr) {}

// Destructor
Queue::~Queue()
{
    if (head != nullptr)
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

void Queue::pushFront(int item)
{
    Node *newNode = new Node(item);
    if (head == nullptr)
    {
        head = newNode;
        last = newNode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void Queue::pushMiddle(int item)
{
    Node *newNode = new Node(item);
    if (head == nullptr)
    {
        head = newNode;
        last = newNode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        Node *slow = head, *fast = head->next;
        while (fast != head && fast->next != head)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        newNode->next = slow->next;
        slow->next->prev = newNode;
        slow->next = newNode;
        newNode->prev = slow;
    }
}

void Queue::pushBack(int item)
{
    Node *newNode = new Node(item);
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

int Queue::popFront()
{
    if (head == nullptr)
        return -923;
    int data = head->data;
    Node *nodeToDelete = head;
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

int Queue::popMiddle()
{
    if (head == nullptr)
        return -923;

    Node *slow = head, *fast = head->next;
    while (fast != head && fast->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->prev->next = slow->next;
    slow->next->prev =  slow->prev;
    return slow->data;
}

int Queue::popBack()
{
    if (head == nullptr)
        return -923;

    int data = last->data;
    last->prev->next = head;
    head->prev =  last->prev;
    return data;
}


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