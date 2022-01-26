#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <string.h>
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

using namespace std;

class marksheet
{
private:
    char Name[20];
    long int PRN;
    int Maths, Physics, Chemistry, total;
    char grade;

public:
    marksheet()
    {
        strcpy(Name, "-");
        PRN = 0;
        Physics = Maths = Chemistry = 0;
        total = Physics + Maths + Chemistry;
        grade = '-';
    }
    marksheet(char name[20], long int prn, int phy, int math, int chem)
    {
        strcpy(this->Name, name);
        this->PRN = prn;
        this->Physics = phy;
        this->Maths = math;
        this->Chemistry = chem;
        total = this->Physics + this->Maths + this->Chemistry;
        this->grade = grade_func(this->total);
        cout << BOLDGREEN << "Data is Recorded Successfully" << RESET << endl;
    }
    void modify(int phy, int chem, int maths, int total, char grade)
    {

        this->Physics = phy;
        this->Chemistry = chem;
        this->Maths = maths;
        this->total = total;
        this->grade = grade;
    }
    char grade_func(int total)
    {
        float percentage = (total / 3);
        if (percentage >= 75)
            return 'A';
        else if (percentage >= 60 && percentage < 75)
            return 'B';
        else if (percentage >= 45 && percentage < 60)
            return 'C';
        else if (percentage >= 35 && percentage < 45)
            return 'D';
        else
            return 'F';
    }
    void displayRecords()
    {
        cout << endl
             << BOLDBLUE << "\t\tStudent Details" << RESET << endl;
        cout << "|" << setw(15) << "PRN"
             << " |" << setw(15) << "Name"
             << " |" << setw(15) << "Physics"
             << " |" << setw(15) << "Maths"
             << " |" << setw(15) << "Chemistry"
             << " |" << setw(15) << "Total"
             << " |" << setw(15) << "Grade";
        cout << endl
             << "|" << setw(15) << this->PRN << " |" << setw(15) << this->Name << " |" << setw(15) << this->Physics << " |" << setw(15) << this->Maths << " |" << setw(15) << this->Chemistry << " |" << setw(15) << this->total << " |" << setw(15) << this->grade;
        cout << endl;
    }
    int get_data()
    {
        return this->PRN;
    }
};

class teacher : public marksheet
{
private:
    char name[20];
    long int prn;
    int maths,
        chem,
        phy;
    int count = 0;

public:
    friend class admin;
    void accept_name()
    {
        cout << endl
             << BOLDBLUE
            "Enter Details of Students"
             << RESET << endl;
        cout << endl
             << "Enter Name and PRN :: ";
        cin >> name >> prn;
    }
    int accept_data()
    {
        count = 0;
        try
        {
            cout << endl
                 << "Enter Maths Marks :: ";
            cin >> maths;
            if (maths < 0 || maths > 100)
            {
                throw(maths);
            }
            else
            {
                count++;
            }
            cout << endl
                 << "Enter Chemistry Marks :: ";
            cin >> chem;
            if (chem < 0 || chem > 100)
            {
                throw(chem);
            }
            else
            {
                count++;
            }
            cout << endl
                 << "Enter Physics Marks :: ";
            cin >> phy;
            if (phy < 0 || phy > 100)
            {
                throw(phy);
            }
            else
            {
                count++;
            }
        }
        catch (int marks)
        {
            cout << BOLDRED << "Entered Marks out of Range" << RESET << endl;
        }
        return count;
    }
    void add_data()
    {
        accept_name();
        count = accept_data();
        if (count == 3)
        {
            fstream file;
            file.open("data.txt", ios::app | ios::binary);
            marksheet ms1(name, prn, phy, maths, chem);
            file.seekp(0, ios::end);
            if (!file.is_open())
            {
                cout << endl
                     << BOLDRED << "File cannot be created." << RESET << endl;
            }
            file.write((char *)&ms1, sizeof(marksheet));
            file.close();
        }
        else
        {
            cout << endl
                 << BOLDRED << "Incorrect Info added" << RESET << endl;
        }
    }
};

