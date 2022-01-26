/*
Name: Rushikesh Patade
Roll no.: PG-19
Batch: G2
*/
#include <iostream>
#include <string.h>

using namespace std;

class graph
{
private:
    int cost[50][50];
    int total_cities;

public:
    void create();
    void display();
    void prims();
};

// Class function definition - create
void graph::create()
{
    string ch;
    cout << "\nEnter the number of cities:";
    cin >> total_cities;
    for (int i = 0; i < total_cities; i++)
    {
        for (int j = 0; j < total_cities; j++)
        {
            cost[i][j] = 999;
        }
    }
    for (int i = 0; i < total_cities; i++)
    {
        for (int j = i + 1; j < total_cities; j++)
        {
            cout << "\n Is there a connection between " << i << " and " << j << ":"
                 << "(y or n)"
                 << "->";
            cin >> ch;
            if (ch == "y")
            {
                cout << "\nEnter the cost of edge " << i << " and " << j << ":";
                cin >> cost[i][j];
                cost[j][i] = cost[i][j];
            }
        }
    }
}

// Class function definition - display
void graph::display()
{
    for (int i = 0; i < total_cities; i++)
    {
        for (int j = 0; j < total_cities; j++)
        {
            cout << cost[i][j] << "\t";
        }
        cout << endl;
    }
}

// Class function definition - prims
void graph::prims()
{
    int st[total_cities][2];
    int i, j, k;
    int r = 0;
    int startv, min, final = 0;
    int nearest[total_cities];

    cout << "\nEnter starting vertex: ";
    cin >> startv;
    nearest[startv] = -1;

    for (i = 0; i < (total_cities); i++)
    {
        if (i != startv)
        {
            nearest[i] = startv;
        }
    }

    for (i = 1; i < total_cities; i++)
    {
        min = 999;
        for (k = 0; k < total_cities; k++)
        {
            if (nearest[k] != -1 && cost[k][nearest[k]] < min)
            {
                j = k;
                min = cost[k][nearest[k]];
            }
        }

        st[r][0] = nearest[j];
        st[r][1] = j;
        r = r + 1;
        final = final + cost[j][nearest[j]];
        nearest[j] = -1;

        for (k = 0; k < total_cities; k++)
        {
            if (nearest[k] != -1 && cost[k][nearest[k]] > cost[k][j])
            {
                nearest[k] = j;
            }
        }
    }

    cout << "\nThe spanning tree is as follows:\n";
    for (i = 0; i < total_cities - 1; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cout << st[i][j];
            cout << "\t";
        }
        cout << endl;
    }
    cout << "\nThe total cost is: " << final << endl;
}
int main()
{
    int choice;
    char random;
    graph g;
    do
    {
        cout << "\n---------------------MENU-----------------------" << endl;
        cout << "1) Create the graph" << endl;
        cout << "2) Display the graph" << endl;
        cout << "3) Display total cost" << endl;
        cout << "4) Exit." << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "\nCreating Graph.........." << endl;
            g.create();
            break;
        }
        case 2:
        {
            cout << "Displaying the graph..........." << endl;
            g.display();
            break;
        }
        case 3:
        {
            g.prims();
            break;
        }
        case 4:
        {
            exit(0);
            break;
        }
        default:
        {
            cout << "Invalid Input";
            break;
        }
        }
        cout << "\nPress any key to continue:" << endl;
        cin >> random;
    } while (choice != 4);
    return 0;
}
