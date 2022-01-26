#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

#define clrscr system("cls");
#define MAX_ADDRESS_LEN 250

// Class Employee
class Employee
{
protected:
    string emp_name, emp_mail, emp_mob, emp_adr;

    int emp_id;

    float basicSal, grossSal, netSal, DA, HRA, PF, SCF;

public:
    void accept();
    void display();
    void calculate();
};

// Class function Employee - accept
void Employee ::accept()
{
    char ch;
    clrscr
            cout
        << "\tEnter Employee Details\n";
    cout << "1.Employee Name : ";
    cin >> emp_name;

    cout << "2.Employee  Id : ";
    cin >> emp_id;

    cout << "3.Employee Mobile Number : ";
    cin >> emp_mob;
    scanf("%c", &ch);

    cout << "4.Employee Address : ";
    getline(cin, emp_adr);

    cout << "5.Employee Email Id : ";
    cin >> emp_mail;

    cout << "6.Enter the basic pay : ";
    cin >> basicSal;
}

// Class function Employee - display
void Employee ::display()
{
    clrscr
            cout
        << "\tEmployee Details";
    cout << "Employee Name : " << emp_name << endl;
    cout << "Employee Id : " << emp_id << endl;
    cout << "Employee Mobile Number : " << emp_mob << endl;
    cout << "Employee Address : " << emp_adr << endl;
    cout << "Employee Email Id : " << emp_mail << endl;

    cout << "\nBasic Pay :  " << basicSal;
    cout << "\nDA : \t" << DA << "\nHRA : \t" << HRA << "\nPF : \t" << PF << "\nSCF : \t" << SCF << endl;
    cout << "Gross Salary : \t" << grossSal << endl;
    cout << "Net Salary : \t" << netSal << endl;
}

// Class function Employee - calculate
void Employee::calculate()
{
    DA = 0.97 * basicSal;
    HRA = 0.1 * basicSal;
    PF = 0.12 * basicSal;
    SCF = 0.01 * basicSal;
    grossSal = basicSal + DA + HRA;
    netSal = (grossSal - PF - SCF);
}

// Class Programmer - derived from Employee
class Programmer : public Employee
{

public:
    void paySlip()
    {
        cout << "Position :  Programmer" << endl;
        accept();
        calculate();
        display();
    }
};

// Class TeamLeader - derived from Employee
class TeamLeader : public Employee
{

public:
    void paySlip()
    {
        cout << "Position :  Team Leader" << endl;
        accept();
        calculate();
        display();
    }
};

// Class AssistantProjectManager - derived from Employee
class AssistantProjectManager : public Employee
{

public:
    void paySlip()
    {
        cout << "Position :  Assistant Project Manager" << endl;
        accept();
        calculate();
        display();
    }
};

// Class ProjectManager - derived from Employee
class ProjectManager : public Employee
{
public:
    void paySlip()
    {
        cout << "Position :  Project Manager" << endl;
        accept();
        calculate();
        display();
    }
};

// main function - driver code
int main()
{
    int ch;
    string random;

    // Class objects
    Programmer programmer;
    TeamLeader teamleader;
    AssistantProjectManager apm;
    ProjectManager pm;

    // Menu
    do
    {
        clrscr
                cout
            << "1.Programmer\n2.Team Leader\n3.Assistant Project Manager\n4.Project Manager\n5.Exit\n\nEnter your position :  ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            programmer.paySlip();
            break;

        case 2:
            teamleader.paySlip();
            break;

        case 3:
            apm.paySlip();
            break;

        case 4:
            pm.paySlip();
            break;

        case 5:
            cout << "Exiting..." << endl;
            exit(0);
            break;

        default:
            cout << "Wrong choice...Try again" << endl;
            break;
        }
        cout << "Press any key to continue...";
        cin >> random;

    } while (1);

    return 0;
}

/*
Rushikesh
1001
1234567890
My home address
pataderushikesh@gmail.com
*/