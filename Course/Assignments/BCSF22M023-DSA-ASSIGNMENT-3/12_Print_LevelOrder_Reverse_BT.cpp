#include <bits/stdc++.h>
#include "BT.h"
using namespace std;

/*
Solution:
1. Do level order traversal and store the nodes in a stack.
    ~ In Normal Level Order (Root, Left, Right), pushing nodes in a stack will give the nodes in reverse level order.
    ~ So, we will do reverse level order traversal : Root, Right, Left.
2. After the traversal, the stack will have the nodes in reverse level order.
3. Pop the elements from the stack and print them.
*/

void reverseLevelOrder(TreeNode *root)
{
    if (!root)
        return;

    queue<TreeNode *> q;    // Queue for Level order Traversal
    stack<TreeNode *> s;    // Stack for storing the nodes in reverse level order
    q.push(root);

    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();
        s.push(front);

        if (front->right)
            q.push(front->right);
        if (front->left)
            q.push(front->left);
    }

    while (!s.empty())
    {
        cout << s.top()->val << " ";
        s.pop();
    }
}

int main()
{
    char choice;
    do
    {
        system("cls");
        cout << "----------> Reverse Level Order <----------" << endl;
        BinaryTree tree;
        tree.insertLevelOrder();
        cout << "Tree structure:\n"
             << endl;
        tree.print(tree.root);
        cout << "\n\n";

        cout << "Reverse Level Order: ";
        reverseLevelOrder(tree.root);

        cout << endl;
        system("pause");
        system("cls");
        cout << "Do you want to continue? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Exiting the program." << endl;
    return 0;
}