// Class admin - inheritance from marksheet
class admin : public marksheet
{
private:
    string name;
    int count;
    long int prn_search,
        position;
    int temp = 0;

public:
    void search_data()
    {
        bool flag = 0;
        marksheet ms1;
        cout << endl
             << "Enter PRN to search in the Database :: ";
        cin >> prn_search;
        ifstream file;
        file.open("data.txt", ios::in);
        while (file.read((char *)&ms1, sizeof(ms1)))
        {
            if (ms1.get_data() == prn_search)
            {
                ms1.displayRecords();
                flag = 1;
                break;
            }
            else
                flag = 0;
        }
        if (flag == 0)
        {
            cout << endl
                 << BOLDRED << "Entered Record not found in the Database" << RESET << endl;
        }
        file.close();
    }
    void update_data()
    {
        bool flag = 0, temp = 0;
        marksheet ms1;
        cout << endl
             << "Enter PRN to search in the Database :: ";
        cin >> prn_search;
        fstream file;
        file.open("data.txt", ios::in | ios::out);
        while (file.read((char *)&ms1, sizeof(ms1)))
        {
            if (ms1.get_data() == prn_search)
            {
                flag = 1;
                break;
            }
            else
            {
                flag = 0;
            }
        }
        if (flag == 1)
        {
            long int pos = (temp) * sizeof(ms1);
            file.seekp(pos);
            int m, p, c, tot;
            char grd;
            cout << endl
                 << BOLDWHITE << "Enter the new marks of student" << RESET << endl
                 << endl;
            try
            {
                cout << "Enter the Maths marks : " << endl;
                cin >> m;
                if (m < 0 || m > 100)
                    throw(m);
                cout << "Enter the Physics marks : " << endl;
                cin >> p;
                if (p < 0 || p > 100)
                    throw(p);
                cout << "Enter the Chemistry marks : " << endl;
                cin >> c;
                if (c < 0 || c > 100)
                    throw(c);
            }
            catch (int marks)
            {
                cout << BOLDRED << "Entered Marks out of Range" << RESET << endl;
            }
            tot = m + p + c;
            float percentage = tot / 3;
            grd = ms1.grade_func(tot);
            ms1.modify(p, c, m, tot, grd);
            file.write((char *)&ms1, sizeof(ms1));
            cout << BOLDGREEN << "Database has been Modified" << RESET << endl;
            file.close();
        }
        else
        {
            cout << BOLDRED << "Entered Record not found in the Database" << RESET << endl;
            cout << BOLDRED << "Data Could not be deleted" << RESET << endl;
        }
    }
    void delete_data()
    {
        bool flag = 0;
        marksheet ms1;
        ifstream file1;
        file1.open("data.txt", ios::app);
        cout << endl
             << "Enter PRN to search in the Database :: ";
        cin >> prn_search;
        fstream file2;
        file2.open("Temp.txt", ios::app);
        file1.seekg(0, ios::beg);
        while (file1.read((char *)&ms1, sizeof(ms1)))
        {
            if (ms1.get_data() == prn_search)
            {
                flag = 1;
                break;
            }
            else
            {
                file2.write((char *)&ms1, sizeof(ms1));
                flag = 0;
            }
        }
        if (flag == 0)
        {
            cout << endl
                 << "Entered Record not found in the Database";
            cout << endl
                 << "Data Could not be deleted";
        }
        else
        {
            cout << endl
                 << BOLDGREEN << "Data Deleted Successfully" << RESET << endl;
        }
        file2.close();
        file1.close();
        remove("data.txt");
        rename("Temp.txt", "data.txt");
    }
};

int main()
{
    clrscr
        teacher t;
    admin ad;
    int choice1;
    char choice2, choice3, random;
    do
    {

        cout << endl
             << BOLDCYAN << "\t\tStudent Record" << RESET;
        cout << endl
             << endl
             << BOLDWHITE << "\tLogin Menu" << RESET;
        cout << endl
             << "\t1. Create New Records" << endl
             << "\t2. Search a Record" << endl
             << "\t3. Modify a Record" << endl
             << "\t4. Delete a Record" << endl
             << "\t5. Exit" << endl;
        cout << endl
             << "Enter Choice :: ";
        cin >> choice1;
        switch (choice1)
        {
        case 1:
            t.add_data();
            break;
        case 2:
            ad.search_data();
            break;

        case 3:
            ad.update_data();
            break;

        case 4:
            ad.delete_data();
            break;

        case 5:
            clrscr
                    cout
                << BOLDRED << "Program has been Terminated" << endl
                << "Exiting..." << RESET;
            exit(0);

        default:
            cout << endl
                 << BOLDRED << "Invalid Input" << RESET << endl;
            break;

            break;
        }
        cout << BOLDBLACK << "Press any key to continue..." << RESET << endl;
        cin >> random;

        clrscr
    } while (choice1 != 3);
    return 0;
}

/*
1
Rushikesh 1032200845
100
80
90
.
1
Name 1032200846
90
87
70
.
1
Another 1032200842
60
100
80
.

*/