#include <bits/stdc++.h>
#include "BT.cpp"
using namespace std;

// bool checkIfTwoTreesAreEqual(TreeNode *t1, TreeNode *t2)
// {
//     if (!t1 && !t2)
//         return true;
//     if (!t1 || !t2)
//         return false;

//     if (t1->val != t2->val)
//         return false;

//     return checkIfTwoTreesAreEqual(t1->left, t2->left) && checkIfTwoTreesAreEqual(t1->right, t2->right);
// }


bool isSubtree(TreeNode *t1, TreeNode *t2)
{
    if (!t1 && !t2)
        return true;
    if (!t1 || !t2)
        return false;

    if (t1->val == t2->val)
        return isSubtree(t1->left, t2->left) && isSubtree(t1->right, t2->right);

    return isSubtree(t1->left, t2) || isSubtree(t1->right, t2);
}

int main()
{
    vector<int> v1 = {30, 20, 40};
    TreeNode *root1 = nullptr;
    for (int i = 0; i < v1.size(); i++)
        root1 = insertIntoBST(root1, v1[i]);
    print(root1);

    cout << "\n\n";
    vector<int> v2 = {30, 20, 40};
    TreeNode *root2 = nullptr;
    for (int i = 0; i < v2.size(); i++)
        root2 = insertIntoBST(root2, v2[i]);
    print(root2);

    if (isSubtree(root1, root2))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}