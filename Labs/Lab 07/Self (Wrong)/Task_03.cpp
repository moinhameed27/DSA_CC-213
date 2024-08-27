#include <iostream>
#include <vector>
using namespace std;

void displayParenthesizedView(vector<int> tree, int idx, int n)
{
    if (idx >= n)
        return;
    cout << tree[idx];
    if (idx * 2 < n)
    {
        if(tree[idx * 2] != -1)
        {
            cout << "(";
            displayParenthesizedView(tree, idx * 2, n);
            cout << ",";
        }
        if(tree[(idx * 2) + 1] != -1)
        {
            displayParenthesizedView(tree, (idx * 2) + 1, n);
            cout << ")";
        }
    }
}

int main()
{
    int n = 12;
    vector<int> arr = {0, 10, 20, 30, 40, -1, -1, 50, -1, -1, -1, 60};
    displayParenthesizedView(arr, 1, n);
    return 0;
}