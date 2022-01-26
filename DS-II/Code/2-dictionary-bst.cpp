/*
Name: Rushikesh Patade
Roll no.: PG-19
Batch: G2

*/

#include <iostream>
using namespace std;

#define SIZE 1000
#define DEBUG(opt)                       \
    do                                   \
    {                                    \
        cout << "DEBUG " << opt << endl; \
    } while (0);
#define clrscr system("cls");

// Class TreeNode
class TreeNode
{
    // Properties of TreeNode
    string data;
    string meaning;

    // TreeNode left, right children
    TreeNode *left;
    TreeNode *right;

    // Friend classes
    friend class Tree;
    friend class Queue;
};

// Class Queue
class Queue
{
    // Array of TreeNode Object holder
    TreeNode *arr[100];

    // Properties of Queue
    int capacity;
    int front;
    int rear;
    int count;

    // Public access specifier
public:
    // Default Parameterized Constructor
    Queue(int size = SIZE);

    // Class function members
    TreeNode *dequeue();
    void enqueue(TreeNode *item);
    int peek();
    int size();
    bool isempty();
    bool isfull();
};

// Constructor definition - Queue
Queue::Queue(int size)
{
    capacity = size;
    front = -1;
    rear = -1;
    count = 0;
}

// Function definition - dequeue
TreeNode *Queue::dequeue()
{
    if (isempty())
        cout << "Underflow\nProgram Terminated\n";

    TreeNode *x = arr[++front];
    count--;
    return x;
}

// Function definition - enqueue
void Queue::enqueue(TreeNode *item)
{
    if (isfull())
        cout << "Overflow\nProgram Terminated\n";

    else
    {
        arr[++rear] = item;
        count++;
    }
}

// Function definition - size
int Queue::size()
{
    return count;
}

// Function definition - isempty
bool Queue::isempty()
{
    return (size() == 0);
}

// Function definition - isfull
bool Queue::isfull()
{
    return (size() == capacity);
}

// Class Tree
class Tree
{
    // Public access specifier
public:
    // Properties of Tree
    TreeNode *root;

    // Constructor definition - Tree
    Tree()
    {
        root = NULL;
    }

    // Class function members
    void create_nr();

    void inorder_r();
    void inorder_r(TreeNode *temp);

    void del();

    void copy_r();
    TreeNode *copy_r(TreeNode *root);

    void mirror_r();
    void mirror_r(TreeNode *root);
    void mirror_nr();

    void bfs();
};

// Function definition - create_nr
void Tree::create_nr()
{
    int flag;
    char choice;
    if (root == NULL)
    {
        root = new TreeNode();
        cout << "Enter your root data : ";
        cin >> root->data;
        cout << "Enter your root meaning : ";
        cin >> root->meaning;
        root->left = NULL;
        root->right = NULL;
    }
    do
    {
        TreeNode *temp = root;
        TreeNode *curr = new TreeNode();
        flag = 1;
        cout << "Enter your data : ";
        cin >> curr->data;
        cout << "Enter your data meaning : ";
        cin >> curr->meaning;

        // DEBUG(1)
        // Inserting node data in the tree
        while (flag)
        {
            // Current data is lesser than the Temp data - Going to left subtree
            if (curr->data < temp->data)
            {
                // DEBUG("L")
                // Left subtree is NULL - Add data to the tree
                if (temp->left == NULL)
                {
                    temp->left = curr;
                    flag = 0;
                }
                // Left subtree exists - Going to explore the left subtree
                else
                    temp = temp->left;
            }

            // Current data is greater than the Temp data - Going to right subtree
            else
            {
                // DEBUG("R")
                // Right subtree is NULL - Add data to the tree
                if (temp->right == NULL)
                {
                    temp->right = curr;
                    flag = 0;
                }
                // Right subtree exists - Going to explore the right subtree
                else
                    temp = temp->right;
            }
        }
        // Asking for continuation
        cout << "Press 'y' to continue adding new data : ";
        cin >> choice;

    } while (choice == 'y');
}

// Function definition - inorder_r
void Tree::inorder_r()
{
    // DEBUG("INORDER")
    inorder_r(root);
}

// Function definition - inorder_r - Overloaded function
void Tree::inorder_r(TreeNode *temp)
{
    if (temp != NULL)
    {
        inorder_r(temp->left);
        cout << temp->data << " : " << temp->meaning << endl;
        inorder_r(temp->right);
    }
}

