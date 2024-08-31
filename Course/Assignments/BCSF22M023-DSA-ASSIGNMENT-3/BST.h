#ifndef BST_H
#define BST_H

#include <bits/stdc++.h>
using namespace std;

template <typename T>
void positiveValidation(T &);
template <typename T>
void numberValidation(T &);

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinarySearchTree
{
public:
    TreeNode *root;

    BinarySearchTree()
    {
        root = nullptr;
    }

    TreeNode *insertIntoBST(TreeNode *node, int val)
    {
        if (node == nullptr)
            return new TreeNode(val);
        if (val <= node->val)
            node->left = insertIntoBST(node->left, val);
        else
            node->right = insertIntoBST(node->right, val);
        return node;
    }

    void insert(int val)
    {
        root = insertIntoBST(root, val);
    }

    void insertFromList(const vector<int> &values)
    {
        for (int val : values)
        {
            root = insertIntoBST(root, val);
        }
    }

    void print(TreeNode *node, int depth = 0)
    {
        if (!node)
            return;

        print(node->right, depth + 1);

        for (int i = 0; i < depth; i++)
            cout << "\t";

        cout << node->val << endl;

        print(node->left, depth + 1);
    }

    void preOrderDisplay(TreeNode *node)
    {
        if (node == nullptr)
            return;
        cout << node->val << " ";
        preOrderDisplay(node->left);
        preOrderDisplay(node->right);
    }

    void inOrderDisplay(TreeNode *node)
    {
        if (node == nullptr)
            return;
        inOrderDisplay(node->left);
        cout << node->val << " ";
        inOrderDisplay(node->right);
    }

    void postOrderDisplay(TreeNode *node)
    {
        if (node == nullptr)
            return;
        postOrderDisplay(node->left);
        postOrderDisplay(node->right);
        cout << node->val << " ";
    }

    void levelOrderDisplay(TreeNode *node)
    {
        if (node == nullptr)
            return;
        queue<TreeNode *> q;
        q.push(node);
        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();
            cout << current->val << " ";
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }

    ~BinarySearchTree()
    {
        clear(root);
    }

    void clear(TreeNode *node)
    {
        if (node == nullptr)
            return;

        clear(node->left);
        clear(node->right);

        delete node;
    }
};

int findSuccessor(TreeNode *root)
{
    while (root->left)
        root = root->left;
    return root->val;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return nullptr;
    if (key < root->val)
        root->left = deleteNode(root->left, key);

    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else
    {
        if (!root->left && !root->right)
            return nullptr;

        if (!root->left)
            return root->right;
        if (!root->right)
            return root->left;

        root->val = findSuccessor(root->right);
        root->right = deleteNode(root->right, root->val);
    }
    return root;
}

template <typename T>
void positiveValidation(T &number)
{
    bool validInput = false;
    while (!validInput)
    {
        if (cin >> number)
        {
            if (number <= 0)
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
}

template <typename T>
void numberValidation(T &number)
{
    bool validInput = false;
    while (!validInput)
    {
        if (cin >> number)
            validInput = true;
        else
        {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Invalid input. Please enter a valid number." << endl;
        }
    }
}

#endif
