#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void positiveValidation(T &);
template <typename T>
void numberValidation(T &);

class BinaryTree
{
private:
    int *tree;
    int size;
    int nullChild = -23;

public:
    // Constructor to initialize the tree array with the given number of levels 
    BinaryTree(int levels)
    {
        // [1 - based Indexing] leaving the 0th index unused
        size = (1 << levels);   // Equivalent to 2 ^ levels
        tree = new int[size];
        // Null Tree
        for (int i = 0; i < size; i++)
            tree[i] = nullChild;
    }

    // Destructor
    ~BinaryTree()
    {
        delete[] tree;
    }

    // Inserting elements into array with level order placement
    void insert()
    {
        cout << "\n* Enter " << nullChild << " for null child. *\n" << endl;
        cout << "Enter root value : ";
        numberValidation(tree[1]);

        for (int i = 1; i < size; i++)
        {
            // If the parent node is not null, then only ask for left and right child
            if (tree[i] != nullChild)
            {
                int leftChildIndex = 2 * i;
                int rightChildIndex = 2 * i + 1;

                if (leftChildIndex < size)
                {
                    cout << "Enter left child of " << tree[i] << " : ";
                    numberValidation(tree[leftChildIndex]);
                }

                if (rightChildIndex < size)
                {
                    cout << "Enter right child of " << tree[i] << " : ";
                    numberValidation(tree[rightChildIndex]);
                }
            }
        }
    }

    // Insert element at null children positions
    void insertElement()
    {
        int nullCount = 0;
        for (int i = 1; i < size; i++)
        {
            if (tree[i] == nullChild)
                nullCount++;
        }

        if (nullCount == 0)
        {
            cout << "Tree is full, cannot insert more elements." << endl;
            return;
        }

        cout << "Available null child positions: ";
        for (int i = 1; i < size; i++)
        {
            if (tree[i] == nullChild)
                cout << i << " ";
        }
        cout << endl;

        int position;
        cout << "Enter the position from available ones: ";
        numberValidation(position);
        int element;
        cout << "Enter element to insert: ";
        numberValidation(element);

        if (position < size && tree[position] == nullChild)
            tree[position] = element;
        else
            cout << "Invalid position or position already occupied!" << endl;
    }

    void deleteElement()
    {
        int level, position;
        cout << "Enter the level of the node to delete: ";
        positiveValidation(level);
        cout << "Enter the position of the node at that level: ";
        positiveValidation(position);

        int startIndex = (1 << (level - 1));    // Starting range of the level
        int endIndex = (1 << level) - 1;        // Ending range of the level
        int index = startIndex + position - 1;  // Entered index

        // If the index is valid, not null and in between range, then delete the element with its subtree
        if (index < size && tree[index] != nullChild && (index >= startIndex && index <= endIndex))
        {
            cout << "Element " << tree[index] << " deleted from the tree." << endl;
            nullifySubtree(index);
        }
        else
            cout << "Invalid position or element is already null!" << endl;
    }

    // Nullify the subtree of the given index
    void nullifySubtree(int index)
    {
        if (index >= size || tree[index] == nullChild)
            return;

        tree[index] = nullChild;

        int leftChildIndex = 2 * index;
        int rightChildIndex = 2 * index + 1;

        nullifySubtree(leftChildIndex);
        nullifySubtree(rightChildIndex);
    }

    // Edit the element at the given level and position
    void edit()
    {
        int level, position;
        cout << "Enter the level of the node to edit: ";
        positiveValidation(level);
        cout << "Enter the position of the node at that level: ";
        positiveValidation(position);

        int startIndex = (1 << (level - 1));
        int endIndex = (1 << level) - 1;

        int index = (1 << (level - 1)) + position - 1;
        if (index < size && tree[index] != nullChild && (index >= startIndex && index <= endIndex))
        {
            cout << "Current value: " << tree[index] << ", enter new value: ";
            numberValidation(tree[index]);
        }
        else
            cout << "Invalid position!" << endl;
    }

    // Find the index of the element in the tree
    int find(int element)
    {
        for (int i = 1; i < size; i++)
        {
            if (tree[i] == element)
                return i;
        }
        return -1;
    }

    // Get the right child of the given index
    int getRightChild(int index)
    {
        int rightChildIndex = 2 * index + 1;

        if (rightChildIndex < size && tree[rightChildIndex] != nullChild)
            return tree[rightChildIndex];
        return nullChild;
    }
     
    // Get the left child of the given index
    int getLeftChild(int index)
    {
        int leftChildIndex = 2 * index;

        if (leftChildIndex < size && tree[leftChildIndex] != nullChild)
            return tree[leftChildIndex];
        return nullChild;
    }

    // Get the parent of the given index
    int getParent(int index)
    {
        if (index <= 1 || index >= size)
            return nullChild;
        return tree[index / 2];
    }

    // In-order traversal of the tree
    vector<int> traverseInOrder(int index, vector<int> &inorder)
    {
        if (index >= size || tree[index] == nullChild)
            return inorder;

        traverseInOrder(2 * index, inorder);
        cout << tree[index] << " ";
        inorder.push_back(tree[index]);
        traverseInOrder(2 * index + 1, inorder);
        return inorder;
    }

