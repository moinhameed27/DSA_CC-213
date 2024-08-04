#ifndef NODE_H
#define NODE_H

#include "Queue.h"

class Node
{
    int data;
    Node *next;
public:
    Node() : data(0), next(nullptr) {}
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
    friend class Queue;
};

#endif