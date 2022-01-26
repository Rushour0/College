/*
Name: Rushikesh Patade
Roll no.: PG-19
Batch: G2
*/
#include <iostream>
using namespace std;

#define clrscr system("cls");

#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

class Heap
{
    int *marks;
    int size;

public:
    // Constructor
    Heap(int student_number)
    {
        size = student_number;
        marks = new int[student_number];
    }

    // Functions
    void accept();

    void display();

    void heapsort();

    void adjust(int n, int i);
};

// Class function definition - accept
void Heap::accept()
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        cout << BOLDWHITE << "Enter the marks for student " << i << ": " << RESET;
        cin >> temp;
        marks[i] = temp;
        cout << marks[i] << endl;
    }
}

// Class function definition - display
void Heap::display()
{
    cout << "The marks are as follow:" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << marks[i] << "\t";
    }

    cout << endl
         << endl;
    cout << "The maximum marks are: " << marks[size - 1] << endl;
    cout << "The minimum marks are: " << marks[0] << endl;
}

// Class function definition - heapsort
void Heap::heapsort()
{
    int t, n = size;

    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        adjust(n, i);
    }

    while (n > 1)
    {
        t = marks[0];
        marks[0] = marks[n - 1];
        marks[n - 1] = t;
        n--;
        adjust(n, 0);
    }
}

// Class function definition - adjust
void Heap::adjust(int n, int i)
{

    int temp = 0;

    while ((2 * i + 1) < n)
    {
        int j = 2 * i + 1;

        if ((j + 1 < n) && (marks[j + 1] > marks[j]))
            j++;
        if (marks[i] > marks[j])
            break;
        else
        {
            temp = marks[i];
            marks[i] = marks[j];
            marks[j] = temp;
            i = j;
        }
    }
}

// main driver code
int main()
{
    clrscr int n;
    cout << "Enter the number of students appearing for the exam: ";
    cin >> n;
    Heap h(n);
    cout << endl;
    h.accept();
    h.heapsort();
    h.display();

    return 0;
}