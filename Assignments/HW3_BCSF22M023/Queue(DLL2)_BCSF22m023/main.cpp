#include "Queue.h"

template <typename T>
void positiveValidation(T &);
template <typename T>
void characterValidation(T &);

int main()
{
    Queue queue;
    int choice, value;

    while (true)
    {
        system("cls");
        cout << "\nQueue (DLL2) Operations Menu" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Add Front" << endl;
        cout << "4. Remove Rear" << endl;
        cout << "5. Peek Front" << endl;
        cout << "6. Peek Rear" << endl;
        cout << "7. Check if Empty" << endl;
        cout << "8. Size" << endl;
        cout << "9. Print" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        positiveValidation(choice);
        cout << endl;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            characterValidation(value);
            queue.enqueue(value);
            queue.print();
            break;
        case 2:
            value = queue.dequeue();
            if (value != -923)
                cout << "Dequeued value: " << value << endl;
            queue.print();
            break;
        case 3:
            cout << "Enter value to add at front: ";
            characterValidation(value);
            queue.add_front(value);
            queue.print();
            break;
        case 4:
            value = queue.remove_rear();
            if (value != -923)
                cout << "Removed rear value: " << value << endl;
            queue.print();
            break;
        case 5:
            value = queue.peek_front();
            if (value != -923)
                cout << "Front value: " << value << endl;
            break;
        case 6:
            value = queue.peek_rear();
            if (value != -923)
                cout << "Rear value: " << value << endl;
            break;
        case 7:
            if (queue.is_empty())
                cout << "Queue is empty." << endl;
            else
                cout << "Queue is not empty." << endl;
            break;
        case 8:
            cout << "Queue size: " << queue.size() << endl;
            break;
        case 9:
            queue.print();
            break;
        case 10:
            cout << "Exiting program..." << endl;
            cout << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
        system("pause");
    }
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
void characterValidation(T &number)
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
