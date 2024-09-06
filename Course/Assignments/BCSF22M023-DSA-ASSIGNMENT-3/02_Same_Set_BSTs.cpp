#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

/*
Solution:
--> Current Approach: For all the elements in tree1, check if they are present in tree2 and vice versa.
Went for the Recursive Approach, further approaches:
1. Push all elements into priority queue and compare the two priority queues.
2. Inorder traversal of both trees and compare the two arrays. (Inorder Traversel of BST gives sorted Array)
*/

bool find(TreeNode *root, int val)
{
    if (!root)
        return false;
    if (root->val == val)
        return true;
    if (val < root->val)
        return find(root->left, val);
    return find(root->right, val);
}

bool checkAllValues(TreeNode *root1, TreeNode *root2)
{
    if (!root1)
        return true;
    if (!find(root2, root1->val))
        return false;
    return checkAllValues(root1->left, root2) && checkAllValues(root1->right, root2);
}

bool sameSet(TreeNode *root1, TreeNode *root2)
{
    if(!root1 && !root2)
        return true;
    if(!root1 || !root2)
        return false;

    return checkAllValues(root1, root2) && checkAllValues(root2, root1);
}



int main()
{
    char choice;
    do
    {
        system("cls");
        cout << "----------> SAME SET OF VALUES IN TWO BSTs <----------" << endl;
        BinarySearchTree tree1, tree2;
        int val;

        cout << "Enter Tree 1 values to insert into the BST (enter -23 to stop):" << endl;
        while (true)
        {
            numberValidation(val);
            if (val == -23)
                break;
            tree1.insert(val);
        }

        cout << "Enter Tree 2 values to insert into the BST (enter -23 to stop):" << endl;
        while (true)
        {
            numberValidation(val);
            if (val == -23)
                break;
            tree2.insert(val);
        }

        cout << "\nTree 1 structure:\n" << endl;
        tree1.print(tree1.root);

        cout << "Tree 2 structure:\n" << endl;
        tree2.print(tree2.root);

        if(sameSet(tree1.root, tree2.root))
            cout << "\nBoth trees have the same set of values." << endl;
        else
            cout << "\nBoth trees do not have the same set of values." << endl;

        cout << endl;
        system("pause");
        system("cls");
        cout << "\nDo you want to continue? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Exiting the program." << endl;
    return 0;
}
