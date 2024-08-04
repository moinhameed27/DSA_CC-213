#ifndef DLL2_H
#define DLL2_H

#include <iostream>
#include <vector>
using namespace std;
#include "Node.h"

class DLL2
{
    Node *head;
    Node *last;

public:
    DLL2();
    DLL2(Node *, Node *);
    void print();
    int size();
    void insertFirstNode(int);
    void insertLastNode(int);
    void insertAfterXNode(int, int);
    void insertBeforeXNode(int, int);
    void sortedInsertionIncreasing(int);
    void sortedInsertionDecreasing(int);
    void deleteFirstOccurrenceOfXNode(int);
    void deleteKthOccurrenceOfXNode(int, int);
    void deleteAllOccurrencesOfXNode(int);
    void reverseList();
    void printReverse();
    ~DLL2();
};

// Constructor
DLL2::DLL2() : head(nullptr), last(nullptr) {}

// Print the Linked List
void DLL2::print()
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

// Length of Linked List
int DLL2::size()
{
    Node *mover = head;
    int count = 0;
    while (mover)
    {
        count++;
        mover = mover->next;
    }
    return count;
}

// Insert at the Start of Linked List
void DLL2::insertFirstNode(int val)
{
    if (head == nullptr)
    {
        head = new Node(val);
        last = head;
        return;
    }
    Node *newNode = new Node(val, head, nullptr);
    head->prev = newNode;
    head = newNode;
}

// Insert at the Last of Linked List
void DLL2::insertLastNode(int val)
{
    if (head == nullptr)
    {
        head = new Node(val);
        last = head;
        return;
    }
    Node *newNode = new Node(val, nullptr, last);
    last->next = newNode;
    last = newNode;
}

// Insert after any X Node
void DLL2::insertAfterXNode(int x, int val)
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node *mover = head;
    while (mover)
    {
        if (mover->data == x)
        {
            Node *newNode = new Node(val, mover->next, mover);
            if (mover->next)
                mover->next->prev = newNode;
            else
                last = newNode;
            mover->next = newNode;
            return;
        }
        mover = mover->next;
    }
    cout << "No Occurrence of " << x << " is present in the Linked List" << endl;
}

// Insert before any X Node
void DLL2::insertBeforeXNode(int x, int val)
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    if (head->data == x)
    {
        insertFirstNode(val);
        return;
    }
    Node *mover = head;
    while (mover)
    {
        if (mover->data == x)
        {
            Node *newNode = new Node(val, mover, mover->prev);
            mover->prev->next = newNode;
            mover->prev = newNode;
            return;
        }
        mover = mover->next;
    }
    cout << "No Occurrence of " << x << " is present in the Linked List" << endl;
}

// Sorted insertion in increasing order
void DLL2::sortedInsertionIncreasing(int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = last = newNode;
        return;
    }

    if (val <= head->data)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    if (val >= last->data)
    {
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
        return;
    }

    Node *mover = head;
    while (mover->data < val)
        mover = mover->next;

    newNode->next = mover;
    newNode->prev = mover->prev;
    mover->prev->next = newNode;
    mover->prev = newNode;
}

// Sorted insertion in decreasing order
void DLL2::sortedInsertionDecreasing(int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = last = newNode;
        return;
    }

    if (val >= head->data)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    if (val <= last->data)
    {
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
        return;
    }

    Node *mover = head;
    while (mover->data > val)
        mover = mover->next;

    newNode->next = mover;
    newNode->prev = mover->prev;
    mover->prev->next = newNode;
    mover->prev = newNode;
}

// Delete first Occurrence of X Node
void DLL2::deleteFirstOccurrenceOfXNode(int x)
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node *mover = head;
    while (mover)
    {
        if (mover->data == x)
        {
            if (mover == head)
            {
                head = head->next;
                if (head)
                    head->prev = nullptr;
                else
                    last = nullptr;
            }
            else
            {
                mover->prev->next = mover->next;
                if (mover->next)
                    mover->next->prev = mover->prev;
                else
                    last = mover->prev;
            }
            delete mover;
            return;
        }
        mover = mover->next;
    }
    cout << "No Occurrence of " << x << " is present in the Linked List" << endl;
}

// Delete kth Occurrence of X node
void DLL2::deleteKthOccurrenceOfXNode(int x, int k)
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node *mover = head;
    int count = 0;
    while (mover)
    {
        if (mover->data == x)
        {
            count++;
            if (count == k)
            {
                if (mover == head)
                {
                    head = head->next;
                    if (head)
                        head->prev = nullptr;
                    else
                        last = nullptr;
                }
                else
                {
                    mover->prev->next = mover->next;
                    if (mover->next)
                        mover->next->prev = mover->prev;
                    else
                        last = mover->prev;
                }
                delete mover;
                return;
            }
        }
        mover = mover->next;
    }
    if (count < k)
        cout << "No " << k << "th Occurrence of " << x << " is present in the Linked List" << endl;
}

// Delete all occurrences of any X Node
void DLL2::deleteAllOccurrencesOfXNode(int x)
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node *mover = head;
    bool isPresent = false;

    while (mover)
    {
        if (mover->data == x)
        {
            isPresent = true;
            Node *nodeToDelete = mover;
            if (mover == head)
            {
                head = head->next;
                if (head)
                    head->prev = nullptr;
                else
                    last = nullptr;
                mover = head;
            }
            else
            {
                mover->prev->next = mover->next;
                if (mover->next)
                    mover->next->prev = mover->prev;
                else
                    last = mover->prev;
                mover = mover->next;
            }
            delete nodeToDelete;
        }
        else
            mover = mover->next;
    }

    if (!isPresent)
        cout << "No Occurrence of " << x << " is present in the Linked List" << endl;
}

// Reverse the linked list
void DLL2::reverseList()
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node *mover = head;
    Node *prevNode = nullptr;

    while (mover)
    {
        prevNode = mover->prev;
        mover->prev = mover->next;
        mover->next = prevNode;
        mover = mover->prev;
    }

    prevNode = head;
    head = last;
    last = prevNode;
}

// Print the list in reverse order
void DLL2::printReverse()
{
    if (last == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node *mover = last;
    while (mover)
    {
        cout << mover->data << " ";
        mover = mover->prev;
    }
    cout << endl;
}

// Destructor
DLL2::~DLL2()
{
    Node *curr = head;
    while (head)
    {
        head = head->next;
        delete curr;
        curr = head;
    }
    last = nullptr;
}

#endif
