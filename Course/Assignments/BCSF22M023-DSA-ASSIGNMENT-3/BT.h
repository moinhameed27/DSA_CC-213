#ifndef BT_H
#define BT_H

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

class BinaryTree
{
public:
    TreeNode *root;

    BinaryTree()
    {
        root = nullptr;
    }

    void insertLevelOrder()
    {
        int val;
        cout << "Enter root value: ";
        numberValidation(val);

        if (val == -23)
            return;

        root = new TreeNode(val);
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();

            // Insert left child
            cout << "Enter left child of " << current->val << " (-23 for no node): ";
            numberValidation(val);
            if (val != -23)
            {
                current->left = new TreeNode(val);
                q.push(current->left);
            }

            // Insert right child
            cout << "Enter right child of " << current->val << " (-23 for no node): ";
            numberValidation(val);
            if (val != -23)
            {
                current->right = new TreeNode(val);
                q.push(current->right);
            }
        }
    }

    TreeNode *insertInOrder()
    {
        int val;
        cout << "Enter node value (-23 for no node): ";
        numberValidation(val);

        if (val == -23)
            return nullptr;

        TreeNode *node = new TreeNode(val);

        cout << "Entering left child of " << val << endl;
        node->left = insertInOrder();

        cout << "Entering right child of " << val << endl;
        node->right = insertInOrder();

        return node;
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

    ~BinaryTree()
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