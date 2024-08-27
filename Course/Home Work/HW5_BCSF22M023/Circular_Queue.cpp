#include <iostream>
using namespace std;

template <typename T>
void positiveValidation(T &);
template <typename T>
void numberValidation(T &);
template <typename T>

class Queue
{
    int capacity;
    T *data;
    int front;
    int rear;
    int numOfElements;

public:
    Queue(int size);
    ~Queue();

    void enqueue(T);
    T dequeue();
    T getFront();
    T getRear();
    bool isFull();
    bool isEmpty();
    int size();
    void print();
};

// Constructor to initialize queue with given size
template <typename T>
Queue<T>::Queue(int size)
{
    capacity = size;
    data = new T[capacity];
    front = 0;
    rear = 0;
    numOfElements = 0;
}

// Destructor
template <typename T>
Queue<T>::~Queue()
{
    delete[] data;
}

// Enqueue element to queue
template <typename T>
void Queue<T>::enqueue(T val)
{
    if (isFull())
    {
        cout << "Queue is full, cannot enqueue " << val << endl;
        return;
    }
    data[rear] = val;
    rear = (rear + 1) % capacity;   // Circular increment
    numOfElements++;
}

// Dequeue element from queue
template <typename T>
T Queue<T>::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty, cannot dequeue" << endl;
        return -923;
    }
    T val = data[front];
    front = (front + 1) % capacity;
    numOfElements--;
    return val;
}

// Get front element of queue
template <typename T>
T Queue<T>::getFront()
{
    if (isEmpty())
    {
        cout << "Queue is empty, nothing at the front" << endl;
        return -923;
    }
    return data[front];
}

// Get Rear element of queue
template <typename T>
T Queue<T>::getRear()
{
    if (isEmpty())
    {
        cout << "Queue is empty, nothing at the rear" << endl;
        return -923;
    }
    return data[(rear - 1 + capacity) % capacity];
}

// Check if queue is full
template <typename T>
bool Queue<T>::isFull()
{
    return numOfElements == capacity;
}

// Check if queue is empty
template <typename T>
bool Queue<T>::isEmpty()
{
    return numOfElements == 0;
}

// Get size of queue
template <typename T>
int Queue<T>::size()
{
    return numOfElements;
}

// Print queue
template <typename T>
void Queue<T>::print()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << endl;
    cout << "Queue : ";
    for (int i = 0; i < numOfElements; i++)
        cout << data[(front + i) % capacity] << " ";
    cout << endl;
}

int main()
{
    int choice, element, size, front, rear;
    system("cls");

    cout << "Enter queue capacity: ";
    positiveValidation(size);

    Queue<int> queue(size);

    do
    {
        system("cls");
        cout << "\n----------> Queue <----------" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Rear" << endl;
        cout << "5. Check if Queue is Empty" << endl;
        cout << "6. Check if Queue is Full" << endl;
        cout << "7. Get Queue Size" << endl;
        cout << "8. Print Queue" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        positiveValidation(choice);
        cout << endl;

        switch (choice)
        {
        case 1:
            cout << "Enter element to enqueue: ";
            numberValidation(element);
            queue.enqueue(element);
            queue.print();
            break;

        case 2:
            front = queue.dequeue();
            if (front != -923)
            {
                cout << "Dequeued element: " << front << endl;
                queue.print();
            }
            break;

        case 3:
            front = queue.getFront();
            if (front != -923)
            {
                cout << "Front element: " << front << endl;
                queue.print();
            }
            break;

        case 4:
            rear = queue.getRear();
            if (front != -923)
            {
                cout << "Rear element: " << rear << endl;
                queue.print();
            }
            break;

        case 5:
            cout << (queue.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
            break;

        case 6:
            cout << (queue.isFull() ? "Queue is full" : "Queue is not full") << endl;
            break;

        case 7:
            cout << "Queue size: " << queue.size() << endl;
            break;

        case 8:
            queue.print();
            break;

        case 9:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice, please try again." << endl;
            break;
        }
        cout << endl;
        system("pause");
    } while (choice != 9);

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
