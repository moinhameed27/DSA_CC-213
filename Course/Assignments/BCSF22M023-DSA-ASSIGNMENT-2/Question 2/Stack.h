#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
class Node
{
    T data;
    Node<T>* next;
public:
    Node() : data(0), next(nullptr) {}
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }

    Node(T data, Node<T>* next)
    {
        this->data = data;
        this->next = next;
    }
    template <typename U>
    friend class Stack;
};

template <typename T>
class Stack
{
    Node<T>* head;
    Node<T>* last;

public:
    Stack() { head = last = nullptr; }
    void push(T);
    void pop();
    T top();
    void print();
    bool empty();
    int size();
    ~Stack();
};

// Push an element into the stack.
template <typename T>
void Stack<T>::push(T x)
{
    Node<T>* newNode = new Node<T>(x);
    if (head == nullptr)
    {
        head = last = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

// Remove an element from the top of the stack.
template <typename T>
void Stack<T>::pop()
{
    if (head == nullptr)
        cout << "Empty Stack" << endl;
    else
    {
        Node<T>* temp = head;
        if (head == last)
            head = last = nullptr;
        else
            head = head->next;
        delete temp;
    }
}

// Top of the Stack
template <typename T>
T Stack<T>::top()
{
    if (head == nullptr)
    {
        cout << "Empty Stack" << endl;
        return T(); // Return a default-constructed object of type T
    }
    else
        return head->data;
}

// Print the elements in the stack.
template <typename T>
void Stack<T>::print()
{
    if (head == nullptr)
        cout << "Empty Stack" << endl;
    else
    {
        cout << endl;
        Node<T>* mover = head;
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
template <typename T>
bool Stack<T>::empty()
{
    return head == nullptr;
}

// Size of Stack
template <typename T>
int Stack<T>::size()
{
    if (head == nullptr)
        return 0;
    else
    {
        int count = 0;
        Node<T>* mover = head;
        while (mover)
            count++, mover = mover->next;
        return count;
    }
}

// Destructor
template <typename T>
Stack<T>::~Stack()
{
    Node<T>* mover = head;
    while (mover)
    {
        Node<T>* deleteNode = mover;
        mover = mover->next;
        delete deleteNode;
    }
}

#endif
