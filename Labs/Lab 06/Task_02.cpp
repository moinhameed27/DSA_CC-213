#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *constructLL(int arr[], int size)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < size; i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node *reverseList(Node *head)
{
    Node *nextNode = head, *prevNode = nullptr;
    while (head)
    {
        nextNode = head->next;
        head->next = prevNode;
        prevNode = head;
        head = nextNode;
    }
    return prevNode;
}

int getNumberFromLL(Node *head)
{
    int num = 0, mul = 1;
    Node *mover = head;
    while(mover)
    {
        num = num + (mover->data * mul);
        mul *= 10;
        mover = mover->next;
    }
    return num;
}

Node* convertNumToLL(int num, Node *head)
{
    Node *mover = head;
    Node *prev = nullptr;
    while(num > 0)
    {
        int div = num % 10;
        if(mover)
        {
            mover->data = div;
            prev = mover;
            mover = mover->next;
        }
        else
        {
            Node *newNode = new Node(div);
            prev->next = newNode;
            mover = newNode;
            prev = mover;
            mover = mover->next;
        }
        num /= 10;
    }
    head = reverseList(head);
    return head;
}

int main()
{
    int v[] = {1, 0, 0, 1};
    Node *head = constructLL(v, 4);
    head = reverseList(head);
    int num = getNumberFromLL(head);
    cout << "Number : " << num << endl;
    head = convertNumToLL(num * 2, head);
    Node *mover = head;
    cout << "Double : ";
    while(mover)
    {
        cout << mover->data;
        mover = mover->next;
    }
    return 0;
}