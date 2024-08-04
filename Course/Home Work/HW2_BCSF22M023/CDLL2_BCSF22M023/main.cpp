#include <iostream>
#include "CDLL2.h"

using namespace std;

template <typename T>
void positiveValidation(T &);
template <typename T>
void characterValidation(T &);

int main()
{
    CDLL2 list;
    int choice, value, x, k;

    while (true)
    {
        cout << "\nCircular Doubly Linked List (Two Pointer) Operations Menu:" << endl;
        cout << "1. Print List" << endl;
        cout << "2. Get List Size" << endl;
        cout << "3. Insert at Start" << endl;
        cout << "4. Insert at End" << endl;
        cout << "5. Insert After Value" << endl;
        cout << "6. Insert Before Value" << endl;
        cout << "7. Sorted Insertion (Increasing)" << endl; 
        cout << "8. Sorted Insertion (Decreasing)" << endl; 
        cout << "9. Delete First Node" << endl;
        cout << "10. Delete Last Node" << endl;
        cout << "11. Delete Kth Node" << endl;
        cout << "12. Delete First Occurrence of Value" << endl;
        cout << "13. Delete Kth Occurrence of Value" << endl;
        cout << "14. Delete All Occurrences of Value" << endl;
        cout << "15. Reverse List" << endl;
        cout << "16. Print List in Reverse" << endl;
        cout << "17. Exit" << endl;
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
            cout << "Enter value for Sorted Insertion (Increasing): ";
            characterValidation(value);
            list.sortedInsertionIncreasing(value);
            list.print();
            break;
        case 8:
            cout << "Enter value for Sorted Insertion (Decreasing): ";
            characterValidation(value);
            list.sortedInsertionDecreasing(value);
            list.print();
            break;
        case 9:
            list.deleteFirstNode();
            list.print();
            break;
        case 10:
            list.deleteLastNode();
            list.print();
            break;
        case 11:
            cout << "Enter the node position (k) to delete: ";
            positiveValidation(k);
            list.deleteKthNode(k);
            list.print();
            break;
        case 12:
            cout << "Enter value to delete first occurrence of: ";
            characterValidation(x);
            list.deleteFirstOccurrenceOfXNode(x);
            list.print();
            break;
        case 13:
            cout << "Enter value to delete: ";
            characterValidation(x);
            cout << "Enter the occurrence to delete (k): ";
            positiveValidation(k);
            list.deleteKthOccurrenceOfXNode(x, k);
            list.print();
            break;
        case 14:
            cout << "Enter value to delete all occurrences of: ";
            characterValidation(x);
            list.deleteAllOccurrencesOfXNode(x);
            list.print();
            break;
        case 15:
            cout << "Original ";
            list.print();
            cout << "Reversed ";
            list.reverseList();
            list.print();
            break;
        case 16:
            cout << "Original ";
            list.print();
            cout << "Reversed ";
            list.printReverse();
            break;
        case 17:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice, please try again." << endl;
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
