#ifndef SDLL1_H
#define SDLL1_H

#include <iostream>
#include <iomanip>
using namespace std;
#include "Node.h"

class Stack
{
    Node *head;

public:
    Stack() { head = nullptr; }
    void push(int);
    void pop();
    int top();
    void print();
    bool isEmpty();
    int size();
    ~Stack();
};

// Push an element into the stack.
void Stack::push(int x)
{
    Node *newNode = new Node(x);
    if (head == nullptr)
        head = newNode;
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Remove an element from the top of the stack.
void Stack::pop()
{
    if (head == nullptr)
        cout << "Empty Stack" << endl;
    {
        Node *temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        delete temp;
    }
}

// Top of the Stack
int Stack::top()
{
    if (head == nullptr)
    {
        cout << "Empty Stack" << endl;
        return -1;
    }
    else
        return head->data;
}

// Print the elements in the stack.
void Stack::print()
{
    if (head == nullptr)
        cout << "Empty Stack" << endl;
    else
    {
        cout << endl;
        Node *mover = head;
        cout << "-----------" << endl;
        while (mover)
        {
            cout << "|" << setw(5) << fixed << mover->data << setw(5) << fixed << "|" << endl;
            cout << "-----------" << endl;
            mover = mover->next;
        }
    }
}

// Check if the stack is empty or not.
bool Stack::isEmpty()
{
    return head == nullptr;
}

// Size of Stack
int Stack::size()
{
    int count = 0;
    Node *mover = head;
    while (mover)
        count++, mover = mover->next;
    return count;
}

// Destructor
Stack::~Stack()
{
    Node *mover = head;
    while (mover)
    {
        Node *deleteNode = mover;
        mover = mover->next;
        delete deleteNode;
    }
}

#endif
