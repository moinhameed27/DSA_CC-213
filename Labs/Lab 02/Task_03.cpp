#include <iostream>
using namespace std;

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
    friend class SLL1;
};

class SLL1
{
    Node *head;

public:
    SLL1();
    void print();
    void insertLastNode(int);
    Node *reverseList(Node *);
    bool isPalindrome();
    ~SLL1();
};

SLL1::SLL1() : head(nullptr) {}

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

Node *SLL1 ::reverseList(Node *head)
{
    Node *next = head, *prev = nullptr;
    while (next)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool SLL1::isPalindrome()
{
    Node *slow = head, *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = reverseList(slow->next);
    Node *start = head, *middle = slow;
    while (middle)
    {
        if (start->data != middle->data)
            return false;
        start = start->next;
        middle = middle->next;
    }
    return true;
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

int main()
{
    SLL1 obj;
    obj.insertLastNode(1);
    obj.insertLastNode(2);
    // obj.insertLastNode(3);
    // obj.insertLastNode(2);
    obj.insertLastNode(1);
    // obj.insertLastNode(1);
    if (obj.isPalindrome())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}