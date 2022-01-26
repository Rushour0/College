/*
Name: Rushikesh Patade
Roll no.: PG-19
Batch: G2
*/

#include <iostream>
using namespace std;

#define DEBUG(opt)                       \
    do                                   \
    {                                    \
        cout << "DEBUG " << opt << endl; \
    } while (0);
#define clrscr system("cls");

// Class TBTNode
class TBTNode
{
    // Properties of TBTNode
    char data;
    bool rbit, lbit;
    TBTNode *rightc, *leftc;

    // Friend classes
    friend class TBT;

public:
    // Default constructor
    TBTNode()
    {
        lbit = true;
        rbit = true;
    }
};

// Class TBT
class TBT
{
    // Properties of TBT
    TBTNode *head, *root, *temp;

public:
    // Class function members
    void create();
    void preorder();
    void inorder();

    TBTNode *preordersucc(TBTNode *temp);
    TBTNode *inordersucc(TBTNode *temp);

    // Default constructor
    TBT()
    {
        head = new TBTNode();
        head->rbit = false;
        head->leftc = head->rightc = head;
    }
};

// Class function definition - create
void TBT::create()
{
    TBTNode *curr;
    bool flag;
    char choice;

    root = new TBTNode();
    cout << "Enter root data: ";
    cin >> root->data;

    root->leftc = root->rightc = head;

    head->lbit = false;
    head->leftc = root;

    // Accepting loop
    do
    {
        flag = false;
        temp = root;
        curr = new TBTNode();
        cout << "Enter new data: ";
        cin >> curr->data;

        while (flag == false)
        {
            cout << "Enter left or right (l/r): ";
            cin >> choice;
            cout << endl;

            // Left choice
            if (choice == 'l')
            {
                // Left thread exists
                if (temp->lbit == true)
                {
                    curr->rightc = temp;
                    curr->leftc = temp->leftc;
                    temp->leftc = curr;
                    temp->lbit = false;
                    flag = true;
                }
                else
                    temp = temp->leftc;
            }
            // Right choice
            else if (choice == 'r')
            {
                // Right thread exists
                if (temp->rbit == true)
                {
                    curr->leftc = temp;
                    curr->rightc = temp->rightc;
                    temp->rightc = curr;
                    temp->rbit = false;
                    flag = true;
                }
                else
                    temp = temp->rightc;
            }
            else
            {
                cout << "Wrong choice" << endl;
            }
        }
        cout << "Continue adding nodes? (y/n): ";
        cin >> choice;
    } while (choice == 'y');
}

// Class function definition - inorder
void TBT::inorder()
{
    temp = head;
    while (1)
    {
        temp = inordersucc(temp);
        if (temp == head)
            break;
        cout << temp->data << " ";
    }
}

// Class function definition - preorder
void TBT::preorder()
{
    temp = head->leftc;
    while (temp != head)
    {
        cout << temp->data << " ";
        while (temp->lbit == false)
        {
            temp = temp->leftc;
            cout << temp->data << " ";
        }
        temp = preordersucc(temp);
    }
}

// Class function definition - inordersucc
TBTNode *TBT::inordersucc(TBTNode *node)
{
    temp = node->rightc;
    if (node->rbit == false)
    {
        while (temp->lbit == false)
            temp = temp->leftc;
    }
    return temp;
}

// Class function definition - preordersucc
TBTNode *TBT::preordersucc(TBTNode *node)
{
    while (node->rbit == true)
        node = node->rightc;
    node = node->rightc;
    return node;
}

// main function - driver code
int main()
{
    clrscr
        TBT tbt;
    int op;
    char random;

    // Creating TBT
    tbt.create();

    // Menu loop
    do
    {
        clrscr
                cout
            << "\tEnter your choice" << endl;
        cout << "1)Inorder" << endl;
        cout << "2)Preorder" << endl;
        cout << "3)Exit" << endl;
        cout << "Enter choice option : ";

        // Taking option input
        cin >> op;
        cout << endl;

        switch (op)
        {

        case 1:
            cout << "Inorder is:" << endl;
            tbt.inorder();
            cout << endl;
            break;

        case 2:
            cout << "Preorder is" << endl;
            tbt.preorder();
            cout << endl;
            break;

        case 3:
            cout << "Exiting..." << endl;
            clrscr
                exit(0);

        default:
            cout << "Invalid input" << endl;
            break;
        }

        cout << "Press any key to continue..." << endl;
        cin >> random;
    } while (op != 3);
    return 0;
}

/*
6
1
l
y
3
l
r
y
5
l
l
y
4
r
y
7
r
l
n
*/