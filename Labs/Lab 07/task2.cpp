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
            tree[i] = -1;
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
    void recursivetree(int node, int *arr, int low, int high)
    {
        if (low < high)
        {
            int max = INT_MIN;
            int index = 0;
            for (size_t i = low; i <= high; i++)
            {
                if (arr[i] > max)
                {
                    max = arr[i];
                    index = i;
                }
            }
            tree[node] = max;
            recursivetree(2 * node, arr, low, index - 1);
            recursivetree(2 * node + 1, arr, index + 1, high);
        }
        else if (low == high)
            tree[node] = arr[low];
        else
            tree[node] = -1;
    }
    void printParenthesis(int node)
    {

        if (tree[node] != -1)
        {
            cout << tree[node];
            bool flag = false;

            if (2 * node < size && tree[2 * node] != -1)
            {
                cout << "(";
                printParenthesis(2 * node);
                flag = true;
            }
            if (2 * node + 1 < size && tree[2 * node + 1] != -1)
            {
                if (flag)
                    cout << ",";
                else
                {
                    cout << "(";
                    flag = true;
                }
                printParenthesis(2 * node + 1);
            }
            if (flag)
                cout << ")";
        }
    }
};

int main()
{
    int size = 0;
    cin >> size;
    int *arr = new int[size];

    for (size_t i = 0; i < size; i++)
    {
        int input;
        cin >> arr[i];
    }
    BinaryTree tree(100);
    tree.print();
    cout << "\n\n";
    tree.recursivetree(1, arr, 0, size - 1);
    tree.printParenthesis(1);
    return 0;
}
