#include <iostream>
#include <fstream>
#include <vector>
#include "Queue.h"
using namespace std;

template <typename T>
T numberValidation(T &);

void pageHitsAndFaults(int n, vector<int> sequence)
{
    Queue<int> queue;
    int pageHits = 0, pageFaults = 0;
    for (int request : sequence)
    {
        // queue.print();
        if (queue.is_present(request))
        {
            // cout << "Page Hit for " << request << endl;
            pageHits++;
            Queue<int> tempQueue;
            while (!queue.is_empty())
            {
                int frontOfQueue = queue.dequeue();
                if (frontOfQueue != request)
                    tempQueue.enqueue(frontOfQueue);
            }
            tempQueue.enqueue(request);
            while (!tempQueue.is_empty())
                queue.enqueue(tempQueue.dequeue());
        }
        else
        {
            if (queue.size() == n)
                queue.dequeue();
            // cout << "Page Fault for " << request << endl;
            pageFaults++;
            queue.enqueue(request);
        }
    }
    cout << "\nPage Hits: " << pageHits << endl;
    cout << "Page Faults: " << pageFaults << endl;
}

int main()
{
    system("cls");
    cout << "----------> LRU <----------" << endl;
    int n, num;
    cout << "Enter the number of page frames: ";
    numberValidation(n);
    vector<int> sequence;
    cout << "Enter the sequence of page requests (enter 23 to exit):" << endl;
    while (true)
    {
        while (true)
        {
            numberValidation(num);
            if ((num >= 1 && num <= 9) || num == 23)
                break;
            else
                cout << "Invalid input. Please enter a number between 1 and 9." << endl;
        }
        if (num == 23)
            break;
        sequence.push_back(num);
    }
    cout << endl;
    pageHitsAndFaults(n, sequence);
    cout << endl;
    system("pause");
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
            if (number < 0)
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
    return number;
}
