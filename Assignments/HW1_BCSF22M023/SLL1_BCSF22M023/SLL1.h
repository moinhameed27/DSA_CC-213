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
    SLL1();
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
    ~SLL1();
};

// Constructor
SLL1::SLL1() : head(nullptr) {}

// Print the Linked List
void SLL1::print()
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
int SLL1::size()
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
void SLL1::insertFirstNode(int val)
{
    if (head == nullptr)
    {
        head = new Node(val);
        return;
    }
    Node *temp = head;
    head = new Node(val, temp);
}

// Insert at the Last of Linked List
void SLL1::insertLastNode(int val)
{
    if (head == nullptr)
    {
        head = new Node(val);
        return;
    }
    Node *mover = head;
    // Stops at last node
    while (mover->next != nullptr)
        mover = mover->next;
    mover->next = new Node(val);
}

// Insert after any X Node
void SLL1::insertAfterXNode(int x, int val)
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
            Node *newNode = new Node(val, mover->next);
            mover->next = newNode;
            return;
        }
        mover = mover->next;
    }
    cout << "No Occurrence of " << x << " is present in the Linked List" << endl;
}

// Insert before any X Node
void SLL1::insertBeforeXNode(int x, int val)
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    if (head->data == x)
    {
        Node *newNode = new Node(val, head);
        head = newNode;
        return;
    }
    Node *mover = head;
    Node *prev = nullptr;
    while (mover)
    {
        if (mover->data == x)
        {
            Node *newNode = new Node(val, mover);
            prev->next = newNode;
            return;
        }
        prev = mover;
        mover = mover->next;
    }
    cout << "No Occurrence of " << x << " is present in the Linked List" << endl;
}

// Sorted insertion in increasing order
void SLL1::sortedInsertionIncreasing(int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr || head->data >= val)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *mover = head;
    while (mover->next != nullptr && mover->next->data < val)
        mover = mover->next;

    newNode->next = mover->next;
    mover->next = newNode;
}

// Sorted insertion in decreasing order
void SLL1::sortedInsertionDecreasing(int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr || head->data <= val)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *mover = head;
    while (mover->next != nullptr && mover->next->data > val)
        mover = mover->next;

    newNode->next = mover->next;
    mover->next = newNode;
}

// Delete first Occurrence of X Node
void SLL1::deleteFirstOccurrenceOfXNode(int x)
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node *mover = head, *prevNode = nullptr;
    while (mover)
    {
        if (mover->data == x)
        {
            if (mover == head)
                head = mover->next;
            else
                prevNode->next = prevNode->next->next;
            delete mover;
            return;
        }
        prevNode = mover;
        mover = mover->next;
    }
    cout << "No Occurrence of " << x << " is present in the Linked List" << endl;
}

// Delete kth Occurrence of X node
void SLL1::deleteKthOccurrenceOfXNode(int x, int k)
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node *mover = head, *prevNode = nullptr;
    int count = 0;
    while (mover)
    {
        if (mover->data == x)
        {
            count++;
            if (count == k)
            {
                if (mover == head)
                    head = mover->next;
                else
                    prevNode->next = prevNode->next->next;
                delete mover;
                return;
            }
        }
        prevNode = mover;
        mover = mover->next;
    }
    if (count < k)
        cout << "No " << k << "th Occurrence of " << x << " is present in the Linked List" << endl;
}

// Delete all occurrences of any X Node
void SLL1::deleteAllOccurrencesOfXNode(int x)
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node *mover = head, *prevNode = nullptr;
    bool isPresent = false;

    while (mover != nullptr)
    {
        if (mover->data == x)
        {
            isPresent = true;
            Node *nodeToDelete = mover;
            if (mover == head)
            {
                head = head->next;
                mover = head;
            }
            else
            {
                prevNode->next = mover->next;
                mover = prevNode->next;
            }
            delete nodeToDelete;
        }
        else
        {
            prevNode = mover;
            mover = mover->next;
        }
    }

    if (!isPresent)
        cout << "No Occurrence of " << x << " is present in the Linked List" << endl;
}

// Reverse the linked list
void SLL1::reverseList()
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

// Print the list in reverse order
void SLL1::printReverse()
{
    reverseList();
    print();
    reverseList();
}

// Destructor
SLL1::~SLL1()
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