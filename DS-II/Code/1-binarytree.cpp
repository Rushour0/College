/*
Name: Rushikesh Patade
Roll no.: PG-19
Batch: G2
*/

#include <iostream>
using namespace std;

#define clrscr system("cls");

// Class TreeNode
class TreeNode
{
    // Data and left / right children
    char data[10];
    TreeNode *left;
    TreeNode *right;

    // Declaring friend classes
    friend class Tree;
};

// Class Stack
class Stack
{
    int top;
    TreeNode *data[30];

public:
    Stack()
    {
        top = -1;
    }

    // Class function declarations
    void push(TreeNode *);
    TreeNode *pop();
    bool empty();

    // Declaring friend classes
    friend class Tree;
};

// Class function definition - push
void Stack::push(TreeNode *temp)
{
    data[++top] = temp;
}

// Class function definition - pop
TreeNode *Stack::pop()
{
    return data[top--];
}

// Class function definition - empty
bool Stack::empty()
{
    if (top == -1)
        return true;
    return false;
}

class Tree
{
    TreeNode *root;

public:
    Tree()
    {
        root = NULL;
    }

    // Class function declarations

    // Recursive functions

    // Internal method
    void create_r();
    // Method which actually performs the algorithm
    void create_r(TreeNode *);

    // Internal method
    void inorder_r();
    // Method which actually performs the algorithm
    void inorder_r(TreeNode *);

    // Internal method
    void preorder_r();
    // Method which actually performs the algorithm
    void preorder_r(TreeNode *);

    // Internal method
    void postorder_r();
    // Method which actually performs the algorithm
    void postorder_r(TreeNode *);

    // Non recursive functions

    void create_nr();
    void inorder_nr();
    void preorder_nr();
    void postorder_nr();
};

// Class function definition - create_r
void Tree::create_r()
{
    this->create_r(root);
}

// Class function definition - create_r - overloaded
void Tree::create_r(TreeNode *temp)
{
    if (root == NULL)
    {
        root = new TreeNode;
        root->right = NULL;
        root->left = NULL;
        cout << "Enter the data for root node: ";
        cin >> root->data;
        temp = root;
    }

    char ch;
    cout << endl;
    TreeNode *curr = new TreeNode();
    curr->right = NULL;
    curr->left = NULL;
    cout << "Enter the data for current node: ";
    cin >> curr->data;
    cout << endl;
    cout << "Add data to the left subtree?\n Enter choice: (Y/N)";
    cin >> ch;

    // Accept choice whether data is added to left of temp->data;
    if (ch == 'y' || ch == 'Y')
    {
        // Allocate a memory for curr and accept data;
        temp->left = curr;
        clrscr
            create_r(curr);
    }
    cout << "Add data to the right subtree?\n Enter choice: (Y/N)";
    cin >> ch;
    // Accept choice whether data is added to right of temp->data;
    if (ch == 'y' || ch == 'Y')
    {
        // Allocate a memory for curr and accept data;
        temp->right = curr;
        clrscr
            create_r(curr);
    }
}

// Class function definition - create_nr
void Tree::create_nr()
{
    char ch2 = 'Y';
    if (root == NULL)
    {
        root = new TreeNode;
        root->right = NULL;
        root->left = NULL;
        cout << "Enter the data for root node: ";
        cin >> root->data;
    }

    do
    {
        TreeNode *temp, *curr;
        temp = root;
        int flag = 0;
        curr = new TreeNode();
        curr->right = NULL;
        curr->left = NULL;
        cout << "Enter the data for current node: ";
        cin >> curr->data;

        while (flag == 0)
        {
            char ch;
            cout << "Press 'l' to add node to left and 'r' to add node to right.\nEnter choice: ";
            cin >> ch;

            if (ch == 'l')
            {
                if (temp->left == NULL)
                {
                    temp->left = curr;
                    flag = 1;
                }
                temp = temp->left;
            }
            else if (ch == 'r')
            {
                if (temp->right == NULL)
                {
                    temp->right = curr;
                    flag = 1;
                }
                temp = temp->right;
            }
            else
                cout << "Wrong choice" << endl;
        }
        clrscr
                cout
            << "DO YOU WANT TO CONTINUE ADDING NODES? [Y/N]" << endl;

        // Take input for next
        cin >> ch2;
        clrscr

    } while (ch2 == 'Y' || ch2 == 'y');
}