// Function definition - del
void Tree::del()
{
    int flag = 1;
    string key;

    // Take key input
    cout << "Input which key is to be deleted : ";
    cin >> key;

    // Search operation - Finding the key location
    TreeNode *curr = root;
    TreeNode *parent;
    TreeNode *temp;

    while (flag)
    {
        // Key found
        if (key == curr->data)
        {
            flag = 0;
            break;
        }

        // Key is lesser than current key - Going to the left subtree
        else if (key < curr->data)
        {
            parent = curr;
            curr = curr->left;
        }

        // Key is greater than current key - Going to the right subtree
        else
        {
            parent = curr;
            curr = curr->right;
        }
    }

    // Deletion operation - Key is found
    if (!flag)
    {
        // Root is the key
        if (curr == root)
        {
            // Right subtree is empty - Left child becomes the new root
            if (curr->right == NULL)
                root = root->left;

            // Left subtree is empty - Right child becomes the new root
            else if (curr->left == NULL)
                root = root->right;

            // Both subtrees exist - Proper deletion
            else if (curr->right != NULL && curr->left != NULL)
            {

                temp = curr->left;
                root = curr->right;
                TreeNode *s = curr->right;

                // Reach the left most node of the right subtree
                while (s->left != NULL)
                    s = s->left;

                // Add the left subtree of the root to the left most node of the right subtree of the root
                s->left = temp;
            }
        }

        // Root is not the key
        else
        {
            // The key is a leaf node
            if (curr->right == NULL && curr->left == NULL)
            {
                // Key is Parent's left node
                if (parent->left == curr)
                    parent->left = NULL;

                // Key is Parent's right node
                else
                    parent->right = NULL;
            }

            // Left node of key is NULL - Right Subtree of key exists
            else if (curr->left == NULL)
            {
                // Key is Parent's left node
                if (parent->left == curr)
                    parent->left = curr->right;

                // Key is Parent's right node
                else
                    parent->right = curr->right;
            }

            // Right node of key is NULL - Left Subtree of key exists
            else if (curr->right == NULL)
            {
                // Key is Parent's left node
                if (parent->left == curr)
                    parent->left = curr->left;

                // Key is Parent's right node
                else
                    parent->right = curr->left;
            }

            // Both Subtrees of key exist
            else
            {
                TreeNode *s = curr->right;
                temp = curr->left;

                // Reach the left most node of the right subtree
                while (s->left != NULL)
                    s = s->left;

                // Add the left subtree of the root to the left most node of the right subtree of the root
                s->left = temp;

                // Key is Parent's left node
                if (parent->left == curr)
                    parent->left = curr->right;

                // Key is Parent's right node
                else
                    parent->right = curr->right;
            }
        }

        // Freeing the node
        curr->left = curr->right = NULL;
        delete curr;
    }

    // Key is not found
    else
        cout << "Not found";
}

// Function definition - copy_r
void Tree::copy_r()
{
    TreeNode *root2 = new TreeNode();
    root2 = copy_r(root);
    cout << endl
         << "Copied Tree is : " << endl;

    inorder_r(root2);
}

// Function definition - copy_r - Overloaded function
TreeNode *Tree::copy_r(TreeNode *root)
{
    TreeNode *temp;
    temp = NULL;
    if (root != NULL)
    {
        // Copy data into temp variable
        temp = new TreeNode();
        temp->data = root->data;
        temp->meaning = root->meaning;

        // Recursively forming the left & right subtree of the current node
        temp->left = copy_r(root->left);
        temp->right = copy_r(root->right);
    }
    return temp;
}

// Function definition - mirror_r
void Tree::mirror_r()
{
    mirror_r(root);
}

// Function definition - mirror_r - Overloaded function
void Tree::mirror_r(TreeNode *root)
{
    TreeNode *temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;

    if (root->left != NULL)
        mirror_r(root->left);

    if (root->right != NULL)
        mirror_r(root->right);
}

// Function definition - mirror_nr
void Tree::mirror_nr()
{
    TreeNode *extra, *temp = root;
    Queue q;
    q.enqueue(temp);

    while (!q.isempty())
    {
        temp = q.dequeue();
        extra = temp->left;
        temp->left = temp->right;
        temp->right = extra;

        if (temp->left != NULL)
            q.enqueue(temp->left);

        if (temp->right != NULL)
            q.enqueue(temp->right);
    }
}

// Function definition - bfs
void Tree::bfs()
{
    TreeNode *temp = root;
    Queue q;
    q.enqueue(temp);
    while (q.size() != 0)
    {
        temp = q.dequeue();
        cout << temp->data << " : " << temp->meaning << endl;
        if (temp->left != NULL)
            q.enqueue(temp->left);

        if (temp->right != NULL)
            q.enqueue(temp->right);
    }
}

// Function main - Driver code
int main()
{
    Tree bt;
    clrscr
        // Create a tree - Driver code
        bt.create_nr();
    int op;
    string random;

    do
    {
        clrscr
                cout
            << "\tEnter your choice" << endl;
        cout << "1)Inorder r" << endl;
        cout << "2)BFS r" << endl;
        cout << "3)Delete key" << endl;
        cout << "4)Copy r" << endl;
        cout << "5)Mirror r" << endl;
        cout << "6)Mirror nr" << endl;
        cout << "7)Exit" << endl;
        cout << "Enter choice option : ";

        // Taking option input
        cin >> op;
        cout << endl;

        switch (op)
        {

        case 1:
            cout << "Inorder is:" << endl;
            bt.inorder_r();
            cout << endl;
            break;

        case 2:
            cout << "BFS is" << endl;
            bt.bfs();
            cout << endl;
            break;

        case 3:
            bt.del();
            cout << endl;
            break;

        case 4:
            cout << "Copy is:" << endl;
            bt.copy_r();
            cout << endl;
            break;

        case 5:
            cout << "Mirror R done" << endl;
            bt.mirror_r();
            cout << endl;
            break;

        case 6:
            cout << "Mirror NR done:" << endl;
            bt.mirror_nr();
            cout << endl;
            break;

        case 7:
            cout << "Exiting..." << endl;
            clrscr
                exit(0);

        default:
            cout << "Invalid input" << endl;
            break;
        }

        cout << "Press any key to continue..." << endl;
        cin >> random;
    } while (op != 7);

    return 0;
}
// Input data for keys

/*
M
Man
N
No
y
L
Length
y
A
Add
y
Q
Queue
n

*/