#include "SDLL1.h"

template <typename T>
void positiveValidation(T &);
template <typename T>
void characterValidation(T &);

int main()
{
    Stack stack;
    int choice, value;

    while (true)
    {
        cout << "\nStack (SDLL1) Operations Menu" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Print" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Size" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        positiveValidation(choice);
        cout << endl;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            characterValidation(value);
            stack.push(value);
            stack.print();
            break;
        case 2:
            stack.pop();
            stack.print();
            break;
        case 3:
            value = stack.top();
            if (value != -1)
                cout << "Top element: " << value << endl;
            break;
        case 4:
            stack.print();
            break;
        case 5:
            if (stack.isEmpty())
                cout << "Stack is empty." << endl;
            else
                cout << "Stack is not empty." << endl;
            break;
        case 6:
            cout << "Stack size: " << stack.size() << endl;
            break;
        case 7:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        system("pause");
        system("cls");
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
