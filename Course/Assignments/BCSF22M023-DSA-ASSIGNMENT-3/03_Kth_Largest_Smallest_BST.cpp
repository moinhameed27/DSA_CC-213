#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

/*
Solution:
1. Inorder traversal of BST gives elements in sorted order.
2. To find the kth smallest element, we need to do inorder traversal.
3. To find the kth largest element, we need to do reverse inorder traversal.
*/

void inorderReverse(TreeNode *root, int &k, int &result)
{
    if (!root || k == 0)
        return;
    inorderReverse(root->right, k, result);
    k--;
    if (k == 0)
    {
        result = root->val;
        return;
    }
    inorderReverse(root->left, k, result);
}

void inorder(TreeNode *root, int &k, int &result)
{
    if (!root || k == 0)
        return;
    inorder(root->left, k, result);
    k--;
    if (k == 0)
    {
        result = root->val;
        return;
    }
    inorder(root->right, k, result);
}

int kthLargest(TreeNode *root, int k)
{
    int ans = -1;
    inorderReverse(root, k, ans);
    return ans;
}

int kthSmallest(TreeNode *root, int k)
{
    int ans = -1;
    inorder(root, k, ans);
    return ans;
}

int main()
{
    char choice;
    int k, ans;
    do
    {
        system("cls");
        cout << "----------> Kth Largest and Smallest <----------" << endl;
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


        cout << "\nTree structure:\n" << endl;
        tree.print(tree.root);

        cout << "Enter the value of k: ";
        positiveValidation(k);
        cout << endl;

        ans = kthLargest(tree.root, k);
        if(ans == -1)
            cout << "Kth largest element not found." << endl;
        else
            cout << "Kth largest element in the BST: " << ans << endl;
        cout << endl;

        ans = kthSmallest(tree.root, k);
        if(ans == -1)
            cout << "Kth smallest element not found." << endl;
        else
            cout << "Kth smallest element in the BST: " << ans << endl;

        cout << endl;
        system("pause");
        system("cls");
        cout << "\nDo you want to continue? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Exiting the program." << endl;
    return 0;
}
