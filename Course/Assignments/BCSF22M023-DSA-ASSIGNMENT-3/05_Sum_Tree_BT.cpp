#include <bits/stdc++.h>
#include "BT.h"
using namespace std;

/*
Solution:
1. An empty tree is a sum tree.
2. A single node tree is a sum tree.
3. For a non-empty tree, we need to check the following conditions:
    a. The root node's value should be equal to the sum of the left subtree and the right subtree.
    b. The left subtree should be a sum tree.
    c. The right subtree should be a sum tree.
*/

// Helper Function : Counting the sum of subtree
int sum(TreeNode *root)
{
    if (!root)
        return 0;
    return sum(root->left) + root->val + sum(root->right);
}

bool isSumTree(TreeNode *root)
{
    // No Tree or Single Node Tree
    if (!root || (!root->left && !root->right))
        return true;
    int leftSum = sum(root->left);  // Left Subtree Sum
    int rightSum = sum(root->right);    // Right Subtree Sum
    return (root->val == leftSum + rightSum) && isSumTree(root->left) && isSumTree(root->right);
}

int main()
{
    char choice;
    do
    {
        system("cls");
        cout << "----------> Print Boundary Nodes <----------" << endl;
        BinaryTree tree;
        tree.insertLevelOrder();
        cout << "Tree structure:\n" << endl;
        tree.print(tree.root);
        cout << "\n\n";
        if (isSumTree(tree.root))
            cout << "The tree is a sum tree." << endl;
        else
            cout << "The tree is not a sum tree." << endl;

        cout << endl;
        system("pause");
        system("cls");
        cout << "Do you want to continue? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Exiting the program." << endl;
    return 0;
}
