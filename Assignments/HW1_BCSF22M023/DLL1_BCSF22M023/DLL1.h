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
    DLL1();
    DLL1(Node *);
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
    ~DLL1();
};

// Constructors
DLL1::DLL1() : head(nullptr) {}
DLL1::DLL1(Node *t) : head(t) {}

// Print the Linked List
void DLL1::print()
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    cout << "List : ";
    Node *mover = head;
    while (mover)
    {
        cout << mover->data << " ";
        mover = mover->next;
    }
    cout << endl;
}

// Length of Linked List
int DLL1::size()
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
void DLL1::insertFirstNode(int val)
{
    Node *newNode = new Node(val, head, nullptr);
    if (head)
        head->prev = newNode;
    head = newNode;
}

// Insert at the Last of Linked List
void DLL1::insertLastNode(int val)
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

// Insert after any X Node
void DLL1::insertAfterXNode(int x, int val)
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
            mover->next = newNode;
            return;
        }
        mover = mover->next;
    }
    cout << "No Occurrence of " << x << " is present in the Linked List" << endl;
}

// Insert before any X Node
void DLL1::insertBeforeXNode(int x, int val)
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

// Insert in sorted order (increasing)
void DLL1::sortedInsertionIncreasing(int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr || head->data >= val)
    {
        newNode->next = head;
        if (head)
            head->prev = newNode;
        head = newNode;
    }
    else
    {
        Node *mover = head;
        while (mover->next && mover->next->data < val)
            mover = mover->next;
        newNode->next = mover->next;
        newNode->prev = mover;
        if (mover->next)
            mover->next->prev = newNode;
        mover->next = newNode;
    }
}

// Insert in sorted order (decreasing)
void DLL1::sortedInsertionDecreasing(int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr || head->data <= val)
    {
        newNode->next = head;
        if (head)
            head->prev = newNode;
        head = newNode;
    }
    else
    {
        Node *mover = head;
        while (mover->next && mover->next->data > val)
            mover = mover->next;
        newNode->next = mover->next;
        newNode->prev = mover;
        if (mover->next)
            mover->next->prev = newNode;
        mover->next = newNode;
    }
}

// Delete first Occurrence of X Node
void DLL1::deleteFirstOccurrenceOfXNode(int x)
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
            }
            else
            {
                mover->prev->next = mover->next;
                if (mover->next)
                    mover->next->prev = mover->prev;
            }
            delete mover;
            return;
        }
        mover = mover->next;
    }
    cout << "No Occurrence of " << x << " is present in the Linked List" << endl;
}

// Delete kth Occurrence of X node
void DLL1::deleteKthOccurrenceOfXNode(int x, int k)
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
                }
                else
                {
                    mover->prev->next = mover->next;
                    if (mover->next)
                        mover->next->prev = mover->prev;
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
void DLL1::deleteAllOccurrencesOfXNode(int x)
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
                mover = head;
            }
            else
            {
                mover->prev->next = mover->next;
                if (mover->next)
                    mover->next->prev = mover->prev;
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
void DLL1::reverseList()
{
    if (head == nullptr || head->next == nullptr)
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
    head = prevNode->prev;
}

// Print the list in reverse order
void DLL1::printReverse()
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node *mover = head;
    while (mover->next)
        mover = mover->next;
    while (mover)
    {
        cout << mover->data << " ";
        mover = mover->prev;
    }
    cout << endl;
}

// Destructor
DLL1::~DLL1()
{
    Node *curr = head;
    while (head)
    {
        head = head->next;
        delete curr;
        curr = head;
    }
}

#endif
