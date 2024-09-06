#include <bits/stdc++.h>
#include "BT.h"
using namespace std;

/*
Solution: 
1. Check in between range of all nodes with range of root starting from INT_MIN to INT_MAX.
2. The left subtree of a node contains only nodes with values less than the node's value.
3. The right subtree of a node contains only nodes with values greater than the node's value.
*/

bool solve(TreeNode *root, int left, int right)
{
    if (root == nullptr)
        return true;
    if (root->val <= left || root->val >= right)
        return false;
    return solve(root->left, left, root->val) && solve(root->right, root->val, right);
}

bool isValidBST(TreeNode *root)
{
    return solve(root, INT_MIN, INT_MAX);
}

int main()
{
    char choice;
    do
    {
        system("cls");
        cout << "----------> Valid BST <----------" << endl;
        BinaryTree tree;
        tree.insertLevelOrder();
        cout << "Tree structure:\n" << endl;
        tree.print(tree.root);
        cout << "\n\n";

        if (isValidBST(tree.root))
            cout << "The tree is a valid BST." << endl;
        else
            cout << "The tree is not a valid BST." << endl;

        cout << endl;
        system("pause");
        system("cls");
        cout << "Do you want to continue? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Exiting the program." << endl;
    return 0;
}

