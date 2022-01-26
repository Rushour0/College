#include <iostream>
using namespace std;

#define clrscr system("cls");

// Base Class - Employee
class Employee
{
protected:
    string name, city, contact;
    int id;
    float grossSal, da, ta, pf;

public:
    virtual float calculate_salary() = 0; // Virtual function declared
    void getData();
    void display();
};

// Class function Employee - getData
void Employee::getData()
{
    cout << "\nEnter the name of the employee: ";
    cin >> name;
    cout << "Enter the ID of the employee: ";
    cin >> id;
    cout << "Enter the Phone Number of the employee: ";
    cin >> contact;
    cout << "Enter the city of the employee: ";
    cin >> city;
}

// Class function Employee - display
void Employee::display() // display the details
{
    getData();
    cout << endl
         << endl;
    cout << "\tDetails" << endl;
    cout << "Employee Name: " << name << endl;
    cout << "Employee Id: " << id << endl;
    cout << "Employee Mobile Number: " << contact << endl;
    cout << "Employee City: " << city << endl;

    cout << "Gross salary of Manager: " << calculate_salary() << endl;
}

// First Derived class from class Employee
class class1_Employee : public Employee
{
    float basic_sal;

public:
    float calculate_salary();
    void display_gross();
};

// Class function class1_Employee - calculate_salary
float class1_Employee::calculate_salary()
{
    basic_sal = 100000;
    da = 0.97 * basic_sal;
    ta = 0.1 * basic_sal;
    pf = 0.12 * basic_sal;
    grossSal = (basic_sal + da + ta + pf);
    return grossSal;
}

// Second Derived class from class Employee
class class2_Employee : public Employee
{
    float basic_sal;

public:
    float calculate_salary();
};

// Class function class2_Employee - calculate_salary
float class2_Employee::calculate_salary()
{
    basic_sal = 80000;
    da = 0.97 * basic_sal;
    ta = 0.1 * basic_sal;
    pf = 0.12 * basic_sal;
    grossSal = (basic_sal + da + ta + pf);
    return grossSal;
}

// Third Derived class from class Employee
class class3_Employee : public Employee
{
    float basic_sal;

public:
    float calculate_salary();
};

// Class function class3_Employee - calculate_salary
float class3_Employee::calculate_salary()
{
    basic_sal = 60000;
    da = 0.97 * basic_sal;
    ta = 0.1 * basic_sal;
    pf = 0.12 * basic_sal;
    grossSal = (basic_sal + da + ta + pf);
    return grossSal;
}

int main() // main function
{
    clrscr
        Employee *e1;

    cout << "\nManager: " << endl;

    class1_Employee cs1_emp;
    e1 = &cs1_emp;

    (*e1).display();

    cout << endl
         << "Team Lead: " << endl;

    class2_Employee cs2_emp;
    e1 = &cs2_emp;

    (*e1).display();

    cout << endl
         << "Programmer: " << endl;

    class3_Employee cs3_emp;
    e1 = &cs3_emp;

    (*e1).display();

    return 0;
}

/*
abc
123
456
abc
cde
567
789
cde
def
012
234
def
*/