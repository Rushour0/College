/*
Name: Rushikesh Patade
Roll no.: PG-19
Batch: G2
*/

#include<iostream>
using namespace std;

#define SIZE 1000
#define DEBUG(opt) do{cout << "DEBUG " << opt << endl;}while(0);
#define clrscr system("cls");

// Class Gnode
class Gnode
{   
    int vertex;
    Gnode *next;
    friend class Graph;

    public:
    Gnode()
    {
        next = nullptr;
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

// Class function definition - dequeue
int Queue::dequeue()
{
    if ( isempty() )
        cout << "Underflow\nProgram Terminated\n";
    
    int x = arr[++front];
    count--;
    return x;
}

// Class function definition - enqueue
void Queue::enqueue(int item)
{
    if ( isfull() )
        cout << "Overflow\nProgram Terminated\n";
    else
    {
        arr[++rear] = item;
        count++;
    }
}

// Class function definition - size
int Queue::size() {
    return count;
}

// Class function definition - isempty
bool Queue::isempty() {
    return (size() == 0);
}

// Class function definition - isfull
bool Queue::isfull() {
    return (size() == capacity);
}

// Class Graph
class Graph
{
    private:
	
	int n;
    Gnode **head, *temp;
    int *visited;
    
    public:



    // Default constructor
	Graph()
	{   
        cout << "Enter number of nodes in the graph: ";
        cin >> n;
        head = new Gnode*[n];
        visited = new int[n];
        for ( int i = 0; i < n; i++ )
        {
            head[i] = new Gnode();
            head[i]->vertex = i;
        }
	}

    // Class member functions
    void create();
    void bfs(int v);
    void dfs();
    void dfs(int v);
};        

// Class function definition - create
void Graph::create()
{
    int v;
    Gnode *curr;
    char choice;
    
    for (int i = 0; i < n; i++ )
    {
        temp = head[i];
        do
        {
            cout << "Enter adjacent node for " << i << ": ";
            cin >> v;
            if( v == i )
                cout << "Self loop are not allowed" << endl;
            else
            {
                curr = new Gnode();
                curr->vertex = v;
                temp->next = curr;
                temp = temp->next;
            }
            cout << "Continue adding adjacent nodes? (y/n): ";
            cin >> choice;
        } while( choice != 'n');
    }
}

// Class function definition - bfs
void Graph::bfs(int v)
{
    for(int i = 0; i < n; i++ )
        visited[i] = 0;
    int w;
	Queue q;

	q.enqueue(v);
	while( !q.isempty() )
	{
		v = q.dequeue();
        visited[v] = 1;
        temp = head[v]->next;
		while( temp != nullptr )
        {
            w = temp->vertex;
            if( !visited[w] )
            {
                cout << " -> " << w;
                q.enqueue(w);
                visited[w] = 1;
            }
            temp = temp->next;
        }
	}
    free(visited);
}

// Class function definition - dfs
void Graph::dfs()
{
    for(int i = 0; i < n; i++ )
        visited[i] = 0;
    
    int v;
    cout << "Enter node to start the DFS from: ";
    cin >> v;
    cout << "DFS is" << endl << v;
    visited[v] = true;
    dfs(v);
    cout << endl;
}

// Class function definition - dfs - override
void Graph::dfs(int v)
{
    Gnode *temp;
    int w;
    if( !visited[v] )
        cout << " -> " << v;
    visited[v] = true;

    temp = head[v]->next;
    while( temp != nullptr )
    {
        w = temp->vertex;
        if( !visited[w] )
            dfs(w);
        temp = temp->next;
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
        cout << "\tEnter your choice" << endl;
		cout << "1)BFS" << endl;
		cout << "2)DFS" << endl;
        cout << "3)Exit" << endl;
        cout << "Enter choice option : ";
		
        // Taking option input
		cin >> op;
        cout << endl;

		switch( op )
		{

            case 1:
                cout << "Enter node to start the BFS from: ";
                cin >> v;
                cout << "BFS is:" << endl << v;
                graph.bfs(v);
                cout << endl;
                break;

            case 2:
                graph.dfs();
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
	} while( op != 3 );
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