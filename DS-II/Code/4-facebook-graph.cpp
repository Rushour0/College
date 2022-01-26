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

// Class Gnode
class Gnode
{
    int vertex;
    Gnode *next;
    string name;
    friend class Graph;

public:
    Gnode()
    {
        next = nullptr;
    }

    Gnode(string myname)
    {
        next = nullptr;
        name = myname;
    }
};

// Class Queue
class Queue
{
    // Array of int holder
    int arr[100];

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
    int dequeue();
    void enqueue(int item);
    int size();
    bool isempty();
    bool isfull();
};

// Constructor definition - Queue
Queue::Queue(int size)
{
    capacity = size;
    front = 0;
    rear = size - 1;
    count = 0;
}

// Class function definition - dequeue
int Queue::dequeue()
{
    if (isempty())
    {
        cout << "Underflow\nProgram Terminated\n";
        return 0;
    }

    int x = arr[front];
    front = (front + 1) % capacity;
    count--;
    return x;
}

// Class function definition - enqueue
void Queue::enqueue(int item)
{
    if (isfull())
        cout << "Overflow\nProgram Terminated\n";
    else
    {
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }
}

// Class function definition - size
int Queue::size()
{
    return count;
}

// Class function definition - isempty
bool Queue::isempty()
{
    return (size() == 0);
}

// Class function definition - isfull
bool Queue::isfull()
{
    return (size() == capacity);
}

// Class Stack
class Stack
{
    int top;
    int data[SIZE];

public:
    Stack()
    {
        top = -1;
    }

    // Class function declarations
    void push(int);
    int pop();
    bool empty();
};

// Class function definition - push
void Stack::push(int temp)
{
    data[++top] = temp;
}

// Class function definition - pop
int Stack::pop()
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

// Class Graph
class Graph
{
private:
    int n;
    Gnode **head, *temp;
    string *names;
    int *visited;

public:
    // Default constructor
    Graph()
    {
        string tempname;
        cout << "Enter number of nodes in the graph: ";
        cin >> n;
        head = new Gnode *[n];
        visited = new int[n];
        names = new string[n];
        for (int i = 0; i < n; i++)
        {
            cout << "Enter name for person \"" << i << "\": ";
            cin >> tempname;
            head[i] = new Gnode(tempname);
            names[i] = tempname;
            head[i]->vertex = i;
        }
    }

    // Class member functions
    void create();
    void bfs();
    void bfs(int v);
    void dfs();
    void dfs(int v);
    void adjacenyShow();
};

// Class function definition - create
void Graph::create()
{
    int v;
    Gnode *curr;
    Gnode *temp2;
    char choice;

    for (int i = 0; i < n; i++)
    {
        temp = head[i];
        while (temp->next != nullptr)
            temp = temp->next;
        do
        {
            cout << "Enter adjacent node for " << i << ": ";
            cin >> v;
            if (v == i)
                cout << "Self loop are not allowed" << endl;
            else if (v > n)
                cout << "Node number out of range!" << endl;
            else
            {
                curr = new Gnode(head[v]->name);
                curr->vertex = v;
                temp->next = curr;
                temp = temp->next;

                // Undirected graph - reverse node connectivity
                temp2 = head[v];
                while (temp2->next != nullptr)
                    temp2 = temp2->next;

                curr = new Gnode(head[i]->name);
                curr->vertex = i;
                temp2->next = curr;
            }
            cout << "Continue adding adjacent nodes? (y/n): ";
            cin >> choice;
        } while (choice != 'n');
    }
}

// Class function definition - bfs
void Graph::bfs()
{
    int v;
    cout << "Enter node to start the BFS from: ";
    cin >> v;
    cout << "BFS is:" << endl
         << v << "( " << head[v]->name << " )";
    bfs(v);
    cout << endl;
}
// Class function definition - bfs - override
void Graph::bfs(int v)
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    int w;
    Queue q;

    q.enqueue(v);
    while (!q.isempty())
    {
        v = q.dequeue();
        visited[v] = true;
        temp = head[v]->next;
        while (temp != nullptr)
        {
            w = temp->vertex;
            if (!visited[w])
            {
                cout << " -> " << w << "( " << temp->name << " )";
                q.enqueue(w);
                visited[w] = true;
            }
            temp = temp->next;
        }
    }
}

// Class function definition - dfs
void Graph::dfs()
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int v;
    cout << "Enter node to start the DFS from: ";
    cin >> v;
    cout << "DFS is" << endl
         << v << "( " << head[v]->name << " )";
    visited[v] = true;
    dfs(v);
    cout << endl;
}

// Class function definition - dfs - override
void Graph::dfs(int v)
{
    Gnode *temp;
    int w;
    if (!visited[v])
        cout << " -> " << v << "( " << head[v]->name << " )";
    visited[v] = true;

    temp = head[v]->next;
    while (temp != nullptr)
    {
        w = temp->vertex;
        if (!visited[w])
            dfs(w);
        temp = temp->next;
    }
}

// Class function definition - adjacencyShow
void Graph::adjacenyShow()
{
    for (int i = 0; i < n; i++)
    {
        temp = head[i]->next;
        cout << "Head \"" << i << "( " << head[i]->name << " )\" -> ";
        while (temp != nullptr)
        {
            cout << temp->vertex << "( " << temp->name << " ) -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
}

// Main function - driver code
int main()
{
    clrscr
        Graph graph;
    int op;
    char random;
    int v;

    // Creating Graph
    graph.create();

    // Menu loop
    do
    {
        clrscr
                cout
            << "\tEnter your choice" << endl;
        cout << "1)Show Graph" << endl;
        cout << "2)BFS" << endl;
        cout << "3)DFS" << endl;
        cout << "4)Exit" << endl;
        cout << "Enter choice option : ";

        // Taking option input
        cin >> op;
        cout << endl;

        switch (op)
        {

        case 1:
            cout << "Adjacency list form of the Graph" << endl
                 << endl;
            graph.adjacenyShow();
            cout << endl;
            break;

        case 2:
            graph.bfs();
            break;

        case 3:
            graph.dfs();
            break;

        case 4:
            cout << "Exiting..." << endl;
            clrscr
                exit(0);

        default:
            cout << "Invalid input" << endl;
            break;
        }

        cout << "Press any key to continue..." << endl;
        cin >> random;
    } while (true);
    return 0;
}

// Input

/*
4
1
y
2
n
2
n
0
y
3
n
3
n
*/

/*
4
water
air
fire
earth
1
n
2
n
3
n
1
n
*/