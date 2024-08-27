#include <iostream>
#include <vector>
using namespace std;

vector<int> buildMaximumBinaryTree(vector<int> &nums)
{
    vector<int> tree;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        tree.push_back(nums[i]);
        int idx = i;
        while (idx > 0)
        {
            int parent = (idx - 1) / 2;
            if (tree[parent] < tree[idx])
            {
                swap(tree[parent], tree[idx]);
                idx = parent;
            }
            else
                break;
        }
    }
    return tree;
}

// Output: [6,3,5,-1,2,0,-1,-1,1]

int main()
{
    vector<int> nums = {5, 4, 3, 2, 1};
    vector<int> tree = buildMaximumBinaryTree(nums);
    for (int i = 0; i < tree.size(); i++)
        cout << tree[i] << " ";
    return 0;
}