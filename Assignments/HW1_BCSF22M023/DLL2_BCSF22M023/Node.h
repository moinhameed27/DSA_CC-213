#ifndef NODE_H
#define NODE_H

#include "DLL2.h"

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
    friend class DLL2;
    friend Node *convertArrayToLinkedList(vector<int> &vc);
};

#endif