#ifndef SLL1_H
#define SLL1_H
#include <iostream>
#include <vector>
using namespace std;
#include "Node.h"

class SLL1
{
    Node *head;

public:
    // Constructor
    SLL1() : head(nullptr) {}
    SLL1(Node *t) : head(t) {}

    // Print the Linked List
    void print()
    {
        if (head == nullptr)
        {
            cout << "Empty Linked List" << endl;
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

    void insertFirstNode(int val)
    {
        if (head == nullptr)
        {
            head = new Node(val);
            return;
        }
        Node *temp = head;
        head = new Node(val, temp);
    }

    void insertLastNode(int val)
    {
        if (head == nullptr)
        {
            head = new Node(val);
            return;
        }
        Node *mover = head;
        while (mover->next != nullptr)
            mover = mover->next;
        mover->next = new Node(val);
    }

    void reverseSinglyLinkedList()
    {
        if (head == nullptr)
        {
            cout << "Empty Linked List" << endl;
            return;
        }
        Node *nextNode = head, *prevNode = nullptr;
        while (head)
        {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        head = prevNode;
    }

    void zigzagPattern()
    {
        Node *mover = head, *prevNode = nullptr;
        int count = 0;
        while (mover)
        {
            count++;
            if (count % 2 == 0)
            {
                if (mover->data < prevNode->data)
                    swap(mover->data, prevNode->data);
                if (mover->next && mover->data < mover->next->data)
                    swap(mover->data, mover->next->data);
            }
            prevNode = mover;
            mover = mover->next;
        }
    }

    // Destructor
    ~SLL1()
    {
        Node *curr = head;
        while (head)
        {
            head = head->next;
            delete curr;
            curr = head;
        }
    }
};

#endif