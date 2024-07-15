#ifndef DLL1_H
#define DLL1_H
#include <iostream>
#include <vector>
using namespace std;
#include "Node.h"

class DLL1
{
    Node *head;

public:
    // Constructor
    DLL1() : head(nullptr) {}
    DLL1(Node *t) : head(t) {}

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
        Node *newNode = new Node(val, head, nullptr);
        if (head)
            head->prev = newNode;
        head = newNode;
    }

    void insertLastNode(int val)
    {
        if (head == nullptr)
        {
            head = new Node(val);
            return;
        }
        Node *mover = head;
        while (mover->next)
            mover = mover->next;
        Node *newNode = new Node(val, nullptr, mover);
        mover->next = newNode;
    }

    void deleteNthNodeFromLast(int n)
    {
        if(head == nullptr)
        {
            cout << "Empty Linked List" << endl;
            return;
        }
        Node *mover = head, *prevNode = nullptr;
        int count1 = 0;
        while (mover)
        {
            count1++;
            prevNode = mover;
            mover = mover->next;
        }

        if (n > count1)
        {
            cout << "Invalid Case" << endl;
            return;
        }

        // First Node
        if(n == count1)
        {
            Node *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            return;
        }

        // Last Node
        if(n == 1)
        {
            Node *temp = prevNode;
            prevNode = prevNode->prev;
            prevNode->next = nullptr;
            delete temp;
            return;
        }

        // In Between
        mover = prevNode;
        int count2 = 0;
        while (mover)
        {
            count2++;
            if (count2 == n)
            {
                Node *prevNode = mover->prev;
                mover->next->prev = prevNode;
                prevNode->next = mover->next;
                delete mover;
                return;
            }
            mover = mover->prev;
        }
    }

    // Destructor
    ~DLL1()
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
