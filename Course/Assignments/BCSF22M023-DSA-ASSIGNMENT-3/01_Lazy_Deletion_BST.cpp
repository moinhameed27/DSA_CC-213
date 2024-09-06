#include <bits/stdc++.h>
using namespace std;

template <typename T>
void positiveValidation(T &);
template <typename T>
void numberValidation(T &);

/*
Solution:
1. Every node contains a boolean flag isDeleted to mark the node as deleted.
2. The lazyDelete() function marks the node as deleted.
3. The cleanup() function removes all the nodes marked as deleted.
*/

struct TreeNode
{
    int val;
    bool isDeleted;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), isDeleted(false), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), isDeleted(false), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), isDeleted(false), left(left), right(right) {}
};

class BinarySearchTree
{
public:
    TreeNode *root;

    BinarySearchTree() : root(nullptr) {}

    TreeNode *insertIntoBST(TreeNode *node, int val)
    {
        if (node == nullptr)
            return new TreeNode(val);
        if (val <= node->val)
            node->left = insertIntoBST(node->left, val);
        else
            node->right = insertIntoBST(node->right, val);
        return node;
    }

    void insert(int val)
    {
        root = insertIntoBST(root, val);
    }

    void lazyDelete(int val)
    {
        TreeNode *node = search(root, val);
        if (node)
            node->isDeleted = true;
    }

    void cleanup()
    {
        root = cleanupHelper(root);
    }

    void print(TreeNode *node, int depth = 0)
    {
        if (!node)
            return;

        print(node->right, depth + 1);

        for (int i = 0; i < depth; i++)
            cout << "\t";

        if (node->isDeleted)
            cout << "[" << node->val << "]" << endl;
        else
            cout << node->val << endl;

        print(node->left, depth + 1);
    }

    ~BinarySearchTree()
    {
        clear(root);
        root = nullptr;
    }

    void clear(TreeNode *node)
    {
        if (node == nullptr)
            return;

        clear(node->left);
        clear(node->right);

        delete node;
    }

private:
    TreeNode *search(TreeNode *node, int val)
    {
        if (!node || node->val == val)
            return node;
        if (val < node->val)
            return search(node->left, val);
        return search(node->right, val);
    }

    TreeNode *cleanupHelper(TreeNode *node)
    {
        if (!node)
            return nullptr;
        node->left = cleanupHelper(node->left);
        node->right = cleanupHelper(node->right);
        if (node->isDeleted)
        {
            delete node;
            return nullptr;
        }
        return node;
    }
};

int main()
{
    char choice;
    BinarySearchTree tree;
    int val;
    int option;
    while (option != 5)
    {
        system("cls");
        cout << "---------- Lazy Deletion in Binary Search Tree ----------" << endl;
        cout << endl;
        cout << "Choose an option:" << endl;
        cout << "1. Insert values into the BST" << endl;
        cout << "2. Display tree structure" << endl;
        cout << "3. Perform lazy deletion" << endl;
        cout << "4. Cleanup deleted nodes" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        numberValidation(option);
        cout << endl;

        switch (option)
        {
        case 1:
            cout << "Enter values to insert into the BST (enter -23 to stop):" << endl;
            while (true)
            {
                numberValidation(val);
                if (val == -23)
                    break;
                tree.insert(val);
            }
            break;

        case 2:
            cout << "Tree structure:\n" << endl;
            tree.print(tree.root);
            break;

        case 3:
            cout << "Enter a value to lazy delete (enter -23 to skip): ";
            numberValidation(val);
            if (val != -23)
            {
                tree.lazyDelete(val);
                cout << "Tree after lazy deletion:\n" << endl;
                tree.print(tree.root);
            }
            break;

        case 4:
            cout << "Cleaning up deleted nodes...\n" << endl;
            tree.cleanup();
            cout << "Tree after cleanup:\n" << endl;
            tree.print(tree.root);
            break;

        case 5:
            cout << "Exiting the program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            break;
        }
        cout << endl;
        cout << endl;
        system("pause");

    }

    cout << "Exiting the program." << endl;
    return 0;
}

template <typename T>
void positiveValidation(T &number)
{
    bool validInput = false;
    while (!validInput)
    {
        if (cin >> number)
        {
            if (number <= 0)
                cout << "Enter a positive number: " << endl;
            else
                validInput = true;
        }
        else
        {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Invalid input. Please enter a valid number." << endl;
        }
    }
}

template <typename T>
void numberValidation(T &number)
{
    bool validInput = false;
    while (!validInput)
    {
        if (cin >> number)
            validInput = true;
        else
        {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Invalid input. Please enter a valid number." << endl;
        }
    }
}
