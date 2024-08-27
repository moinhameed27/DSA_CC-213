#include <bits/stdc++.h>
#include "BT.cpp"
using namespace std;

bool find(TreeNode *root, int target)
{
    if(!root)
        return root;
    if(root->val == target)
        return root;
    if(root->val < target)
        return find(root->right, target);
    else
        return find(root->left, target);
}

bool solve(TreeNode *root, int target, int &k, int &ans)
{
    if(!root)
        return false;
    if(root->val == target)
        return true;
    if(solve(root->left, target, k, ans) || solve(root->right, target, k, ans))
    {
        k--;
        if(k == 0)
        {
            ans = root->val;
            return false;
        }
        return true;
    }
    return false;
}

int findKthAncestor(TreeNode *root, int target, int k)
{
    int ans = -1;
    if(!find(root, target))
        return ans;
    if(k == 0)
        return target;
    solve(root, target, k, ans);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {20, 10, 30, 5, 15};
    TreeNode *root = insertIntoBST(nullptr, arr[0]);
    for(int i = 1; i < arr.size(); i++)
        insertIntoBST(root, arr[i]);
    print(root);

    cout << findKthAncestor(root, 5, 3) << endl;

return 0;
}