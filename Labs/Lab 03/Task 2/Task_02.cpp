#include <iostream>
#include "Stack.h"
using namespace std;

template <typename T>
T numberValidation(T &);

class Queue
{
    Stack<int> st1, st2;

    bool empty() { return st1.empty(); }
public:
    void print();
    void push(int);
    int pop();
};

void Queue::push(int x)
{
    if (st1.empty())
        st1.push(x);
    else
    {
        // Move all elements from st1 to st2
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        // Move x element to st2 so when shifted to st1, it's on the last/top
        st2.push(x);
        // Move elements from st2 to st1, the front of queue will be at the top
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
}

int Queue::pop()
{
    // Top element on the stack to be removed
    if (st1.empty())
        return -923;
    int x = st1.top();
    st1.pop();
    return x;
}

void Queue::print()
{
    st1.print();
}

int main()
{
    Queue q;
    int choice, x;
    while (true)
    {
        system("cls");
        cout << "Queue Operations" << endl;
        cout << "1. Push\n2. Pop\n3. Exit\n";
        cout << "Enter your choice: ";
        numberValidation(choice);
        cout << endl;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to push: ";
            cin >> x;
            q.push(x);
            cout << "Element Pushed." << endl;
            q.print();
            break;
        case 2:
            if (q.pop() == -923)
                cout << "Queue is empty." << endl;
            else
            {
                cout << "Element removed." << endl;
                q.print();
            }
            break;
        case 3:
            cout << "Exit..." << endl;
            exit(0);
            return 0;
        default:
            cout << "Invalid choice." << endl;
        }
        cout << endl;
        system("pause");
    }

    return 0;
}

template <typename T>
T numberValidation(T &number)
{
    bool validInput = false;
    while (!validInput)
    {
        if (cin >> number)
        {
            if (number <= 0)
                cout << "Enter positive number: " << endl;
            else
                validInput = true;
        }
        else
        {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Invalid input. Please enter a valid number." << endl;
        }
    }
    return number;
}