#include <bits/stdc++.h>
#include "BT.h"
using namespace std;

/*
Solution [DFS]:
1. Count the number of nodes in the tree.
2. For 0-based indexing, if tree is not a complete BT, there must be an index left empty and an index will be out of bounds.
3. If the tree is a complete BT, all the indexes will be filled.
--> For BFS, use a queue and maintain a flag to check if a node is encountered with no left or right child.
*/

// Function to count the number of nodes in the tree
int countNodes(TreeNode *root)  
{
    if (!root)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to check if the tree is a complete binary tree
bool solve(TreeNode *root, int index, int nodes)
{
    if (!root)
        return true;
    if (index >= nodes)
        return false;
    return solve(root->left, 2 * index + 1, nodes) && solve(root->right, 2 * index + 2, nodes);
}

bool isCompleteTree(TreeNode *root)
{
    return solve(root, 0, countNodes(root));
}

int main()
{
    char choice;
    do
    {
        system("cls");
        cout << "----------> Complete Binary Tree <----------" << endl;
        BinaryTree tree;
        tree.insertLevelOrder();
        cout << "Tree structure:\n" << endl;
        tree.print(tree.root);
        cout << "\n\n";
        
        if (isCompleteTree(tree.root))
            cout << "The tree is a complete binary tree." << endl;
        else
            cout << "The tree is not a complete binary tree." << endl;
        
        cout << endl;
        system("pause");
        system("cls");
        cout << "Do you want to continue? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Exiting the program." << endl;
    return 0;
}
