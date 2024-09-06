#include <bits/stdc++.h>
#include "BT.h"
using namespace std;

/*
Solution:
1. The boundary nodes are the nodes that are part of the boundary of the tree.
2. The boundary nodes are divided into three parts:
    a. Left boundary nodes
    b. Leaf nodes
    c. Right boundary nodes
3. The left boundary nodes are the nodes that are the leftmost nodes of each level.
4. The leaf nodes are the nodes that do not have any children.
5. The right boundary nodes are the nodes that are the rightmost nodes of each level.
6. The boundary nodes are printed in the following order:
    a. Root node
    b. Left boundary nodes
    c. Leaf nodes of left subtree
    d. Leaf nodes of right subtree
    e. Right boundary nodes
*/

void printLeftBoundary(TreeNode *root)
{
    if (!root || (!root->left && !root->right))
        return;
    cout << root->val << " ";
    if (root->left)
        printLeftBoundary(root->left);
    else
        printLeftBoundary(root->right);
}

void printLeaves(TreeNode *root)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        cout << root->val << " ";
        return;
    }
    printLeaves(root->left);
    printLeaves(root->right);
}

void printRightBoundary(TreeNode *root)
{
    if (!root || (!root->left && !root->right))
        return;
    if (root->right)
        printRightBoundary(root->right);
    else
        printRightBoundary(root->left);
    cout << root->val << " ";
}

void printBoundary(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    printLeftBoundary(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printRightBoundary(root->right);
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
        cout << "Tree structure:" << endl;
        tree.print(tree.root);

        cout << "\nBoundary nodes are: ";
        printBoundary(tree.root);

        cout << endl;
        system("pause");
        system("cls");
        cout << "Do you want to continue? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Exiting the program." << endl;
    return 0;
}
