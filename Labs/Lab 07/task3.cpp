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
    BinaryTree tree(size + 1); 

    for (size_t i = 0; i < size; i++)
    {
        int input;
        cin >> input;
        tree.insert(input);
    };

    cout << endl
         << endl;
    tree.printParenthesis(1);
    return 0;
}
