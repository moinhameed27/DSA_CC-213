#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

/*
Solution:
1. Recursively call the removeKeysInRange function for the left and right subtrees.
2. If the root value is outside the range, delete the node and return the new root.
3. If the root value is not outside the range, return the root as it is.
4. Finally, return the root of the BST.
*/

TreeNode *removeKeysOutsideRange(TreeNode *root, int min, int max)
{
    if (!root)
        return NULL;
    root->left = removeKeysOutsideRange(root->left, min, max);
    root->right = removeKeysOutsideRange(root->right, min, max);
    if (root->val < min || root->val > max)
        return deleteNode(root, root->val);
    return root;
}

int main()
{
    char choice;
    int k, ans;
    do
    {
        system("cls");
        cout << "----------> Remove Keys Outside Range <----------" << endl;
        BinarySearchTree tree;
        int val;

        cout << "Enter Tree values to insert into the BST (enter -23 to stop):" << endl;
        while (true)
        {
            numberValidation(val);
            if (val == -23)
                break;
            tree.insert(val);
        }

        cout << "\nTree structure:\n"
             << endl;
        tree.print(tree.root);

        int min, max;
        cout << "\nEnter the range to remove keys from the BST: ";
        cout << "\nMin: ";
        numberValidation(min);
        cout << "Max: ";
        numberValidation(max);

        tree.root = removeKeysOutsideRange(tree.root, min, max);
        cout << "\nTree structure after removing keys outside the range:\n"
             << endl;
        tree.print(tree.root);

        cout << endl;
        system("pause");
        system("cls");
        cout << "\nDo you want to continue? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Exiting the program." << endl;
    return 0;
}
