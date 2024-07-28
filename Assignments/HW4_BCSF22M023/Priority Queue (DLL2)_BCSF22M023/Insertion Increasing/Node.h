#ifndef NODE_H
#define NODE_H

#include "Queue.h"

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

#endif