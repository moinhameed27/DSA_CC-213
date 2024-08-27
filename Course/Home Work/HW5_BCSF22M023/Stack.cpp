#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
void positiveValidation(T &);
template <typename T>
void numberValidation(T &);

template <typename T>
class Stack
{
    int capacity;
    T *data;
    int top;

public:
    Stack(int size);
    ~Stack();

    void push(T);
    T pop();
    T peek();
    bool isEmpty();
    bool isFull();
    int size();
    void print();
};

// Constructor to initialize stack with given size
template <typename T>
Stack<T>::Stack(int size)
{
    capacity = size;
    data = new T[capacity];
    top = 0;
}

// Destructor
template <typename T>
Stack<T>::~Stack()
{
    delete[] data;
}

// Push element to stack
template <typename T>
void Stack<T>::push(T val)
{
    if (isFull())
    {
        cout << "Stack is full, cannot push " << val << endl;
        return;
    }
    data[top++] = val;
}

// Pop element from stack
template <typename T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty, cannot pop" << endl;
        return -923;
    }
    return data[--top];
}

// Peek top element of stack
template <typename T>
T Stack<T>::peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty, nothing to peek" << endl;
        return -923;
    }
    return data[top - 1];
}

// Check if stack is empty
template <typename T>
bool Stack<T>::isEmpty()
{
    return top == 0;
}

// Check if stack is full
template <typename T>
bool Stack<T>::isFull()
{
    return top == capacity;
}

// Get size of stack
template <typename T>
int Stack<T>::size()
{
    return top;
}

// Print stack
template <typename T>
void Stack<T>::print()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return;
    }
    else
    {
        cout << endl;
        cout << "-----------" << endl;
        for (int i = top - 1; i >= 0; i--)
        {
            cout << "|" << setw(5) << fixed << data[i] << setw(5) << fixed << "|" << endl;
            cout << "-----------" << endl;
        }
        cout << endl;
    }
}

int main()
{
    int choice, element, size, top;
    system("cls");
    cout << "Enter stack capacity: ";
    positiveValidation(size);

    Stack<int> stack(size);

    do
    {
        system("cls");
        cout << "\n----------> Stack <----------" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Check if Stack is Empty" << endl;
        cout << "5. Check if Stack is Full" << endl;
        cout << "6. Get Stack Size" << endl;
        cout << "7. Print Stack" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        positiveValidation(choice);
        cout << endl;

        switch (choice)
        {
        case 1:
            cout << "Enter element to push: ";
            numberValidation(element);
            stack.push(element);
            stack.print();
            break;

        case 2:
            top = stack.pop();
            if (top != -923)
            {
                cout << "Popped element: " << top << endl;
                stack.print();
            }
            break;

        case 3:
            top = stack.peek();
            if (top != -923)
            {
                cout << "Top element: " << top << endl;
                stack.print();
            }
            break;

        case 4:
            cout << (stack.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
            break;

        case 5:
            cout << (stack.isFull() ? "Stack is full" : "Stack is not full") << endl;
            break;

        case 6:
            cout << "Stack size: " << stack.size() << endl;
            break;

        case 7:
            stack.print();
            break;

        case 8:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice, please try again." << endl;
            break;
        }
        cout << endl;
        system("pause");

    } while (choice != 8);

    return 0;
}

template <typename T>
void positiveValidation(T &number)
{
    bool validInput = false;
    while (!validInput)
    {
        if (cin >> number)
        {
            if (number <= 0)
                cout << "Enter a positive number: " << endl;
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
}

template <typename T>
void numberValidation(T &number)
{
    bool validInput = false;
    while (!validInput)
    {
        if (cin >> number)
            validInput = true;
        else
        {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Invalid input. Please enter a valid number." << endl;
        }
    }
}
