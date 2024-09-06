#include <bits/stdc++.h>
#include "BT.h"
using namespace std;

/*
Soltuion:
1. Recursively find the height of the left and right subtree.
2. The height of the tree is the maximum of the height of the left and right subtree + 1.
*/

int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
}

int main()
{
    char choice;
    do
    {
        system("cls");
        cout << "----------> Height of Binary Tree <----------" << endl;
        BinaryTree tree;
        tree.insertLevelOrder();
        cout << "Tree structure:\n"
             << endl;
        tree.print(tree.root);
        cout << "\n\n";

        cout << "Height of the tree: " << maxDepth(tree.root) << endl;

        cout << endl;
        system("pause");
        system("cls");
        cout << "Do you want to continue? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Exiting the program." << endl;
    return 0;
}