    // Pre-order traversal of the tree
    vector<int> traversePreOrder(int index, vector<int> &preorder)
    {
        if (index >= size || tree[index] == nullChild)
            return preorder;

        preorder.push_back(tree[index]);
        cout << tree[index] << " ";
        traversePreOrder(2 * index, preorder);
        traversePreOrder(2 * index + 1, preorder);
        return preorder;
    }

    // Post-order traversal of the tree
    vector<int> traversePostOrder(int index, vector<int> &postorder)
    {
        if (index >= size || tree[index] == nullChild)
            return postorder;

        traversePostOrder(2 * index, postorder);
        traversePostOrder(2 * index + 1, postorder);
        cout << tree[index] << " ";
        postorder.push_back(tree[index]);
        return postorder;
    }

    // Level-order traversal of the tree
    vector<int> levelOrderTraversal(vector<int> &levelorder)
    {
        for (int i = 1; i < size; i++)
        {
            if (tree[i] != nullChild)
                levelorder.push_back(tree[i]), cout << tree[i] << " ";
        }
        return levelorder;
    }

    // Check if the tree is empty
    bool isEmpty()
    {
        return tree[1] == nullChild;
    }

    // Get the size of the tree
    int treeSize()
    {
        int count = 0;
        for (int i = 1; i < size; i++)
        {
            if (tree[i] != nullChild)
                count++;
        }
        return count;
    }

    // Print the tree in a tree-like structure (Left to Right (Root -> Child))
    void print(int index = 1, int depth = 0)
    {
        if(treeSize() == 0)
        {
            cout << "\nTree is empty." << endl;
            return;
        }
        if (index >= size || tree[index] == nullChild)
            return;

        print(2 * index + 1, depth + 1);

        for (int i = 0; i < depth; i++)
            cout << "\t";

        cout << tree[index] << endl;

        print(2 * index, depth + 1);
    }
};

int main()
{
    int choice, element, levels, idx;
    system("cls");
    cout << "Enter the number of levels in the tree: ";
    positiveValidation(levels);

    BinaryTree bt(levels);

    bt.insert();
    cout << "\nCurrent Tree:\n" << endl;
    bt.print();
    cout << endl;
    system("pause");
    vector<int> inorder, preorder, postorder, levelorder;

    do
    {
        system("cls");
        cout << "----------> Binary Tree <----------" << endl;
        cout << "\n1. Insert element" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Edit element" << endl;
        cout << "4. Find element" << endl;
        cout << "5. Get right child" << endl;
        cout << "6. Get left child" << endl;
        cout << "7. Get parent" << endl;
        cout << "8. In-order traversal" << endl;
        cout << "9. Pre-order traversal" << endl;
        cout << "10. Post-order traversal" << endl;
        cout << "11. Level-order traversal" << endl;
        cout << "12. Check if empty" << endl;
        cout << "13. Get size" << endl;
        cout << "14. Print tree" << endl;
        cout << "15. Exit" << endl;
        cout << "Enter your choice: ";
        positiveValidation(choice);
        cout << endl;

        switch (choice)
        {
        case 1:
            bt.insertElement();
            break;
        case 2:
            bt.deleteElement();
            break;
        case 3:
            bt.edit();
            break;
        case 4:
            cout << "Enter element to find: ";
            numberValidation(element);
            idx = bt.find(element);
            if (idx != -1)
                cout << "Element found in the tree at " << idx << " index." << endl;
            else
                cout << "Element not found in the tree." << endl;
            break;
        case 5:
            cout << "Enter index: ";
            numberValidation(element);
            cout << "Right child: " << bt.getRightChild(element) << endl;
            break;
        case 6:
            cout << "Enter index: ";
            numberValidation(element);
            cout << "Left child: " << bt.getLeftChild(element) << endl;
            break;
        case 7:
            cout << "Enter index: ";
            numberValidation(element);
            cout << "Parent: " << bt.getParent(element) << endl;
            break;
        case 8:
            cout << "In-order traversal: ";
            inorder = bt.traverseInOrder(1, inorder);
            cout << endl;
            break;
        case 9:
            cout << "Pre-order traversal: ";
            preorder = bt.traversePreOrder(1, preorder);
            cout << endl;
            break;
        case 10:
            cout << "Post-order traversal: ";
            postorder = bt.traversePostOrder(1, postorder);
            cout << endl;
            break;
        case 11:
            cout << "Level-order traversal: ";
            levelorder = bt.levelOrderTraversal(levelorder);
            cout << endl;
            break;
        case 12:
            cout << (bt.isEmpty() ? "Tree is empty" : "Tree is not empty") << endl;
            break;
        case 13:
            cout << "Tree size: " << bt.treeSize() << endl;
            break;
        case 14:
            bt.print();
            break;
        case 15:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice, try again." << endl;
        }
        cout << endl;
        system("pause");

    } while (choice != 15);

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
