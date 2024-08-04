#include <iostream>
#include "DLL1.h"

using namespace std;

template <typename T>
void positiveValidation(T &);
template <typename T>
void characterValidation(T &);

int main()
{
    DLL1 list;
    int choice, value, x, k;
    while (true)
    {
        cout << "\nDoubley Linked List (One Pointer) Operations Menu:" << endl;
        cout << "1. Print List" << endl;
        cout << "2. Get List Size" << endl;
        cout << "3. Insert at Start" << endl;
        cout << "4. Insert at End" << endl;
        cout << "5. Insert After Value" << endl;
        cout << "6. Insert Before Value" << endl;
        cout << "7. Insert in Sorted Order (Increasing)" << endl;
        cout << "8. Insert in Sorted Order (Decreasing)" << endl;
        cout << "9. Delete First Occurrence of Value" << endl;
        cout << "10. Delete Kth Occurrence of Value" << endl;
        cout << "11. Delete All Occurrences of Value" << endl;
        cout << "12. Reverse List" << endl;
        cout << "13. Print List in Reverse" << endl;
        cout << "14. Exit" << endl;
        cout << "Enter your choice: ";
        positiveValidation(choice);
        cout << endl;

        switch (choice)
        {
        case 1:
            list.print();
            break;
        case 2:
            cout << "Size of the list: " << list.size() << endl;
            break;
        case 3:
            cout << "Enter value to insert at start: ";
            characterValidation(value);
            list.insertFirstNode(value);
            list.print();
            break;
        case 4:
            cout << "Enter value to insert at end: ";
            characterValidation(value);
            list.insertLastNode(value);
            list.print();
            break;
        case 5:
            cout << "Enter the value after which to insert: ";
            characterValidation(x);
            cout << "Enter value to insert: ";
            characterValidation(value);
            list.insertAfterXNode(x, value);
            list.print();
            break;
        case 6:
            cout << "Enter the value before which to insert: ";
            characterValidation(x);
            cout << "Enter value to insert: ";
            characterValidation(value);
            list.insertBeforeXNode(x, value);
            list.print();
            break;
        case 7:
            cout << "Enter value to insert in sorted order (increasing): ";
            characterValidation(value);
            list.sortedInsertionIncreasing(value);
            list.print();
            break;
        case 8:
            cout << "Enter value to insert in sorted order (decreasing): ";
            characterValidation(value);
            list.sortedInsertionDecreasing(value);
            list.print();
            break;
        case 9:
            cout << "Enter value to delete first occurrence of: ";
            characterValidation(x);
            list.deleteFirstOccurrenceOfXNode(x);
            list.print();
            break;
        case 10:
            cout << "Enter value to delete: ";
            characterValidation(x);
            cout << "Enter the occurrence to delete (k): ";
            positiveValidation(k);
            list.deleteKthOccurrenceOfXNode(x, k);
            list.print();
            break;
        case 11:
            cout << "Enter value to delete all occurrences of: ";
            characterValidation(x);
            list.deleteAllOccurrencesOfXNode(x);
            list.print();
            break;
        case 12:
            cout << "Orginal ";
            list.print();
            cout << "Reversed ";
            list.reverseList();
            list.print();
            break;
        case 13:
            cout << "Orginal ";
            list.print();
            cout << "Reversed List : ";
            list.printReverse();
            break;
        case 14:
            cout << "Exiting..." << endl;
            exit(0);
        default:
            cout << "Invalid choice, please try again." << endl;
        }
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
