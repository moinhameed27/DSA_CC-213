#ifndef CDLL2_H
#define CDLL2_H

#include <iostream>
#include <vector>
using namespace std;
#include "Node.h"

class CDLL2
{
    Node *head;
    Node *last;

public:
    CDLL2();
    void print();
    int size();
    void insertFirstNode(int);
    void insertLastNode(int);
    void insertAfterXNode(int, int);
    void insertBeforeXNode(int, int);
    void sortedInsertionIncreasing(int);
    void sortedInsertionDecreasing(int);
    void deleteFirstNode();
    void deleteLastNode();
    void deleteKthNode(int);
    void deleteFirstOccurrenceOfXNode(int);
    void deleteKthOccurrenceOfXNode(int, int);
    void deleteAllOccurrencesOfXNode(int);
    void reverseList();
    void printReverse();
    ~CDLL2();
};

// Constructor
CDLL2::CDLL2() : head(nullptr), last(nullptr) {}

// Destructor
CDLL2::~CDLL2()
{
    if (head != nullptr)
    {
        Node *mover = head;
        do
        {
            Node *next = mover->next;
            delete mover;
            mover = next;
        } while (mover != head);
    }
    head = nullptr;
    last = nullptr;
}

// Print the Circular Doubly Linked List
void CDLL2::print()
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node *mover = head;
    do
    {
        cout << mover->data << " ";
        mover = mover->next;
    } while (mover != head);
    cout << endl;
}

// Print the list in reverse order
void CDLL2::printReverse()
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node *mover = last;
    do
    {
        cout << mover->data << " ";
        mover = mover->prev;
    } while (mover != last);
    cout << endl;
}

// Length of Circular Doubly Linked List
int CDLL2::size()
{
    if (head == nullptr)
    {
        return 0;
    }
    Node *mover = head;
    int count = 0;
    do
    {
        count++;
        mover = mover->next;
    } while (mover != head);
    return count;
}

// Insert at the Start of Circular Doubly Linked List
void CDLL2::insertFirstNode(int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        last = newNode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        newNode->next = head;
        newNode->prev = last;
        head->prev = newNode;
        last->next = newNode;
        head = newNode;
    }
}

// Insert at the Last of Circular Doubly Linked List
void CDLL2::insertLastNode(int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        last = newNode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        last = newNode;
    }
}

// Insert after any X Node
void CDLL2::insertAfterXNode(int x, int val)
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node *mover = head;
    do
    {
        if (mover->data == x)
        {
            Node *newNode = new Node(val, mover->next, mover);
            mover->next->prev = newNode;
            mover->next = newNode;
            if (mover == last)
                last = newNode;
            return;
        }
        mover = mover->next;
    } while (mover != head);
    cout << "No Occurrence of " << x << " is present in the Linked List" << endl;
}

// Insert before any X Node
void CDLL2::insertBeforeXNode(int x, int val)
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
    do
    {
        if (mover->data == x)
        {
            Node *newNode = new Node(val, mover, mover->prev);
            mover->prev->next = newNode;
            mover->prev = newNode;
            return;
        }
        mover = mover->next;
    } while (mover != head);
    cout << "No Occurrence of " << x << " is present in the Linked List" << endl;
}

// Insert into Circular Doubly Linked List in sorted order (increasing)
void CDLL2::sortedInsertionIncreasing(int val)
{
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
        head = newNode;
        last = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    Node *mover = head;
    do
    {
        if (val <= mover->data)
        {
            newNode->next = mover;
            newNode->prev = mover->prev;
            mover->prev->next = newNode;
            mover->prev = newNode;

            if (mover == head)
                head = newNode;

            return;
        }
        mover = mover->next;
    } while (mover != head);

    // If not inserted in between, insert at the end
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    last = newNode;
}

// Insert into Circular Doubly Linked List in sorted order (decreasing)
void CDLL2::sortedInsertionDecreasing(int val)
{
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
        head = newNode;
        last = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    Node *mover = head;
    do
    {
        if (val >= mover->data)
        {
            newNode->next = mover;
            newNode->prev = mover->prev;
            mover->prev->next = newNode;
            mover->prev = newNode;

            if (mover == head)
                head = newNode;

            return;
        }
        mover = mover->next;
    } while (mover != head);

    // If not inserted in between, insert at the end
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    last = newNode;
}

