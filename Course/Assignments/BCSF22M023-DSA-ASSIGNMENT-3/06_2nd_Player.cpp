#include <bits/stdc++.h>
#include "BT.h"
using namespace std;

/*
Solution:
1. Build Max Heap from the given array.
2. Swap the first element with the last element.
3. Build Max Heap from the remaining elements.
4. Count number of swaps when building heap.
*/

void heapify(vector<int> &arr, int n, int i, int &ans)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;


    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // cout << "arr[i] : " << arr[i] << " arr[largest] : " << arr[largest] << endl;
        // print(arr, n);
        ans++;
        heapify(arr, n, largest, ans);
    }
}

void heapSort(vector<int> &arr, int n, int &ans)
{
    for (int i = n / 2; i >= 0; i--)
        heapify(arr, n, i, ans);
}

void print(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    char choice;
    do
    {
        system("cls");
        cout << "----------> 2nd Best Player <----------" << endl;
        vector<int> heap;
        int score, n, comparisons = 0;
        cout << "Enter the scores of Players (-23 to stop entering): " << endl;
        while(true)
        {
            numberValidation(score);
            if(score == -23)
                break;
            heap.push_back(score);
        }
        n = heap.size();

        cout << endl;
        print(heap, n);

        heapSort(heap, n, comparisons);
        swap(heap[0], heap[n - 1]);
        heapSort(heap, n - 1, comparisons);

        cout << "\nComparisons: " << comparisons << endl;
        cout << endl;
        
        system("pause");
        system("cls");
        cout << "Do you want to continue? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Exiting the program." << endl;
    return 0;
}
