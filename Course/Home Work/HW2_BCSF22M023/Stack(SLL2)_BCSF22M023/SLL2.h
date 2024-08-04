#ifndef SSLL2_H
#define SSLL2_H

#include <iostream>
#include <iomanip>
using namespace std;
#include "Node.h"

class Stack
{
    Node *head;
    Node *last;

public:
    Stack() { head = last = nullptr; }
    void push(int);
    void pop();
    int top();
    void print();
    bool isEmpty();
    int size();
    ~Stack();
};

// Push an element into the stack.
void Stack ::push(int x)
{
    Node *newNode = new Node(x);
    if (head == nullptr)
    {
        head = last = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

// Remove an element from the top of the stack.
void Stack ::pop()
{
    if (head == nullptr)
        cout << "Empty Stack" << endl;
    else
    {
        Node *temp = head;
        if (head == last)
            head = last = nullptr;
        else
            head = head->next;
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
    if (head == nullptr)
        return 0;
    else
    {
        int count = 0;
        Node *mover = head;
        while (mover)
            count++, mover = mover->next;
        return count;
    }
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