#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void characterValidation(T &);

void Insertion_Sort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && v[j - 1] > v[j])
        {
            swap(v[j - 1], v[j]);
            j--;
        }
    }
}

vector<int> sortedInsertion(vector<int> &v, int value)
{
    vector<int> result;
    bool inserted = false;

    for (int i = 0; i < v.size(); i++)
    {
        if (!inserted && v[i] > value)
        {
            result.push_back(value);
            inserted = true;
        }
        result.push_back(v[i]);
    }

    if (!inserted)
        result.push_back(value);

    return result;
}

void print(vector<int> &v)
{
    for (int i : v)
        cout << i << " ";
    cout << endl;
}

int main()
{
    system("cls");
    vector<int> v;
    int value;

    cout << "--> Insertion Sort Implementation" << endl;

    cout << "Enter elements of array (enter -923 to stop):" << endl;
    while (true)
    {
        int num;
        characterValidation(num);
        if (num == -923)
            break;
        v.push_back(num);
    }

    cout << endl;
    cout << "Input Array : ";
    print(v);
    cout << endl;

    cout << "Sorted Array : ";
    Insertion_Sort(v);
    print(v);
    cout << endl;

    cout << "Enter a number to insert: ";
    characterValidation(value);
    cout << endl;

    vector<int> newArray = sortedInsertion(v, value);

    cout << "New array: ";
    print(newArray);
    cout << endl;
    system("pause");
    cout << endl;
    return 0;
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
