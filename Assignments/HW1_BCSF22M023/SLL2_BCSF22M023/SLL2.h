#ifndef SLL2_H
#define SLL2_H
#include <iostream>
#include <vector>
using namespace std;
#include "Node.h"

class SLL2
{
    Node *head;
    Node *last;

public:
    SLL2();
    SLL2(Node *, Node *);
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
    ~SLL2();
};

// Constructors
SLL2::SLL2() : head(nullptr), last(nullptr) {}
SLL2::SLL2(Node *h, Node *l) : head(h), last(l) {}

// Print the Linked List
void SLL2::print()
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
int SLL2::size()
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
void SLL2::insertFirstNode(int val)
{
    if (head == nullptr)
    {
        head = new Node(val);
        last = head;
        return;
    }
    Node *temp = head;
    head = new Node(val, temp);
}

// Insert at the Last of Linked List
void SLL2::insertLastNode(int val)
{
    if (head == nullptr)
    {
        head = new Node(val);
        last = head;
        return;
    }
    last->next = new Node(val);
    last = last->next;
}

// Insert after any X Node
void SLL2::insertAfterXNode(int x, int val)
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    if (head == last)
    {
        insertLastNode(val);
        return;
    }
    Node *mover = head;
    bool isPresent = false;
    while (mover)
    {
        if (mover->data == x)
        {
            isPresent = true;
            Node *newNode = new Node(val, mover->next);
            mover->next = newNode;
            return;
        }
        else if (mover == last && last->data == x)
        {
            insertLastNode(val);
            return;
        }
        mover = mover->next;
    }
    if (!isPresent)
        cout << "No Occurrence of " << x << " is present in the Linked List" << endl;
}

// Insert before any X Node
void SLL2::insertBeforeXNode(int x, int val)
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    if (head == last)
    {
        insertFirstNode(val);
        return;
    }
    Node *mover = head;
    Node *prev = nullptr;
    bool isPresent = false;
    while (mover)
    {
        if (mover->data == x)
        {
            isPresent = true;
            Node *newNode = new Node(val, mover);
            prev->next = newNode;
            return;
        }
        prev = mover;
        mover = mover->next;
    }
    if (!isPresent)
        cout << "No Occurrence of " << x << " is present in the Linked List" << endl;
}

// Sorted insertion in increasing order
void SLL2::sortedInsertionIncreasing(int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr || head->data >= val)
    {
        newNode->next = head;
        head = newNode;
        if (last == nullptr)
            last = head;
        return;
    }

    Node *mover = head;
    while (mover->next != nullptr && mover->next->data < val)
        mover = mover->next;

    newNode->next = mover->next;
    mover->next = newNode;
    if (newNode->next == nullptr)
        last = newNode; // Update last if inserted at the end
}

// Sorted insertion in decreasing order
void SLL2::sortedInsertionDecreasing(int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr || head->data <= val)
    {
        newNode->next = head;
        head = newNode;
        if (last == nullptr)
            last = head;
        return;
    }

    Node *mover = head;
    while (mover->next != nullptr && mover->next->data > val)
        mover = mover->next;

    newNode->next = mover->next;
    mover->next = newNode;
    if (newNode->next == nullptr)
        last = newNode; // Update last if inserted at the end
}

// Delete first Occurrence of X Node
void SLL2::deleteFirstOccurrenceOfXNode(int x)
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    if (head == last && head->data == x)
    {
        delete head;
        head = last = nullptr;
        return;
    }
    Node *mover = head, *prevNode = nullptr;
    while (mover)
    {
        if (mover->data == x)
        {
            if (mover == head)
                head = mover->next;
            else if (mover == last)
                last = prevNode;
            else
                prevNode->next = mover->next;
            delete mover;
            return;
        }
        prevNode = mover;
        mover = mover->next;
    }
    cout << "No Occurrence of " << x << " is present in the Linked List" << endl;
}

// Delete kth Occurrence of X node
void SLL2::deleteKthOccurrenceOfXNode(int x, int k)
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
                else if (mover == last)
                    last = prevNode;
                else
                    prevNode->next = mover->next;
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
void SLL2::deleteAllOccurrencesOfXNode(int x)
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
            else if (mover == last)
            {
                last = prevNode;
                prevNode->next = nullptr;
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
void SLL2::reverseList()
{
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
void SLL2::printReverse()
{
    reverseList();
    print();
    reverseList();
}

// Destructor
SLL2::~SLL2()
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
