/*
Name: Rushikesh Patade
Panel: G
Batch: G2
Roll no.: PG19
*/

#include <iostream>
using namespace std;

#define clrscr system("cls || clear");

// Class Box
class Box
{
private:
    double l, b, h;

public:
    // Default constructor
    Box()
    {
        l = 0;
        b = 0;
        h = 0;
    }

    // Class member functions
    Box operator+(Box B);

    // Friend functions
    friend ostream &operator<<(ostream &, Box &);
    friend istream &operator>>(istream &, Box &);
    friend double volume(Box);
};

// Class operator function definition - operator +
Box Box::operator+(Box B)
{
    Box b1;
    b1.l = l + B.l;
    b1.b = b + B.b;
    b1.h = h + B.h;
    return b1;
}

// Function definition - volume
double volume(Box box)
{
    return (box.l * box.b * box.h);
}

// Function definition - operator >> - overloading
istream &operator>>(istream &in, Box &box)
{
    in >> box.l;
    in >> box.b;
    in >> box.h;
    return in;
}

// Function definition - operator << - overloading
ostream &operator<<(ostream &out, Box &box)
{
    out << "LENGHT: " << box.l << "\n";
    out << "BREADTH: " << box.b << "\n";
    out << "HEIGHT: " << box.h << "\n";
    return out;
}

// main function - driver code
int main()
{
    clrscr
        // Box instances
        Box B1,
        B2, B3;

    cout << "\nENTER L,B,H OF BOX 1: \n";
    cin >> B1;
    cout << "\nDETAILS OF BOX 1: \n";
    cout << B1;

    cout << "\nENTER L,B,H OF BOX 2: \n";
    cin >> B2;
    cout << "\nDETAILS OF BOX 2: \n";
    cout << B2;

    B3 = B1 + B2;

    cout << "\nDETAILS OF BOX 3: \n";
    cout << B3;
    cout << "\nVOLUME OF BOX 1: " << volume(B1) << "\n";
    cout << "\nVOLUME OF BOX 2: " << volume(B2) << "\n";
    cout << "\nVOLUME OF BOX 3: " << volume(B3) << "\n";
    return 0;
}