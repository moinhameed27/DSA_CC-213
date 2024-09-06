#include <bits/stdc++.h>
#include "BT.h"
using namespace std;

/*
Solution:
1. Perform inorder traversal of the binary tree and store the values in a vector.
2. Apply heap sort on the vector.
    a. Build a max heap.
    b. Swap the root element with the last element of the heap.
    c. Heapify the heap.
3. Return the sorted vector.
*/

// Check for the largest element in the children and swap it with the root
void heapify(vector<int> &arr, int n, int i)
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
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();

    // Build Max-Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap Sort
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Storing values into vector
void postOrderTraversal(TreeNode *root, vector<int> &values)
{
    if (!root)
        return;
    postOrderTraversal(root->left, values);
    postOrderTraversal(root->right, values);
    values.push_back(root->val);
}

vector<int> sortBinaryTree(TreeNode *root)
{
    vector<int> values;
    postOrderTraversal(root, values);
    heapSort(values);
    return values;
}

int main()
{
    char choice;
    do
    {
        system("cls");
        cout << "----------> Heap Sort <----------" << endl;
        BinaryTree tree;
        tree.insertLevelOrder();
        cout << "Tree structure:\n" << endl;
        tree.print(tree.root);
        cout << "\n\n";

        vector<int> sortedValues = sortBinaryTree(tree.root);
        cout << "Sorted values of the tree: ";
        for (int val : sortedValues)
            cout << val << " ";

        cout << "\n\n";
        system("pause");
        system("cls");
        cout << "Do you want to continue? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Exiting the program." << endl;
    return 0;
}
