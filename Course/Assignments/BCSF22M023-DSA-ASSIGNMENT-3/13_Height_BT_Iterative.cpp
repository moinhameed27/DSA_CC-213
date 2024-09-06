#include <bits/stdc++.h>
#include "BT.h"
using namespace std;

/*
Solution:
1. Use a Stack to store the pair of TreeNode and its depth.
2. Push the root node and its depth into the stack.
3. While the stack is not empty, do the following:
    a. Pop the top element from the stack.
    b. If any of the child exists, push it into stack after increasing the depth otherwise update the answer.
*/

int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});
    int ans = 0;
    while (!st.empty())
    {
        pair<TreeNode *, int> top = st.top();
        st.pop();
        // If any of the child exists, push it into stack otherwise update the answer
        if (top.first->left)
            st.push({top.first->left, top.second + 1});
        if (top.first->right)
            st.push({top.first->right, top.second + 1});
        else
            ans = max(ans, top.second);
    }
    return ans;
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