// Delete the first node in the list
void CDLL2::deleteFirstNode()
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node *nodeToDelete = head;
    if (head == last)
    {
        head = nullptr;
        last = nullptr;
    }
    else
    {
        head = head->next;
        head->prev = last;
        last->next = head;
    }
    delete nodeToDelete;
}

// Delete the last node in the list
void CDLL2::deleteLastNode()
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node *nodeToDelete = last;
    if (head == last)
    {
        head = nullptr;
        last = nullptr;
    }
    else
    {
        last = last->prev;
        last->next = head;
        head->prev = last;
    }
    delete nodeToDelete;
}

// Delete the kth node in the list
void CDLL2::deleteKthNode(int k)
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    if (k <= 0)
    {
        cout << "Invalid value of k" << endl;
        return;
    }
    Node *mover = head;
    int count = 1;
    do
    {
        if (count == k)
        {
            if (mover == head)
            {
                deleteFirstNode();
                return;
            }
            else if (mover == last)
            {
                deleteLastNode();
                return;
            }
            else
            {
                mover->prev->next = mover->next;
                mover->next->prev = mover->prev;
                delete mover;
                return;
            }
        }
        count++;
        mover = mover->next;
    } while (mover != head);
    cout << "No node at position " << k << " is present in the Linked List" << endl;
}

// Delete first Occurrence of X Node
void CDLL2::deleteFirstOccurrenceOfXNode(int x)
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node *mover = head;
    do
    {
        if (mover->data == x)
        {
            if (mover == head && mover == last)
            {
                head = nullptr;
                last = nullptr;
            }
            else if (mover == head)
            {
                head = head->next;
                head->prev = last;
                last->next = head;
            }
            else if (mover == last)
            {
                last = last->prev;
                last->next = head;
                head->prev = last;
            }
            else
            {
                mover->prev->next = mover->next;
                mover->next->prev = mover->prev;
            }
            delete mover;
            return;
        }
        mover = mover->next;
    } while (mover != head);
    cout << "No Occurrence of " << x << " is present in the Linked List" << endl;
}

// Delete kth Occurrence of X node
void CDLL2::deleteKthOccurrenceOfXNode(int x, int k)
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node *mover = head;
    int count = 0;
    do
    {
        if (mover->data == x)
        {
            count++;
            if (count == k)
            {
                if (mover == head && mover == last)
                {
                    head = nullptr;
                    last = nullptr;
                }
                else if (mover == head)
                {
                    head = head->next;
                    head->prev = last;
                    last->next = head;
                }
                else if (mover == last)
                {
                    last = last->prev;
                    last->next = head;
                    head->prev = last;
                }
                else
                {
                    mover->prev->next = mover->next;
                    mover->next->prev = mover->prev;
                }
                delete mover;
                return;
            }
        }
        mover = mover->next;
    } while (mover != head);
    if (count < k)
        cout << "No " << k << "th Occurrence of " << x << " is present in the Linked List" << endl;
}

// Delete all occurrences of any X Node
void CDLL2::deleteAllOccurrencesOfXNode(int x)
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node *mover = head;
    bool isPresent = false;

    do
    {
        if (mover->data == x)
        {
            isPresent = true;
            Node *nodeToDelete = mover;
            if (mover == head && mover == last)
            {
                head = nullptr;
                last = nullptr;
                delete nodeToDelete;
                return;
            }
            else if (mover == head)
            {
                head = head->next;
                head->prev = last;
                last->next = head;
            }
            else if (mover == last)
            {
                last = last->prev;
                last->next = head;
                head->prev = last;
            }
            else
            {
                mover->prev->next = mover->next;
                mover->next->prev = mover->prev;
            }
            mover = mover->next;
            delete nodeToDelete;
        }
        else
            mover = mover->next;
    } while (mover != head);

    if (!isPresent)
        cout << "No Occurrence of " << x << " is present in the Linked List" << endl;
}

// Reverse the linked list
void CDLL2::reverseList()
{
    if (head == nullptr)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    Node *mover = head;
    Node *prevNode = nullptr;
    do
    {
        prevNode = mover->prev;
        mover->prev = mover->next;
        mover->next = prevNode;
        mover = mover->prev;
    } while (mover != head);
    // prevNode used as a temp node to swap head and last
    prevNode = head;
    head = last;
    last = prevNode;
}
#endif
