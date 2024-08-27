#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == nullptr)
        return new TreeNode(val);
    if (val <= root->val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);
    return root;
}

void print(TreeNode *root, int depth = 0)
{
    if (!root)
        return;

    print(root->right, depth + 1);

    for (int i = 0; i < depth; i++)
        cout << "\t";

    cout << root->val << endl;

    print(root->left, depth + 1);
}

void preorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void levelOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     vector<int> v = {4, 2, 7, 1, 3};
//     TreeNode *root = nullptr;
//     for (int i = 0; i < v.size(); i++)
//         root = insertIntoBST(root, v[i]);
//     print(root);
//     return 0;
// }