/* Saif (BCSF22M026) */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class BinaryTree
{
private:
    int *tree;
    int currentSize;
    int size;

public:
    BinaryTree(int capacity)
    {
        size = capacity;
        tree = new int[size]; 

        currentSize = 0;
        for (int i = 0; i < size; i++)
            tree[i] = 0;
    }

    ~BinaryTree()
    {
        delete[] tree; 
    }

    void insert(int key)
    {

        tree[++currentSize] = key;
    }

    void print()
    {

        for (size_t i = 1; i < size; i++)
            cout << tree[i] << " ";
        cout << endl;
    }

    int sum(int node)
    {
        if (2 * node < size && 2 * node + 1 < size)
            return tree[node] + sum(2 * node) + sum(2 * node + 1);
        else if (2 * node < size)
            return tree[node] + sum(2 * node);
        else
            return tree[node];
    }
    int tilt(int node)
    {
        if (2 * node < size && 2 * node + 1 < size)
            tree[node] = abs(sum(2 * node) - sum(2 * node + 1));
        else if (2 * node < size)
            tree[node] = sum(2 * node);
        else
            tree[node] = 0;
        if (2 * node < size && 2 * node + 1 < size)
            return tree[node] + tilt(2 * node) + tilt(2 * node + 1);
        else if (2 * node < size)
            return tree[node] + tilt(2 * node);
        else
            return tree[node];
    }
};

int main()
{
    int size = 0;
    cin >> size;
    BinaryTree tree(size + 1); // Creates a binary tree with a maximum height of 4

    for (size_t i = 0; i < size; i++)
    {
        int input;
        cin >> input;
        tree.insert(input);
    }
    cout << "Ans : " << tree.tilt(1);
    cout << endl
         << endl;
    return 0;
}