// Class function definition - inorder_r
void Tree::inorder_r()
{
    inorder_r(root);
}

// Class function definition - inorder_r - overloaded
void Tree::inorder_r(TreeNode *temp)
{
    if (temp != NULL)
    {
        inorder_r(temp->left);
        cout << temp->data << " ";
        inorder_r(temp->right);
    }
}

// Class function definition - preorder_r
void Tree::preorder_r()
{
    preorder_r(root);
}

// Class function definition - preorder_r - overloaded
void Tree::preorder_r(TreeNode *temp)
{
    if (temp != NULL)
    {
        cout << temp->data << " ";
        preorder_r(temp->left);
        preorder_r(temp->right);
    }
}

// Class function definition - postorder_r
void Tree::postorder_r()
{
    postorder_r(root);
}

// Class function definition - postorder_r - overloaded
void Tree::postorder_r(TreeNode *temp)
{
    if (temp != NULL)
    {
        postorder_r(temp->left);
        postorder_r(temp->right);
        cout << temp->data << " ";
    }
}

// Non recursive function definitions

void Tree::inorder_nr()
{

    Stack stack;
    TreeNode *temp = root; //start traversing the binary tree at the root node
    while (1)
    {

        while (temp != NULL)
        {
            stack.push(temp);
            temp = temp->left;
        }
        if (stack.empty())
            break;
        temp = stack.pop();
        cout << temp->data << " ";
        temp = temp->right;
    }
}

// Class function definition - preorder_nr
void Tree::preorder_nr()
{
    Stack stack;
    TreeNode *temp = root; //start the traversal at the root node
    while (1)
    {
        while (temp != NULL)
        {
            cout << temp->data << " ";
            stack.push(temp);
            temp = temp->left;
        }

        if (stack.empty())
            break;
        temp = stack.pop();
        temp = temp->right;
    }
}

void Tree::postorder_nr()
{
    Stack decoyStack, stack;
    TreeNode *temp = this->root;
    decoyStack.push(temp);
    while (!decoyStack.empty())
    {
        temp = decoyStack.pop();
        stack.push(temp);
        if (temp->left != nullptr)
            decoyStack.push(temp->left);
        if (temp->right != nullptr)
            decoyStack.push(temp->right);
    }
    while (!stack.empty())
    {
        temp = stack.pop();
        cout << temp->data << " ";
    }
}

// main function - driver code
int main()
{
    clrscr
        Tree bt;
    int op;
    char random;
    cout << "Take recursive inputs? (Y/N)" << endl;
    cout << "Enter choice: ";
    cin >> random;

    if (random == 'y' || random == 'Y')
        bt.create_r();
    else
        bt.create_r();

    // Menu
    do
    {
        clrscr
                cout
            << "\tEnter your choice" << endl;
        cout << "1)Inorder r" << endl;
        cout << "2)Preorder r" << endl;
        cout << "3)Postorder r" << endl;
        cout << "4)Inorder nr" << endl;
        cout << "5)Preorder nr" << endl;
        cout << "6)Postorder nr" << endl;
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
            cout << "Preorder is" << endl;
            bt.preorder_r();
            cout << endl;
            break;

        case 3:
            cout << "Postorder is:" << endl;
            bt.postorder_r();
            cout << endl;
            break;
        case 4:
            cout << "Inorder is:" << endl;
            bt.inorder_nr();
            cout << endl;
            break;

        case 5:
            cout << "Preorder is" << endl;
            bt.preorder_nr();
            cout << endl;
            break;

        case 6:
            cout << "Postorder is:" << endl;
            bt.postorder_nr();
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
}
