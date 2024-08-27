#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

template <typename T>
class Node
{
    T data;
    Node *next;
    Node *prev;

public:
    Node() : data(T()), next(nullptr), prev(nullptr) {}
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    Node(T data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
    template <typename U>
    friend class Queue;
};

template <typename T>
class Queue
{
    Node<T> *front;
    Node<T> *rear;

public:
    Queue();
    ~Queue();
    void enqueue(T);
    T dequeue();
    void add_front(T);
    T remove_rear();
    T peek_front();
    T peek_rear();
    bool is_empty();
    int size();
    void print();
};

// Constructor
template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr) {}

// Destructor
template <typename T>
Queue<T>::~Queue()
{
    Node<T> *mover = front;
    while (front)
    {
        front = front->next;
        delete mover;
        mover = front;
    }
    rear = nullptr;
}

// Add an item to the end of the queue
template <typename T>
void Queue<T>::enqueue(T val)
{
    Node<T> *newNode = new Node<T>(val);
    if (rear == nullptr)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
}

// Remove and return the item from the front of the queue
template <typename T>
T Queue<T>::dequeue()
{
    if (front == nullptr)
        return T();

    T val = front->data;
    Node<T> *nodeToDelete = front;
    front = front->next;
    // Check if Queue had only one element
    if (front)
        front->prev = nullptr;
    else
        rear = nullptr;

    delete nodeToDelete;
    return val;
}

// Add an item to the front of the queue
template <typename T>
void Queue<T>::add_front(T val)
{
    Node<T> *newNode = new Node<T>(val);
    if (front == nullptr)
        front = rear = newNode;
    else
    {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
}

// Remove and return the item from the rear of the queue
template <typename T>
T Queue<T>::remove_rear()
{
    if (rear == nullptr)
        return T();

    T val = rear->data;
    Node<T> *nodeToDelete = rear;
    rear = rear->prev;
    // Check if Queue had only one element
    if (rear)
        rear->next = nullptr;
    else
        front = nullptr;

    delete nodeToDelete;
    return val;
}

// Return the item at the front of the queue without removing it
template <typename T>
T Queue<T>::peek_front()
{
    if (front == nullptr)
        return T();

    return front->data;
}

// Return the item at the rear of the queue without removing it
template <typename T>
T Queue<T>::peek_rear()
{
    if (rear == nullptr)
        return T();

    return rear->data;
}

// Check if the queue is empty
template <typename T>
bool Queue<T>::is_empty()
{
    return front == nullptr;
}

// Return the number of items in the queue
template <typename T>
int Queue<T>::size()
{
    Node<T> *mover = front;
    int count = 0;
    while (mover)
    {
        count++;
        mover = mover->next;
    }
    return count;
}

// Prints the items in the queue
template <typename T>
void Queue<T>::print()
{
    if (front == nullptr)
    {
        cout << "Empty Queue" << endl;
        return;
    }
    cout << "Queue: ";
    Node<T> *mover = front;
    while (mover)
    {
        cout << mover->data << " ";
        mover = mover->next;
    }
    cout << endl;
}

#endif
