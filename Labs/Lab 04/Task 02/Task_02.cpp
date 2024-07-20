#include <iostream>
#include <vector>
#include "Priority_Queue_Inc.h"
using namespace std;

template <typename T>
void characterValidation(T &);

void print(vector<int> &v)
{
    for(int i : v)
        cout << i << " ";
    cout << endl;
}


int main()
{
    vector<int> v1, v2;
    cout << "Enter Array 1 Elements in sorted order (Enter -923 to stop):" << endl;
    while(true)
    {   
        int num;
        characterValidation(num);
        if(num == -923)
            break;
        v1.push_back(num);
    }

    cout << "Enter Array 2 Elements in sorted order (Enter -923 to stop):" << endl;
    while(true)
    {   
        int num;
        characterValidation(num);
        if(num == -923)
            break;
        v2.push_back(num);
    }

    cout << "Array 1 : ";
    print(v1);
    cout << endl;

    cout << "Array 2 : ";
    print(v2);
    cout << endl;


    Queue q;
    for(int i : v1)
        q.enqueue(i);
    
    for(int i : v2)
        q.enqueue(i);
    
    vector<int> ans;
    while(q.size() > 0)
        ans.push_back(q.peek_front()), q.dequeue();
    
    cout << "Resultant Array : ";
    print(ans);

    
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