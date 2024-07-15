#include <iostream>
using namespace std;

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
    friend class CDLL2;
};

class CDLL2
{
    Node *head;
    Node *last;

public:
    CDLL2();
    void print();
    int size();
    void insertLastNode(int);
    void deleteFirstOccurrenceOfXNode(int);
    int removeMthNodes(int);
    ~CDLL2();
};

CDLL2::CDLL2() : head(nullptr), last(nullptr) {}

CDLL2::~CDLL2()
{
    if (head != nullptr)
    {
        Node *current = head;
        do
        {
            Node *next = current->next;
            delete current;
            current = next;
        } while (current != head);
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


int CDLL2::removeMthNodes(int m)
{
    Node *mover = head, *temp;
    while(size() > 1)
    {
        int count = 1;
        while(count != m)
        {
            count++;
            mover = mover->next;
        }
        if(count == m)
        {
            // cout << "Data : " << mover->data << endl;
            // print();
            temp = mover->next;
            deleteFirstOccurrenceOfXNode(mover->data);
            mover = temp;
        }
        else
            mover = mover->next;
    }
    return mover->data;
}

int main()
{
    CDLL2 obj;
    obj.insertLastNode(1);
    obj.insertLastNode(2);
    obj.insertLastNode(3);
    obj.insertLastNode(4);
    obj.insertLastNode(5);
    obj.insertLastNode(6);
    obj.insertLastNode(7);
    obj.print();
    cout << obj.removeMthNodes(2) << endl;
    // obj.print();
    return 0;
}
