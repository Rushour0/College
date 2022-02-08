#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class employee
{
    int id;
    char name[20];
    int sal;
    friend class hashing;
};

class hashing
{
    private:
        employee e;
        fstream file;
    public:
        hashing();
        void display();
        void LinearProbingWithoutReplacement();
        void linearprobingwithreplacement();
        void searching(int id);
        void modify(int id);
};

hashing::hashing()
{
    file.open("data.dat",ios::out);
    file.seekp(0,ios::end);
    for(int i=0;i<10;i++)
    {
        e.id=-1;
        e.sal=-1;
        strcpy(e.name,"----");
        file.write((char*)&e,sizeof(e));
    }
    file.close();
}

void hashing::LinearProbingWithoutReplacement()
{
    int loc,i,choice;
    employee temp;
    file.open("data.dat",ios::in|ios::out);
    do
    {
        fflush(stdin);
        file.seekp(0,ios::beg);
        cout<<"\nEnter Employee ID:";
        cin>>e.id;
        cout<<"\nEnter Employee Name:";
        cin>>e.name;
        cout<<"\nEnter Employee Salary:";
        cin>>e.sal;
        loc=e.id%10;
        file.seekp((long int)loc*sizeof(e),ios::beg);
        file.read((char*)&temp,sizeof(employee));
        if(temp.id==-1)
        {
            file.seekp((long int)loc*sizeof(employee),ios::beg);
            file.write((char*)&e,sizeof(employee));
            cout<<"\nSUCCESSFULLY INSERTED";
        }
        else
        {
            for(i=((loc+1)%10);i!=loc;i=(i+1)%10)
            {
                file.seekp((long int)i*sizeof(employee),ios::beg);
                file.read((char*)&temp,sizeof(temp));
                if(temp.id==-1)
                {
                    file.seekp((long int)i*sizeof(employee),ios::beg);
                    file.write((char*)&e,sizeof(employee));
                    cout<<"\nSUCCESSFULLY INSERTED";
                    break;
                }
            }
            if(i==loc)
                cout<<"\n\nINSERTION FAIL.....HASH TABLE FULL";
        }
        cout<<"\nPRESS 1 TO ADD MORE: ";
        cin>>choice;
    }while(choice==1);
    file.close();
}

void hashing::display()
{
    int c=0;
    file.open("data.dat",ios::in);
    cout<<"\nID\tName\tSalary\tIndex";
    for(int i=0;i<10;i++)
    {
        file.read((char*)&e,sizeof(e));
        if(e.id!=-1)
        {
            //c++;
            cout<<endl<<e.id<<"\t"<<e.name<<"\t"<<e.sal<<"\t"<<i;
        }
        else
            cout<<endl<<e.id<<"\t"<<e.name<<"\t"<<e.sal<<"\t"<<i;
            c++;
    }
    file.close();
}

void hashing::searching(int id)
{
    int c=0,i=0;
    file.open("data.dat", ios::in);
    cout<<"\nS.NO\tID\tNAME\tSALARY\tINDEX";
    while(file.read((char *)&e, sizeof(e)))
    {
        if(e.id!=-1)
        {
            if (e.id==id)
            {
                c++;
                cout<<endl<<c<<"\t"<<e.id<<"\t"<<e.name<<"\t"<<e.sal<<"\t"<<i;
            }
        }
        i++;
    }
    file.close();
    if (c==0)
        cout << "\n\n STUDENT NOT EXIST WITH GIVEN ID";
}

void hashing::modify(int id)
{
    int found = 0;
    file.open("data.dat", ios::in | ios::out);
    while (file.read((char *)&e, sizeof(e)) && found == 0)
    {
        if (e.id==id)
        {
            cout << "\nEnter The New Details of book" << endl;
            cout << "\nID: " << e.id;
            cout << "\nNew Name: ";
            cin>>e.name;
            cout << "\nNew Salary: ";
            cin>>e.sal;
            int pos = sizeof(e);
            file.seekp(-pos, ios::cur);
            file.write((char *)&e, sizeof(e));
            cout << "\n\nRecord Updated Successfully...";
            found = 1;
        }
    }
    file.close();
    if (found == 0)
        cout << "\n\n Record Not Found ";
}
void hashing::linearprobingwithreplacement()
{
    int loc,i,choice,newloc;
    employee temp;
    file.open("data.dat",ios::in|ios::out);
    do
    {
        fflush(stdin);
        file.seekp(0,ios::beg);
        cout<<"\nEnter Employee ID:";
        cin>>e.id;
        cout<<"\nEnter Employee Name:";
        cin>>e.name;
        cout<<"\nEnter Employee Salary:";
        cin>>e.sal;
        loc=e.id%10;
        file.seekp((long int)loc*sizeof(e),ios::beg);
        file.read((char*)&temp,sizeof(employee));
        if(temp.id==-1)
        {
            file.seekp((long int)loc*sizeof(employee),ios::beg);
            file.write((char*)&e,sizeof(employee));
            cout<<"\nSUCCESSFULLY INSERTED";
        }
        else
        {
            newloc = temp.id %10;
            if (newloc == loc)
            {


            for(i=((loc+1)%10);i!=loc;i=(i+1)%10)
            {
                file.seekg((long int)i*sizeof(employee),ios::beg);
                file.read((char*)&temp,sizeof(temp));
                if(temp.id==-1)
                {
                    file.seekp((long int)i*sizeof(employee),ios::beg);
                    file.write((char*)&e,sizeof(employee));
                    cout<<"\nSUCCESSFULLY INSERTED";
                    break;
                }
            }
            }
            else
            {
              employee temp1= temp;
            file.seekp(loc*sizeof(e),ios::beg);
            file.write((char*)&e,sizeof(e));

            for(i=((loc+1)%10);i!=loc;i=(i+1)%10)
            {
                file.seekg(i*sizeof(e),ios::beg);
                file.read((char*)&temp,sizeof(temp));

                if(temp.id == -1)
                {
                    file.seekp(i*sizeof(e),ios::beg);
                    file.write((char*)&temp1,sizeof(temp1));
                    break;
                }

            }
            }

            if(i==loc)
                cout<<"\n\nINSERTION FAIL.....HASH TABLE FULL";
        }
        cout<<"\nTO CONTINUE, PRESS 1: ";
        cin>>choice;
    }while(choice==1);
    file.close();
}


int main()
{
    int id,choice,i;
    hashing h;
    do
    {
        cout<<"\n-------------------";
        cout<<"\n1.CREATE WITHOUT REPLACEMENT";
        cout<<"\n2.CREATE WITH REPLACEMENT";
        cout<<"\n3.DISPLAY HASH TABLE";
        cout<<"\n4.SEARCH IN HASH TABLE";
        cout<<"\n5.MODIFY IN HASH TABLE";
        cout<<"\n6.EXIT";
        cout<<"\nENTER YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
            case 1: h.LinearProbingWithoutReplacement();
                    break;

            case 2: h.linearprobingwithreplacement();
                    break;

            case 3: h.display();
                    break;

            case 4: cout<<"\nEnter ID to be search: ";
                    cin>>id;
                    h.searching(id);
                    break;

            case 5: cout<<"\nEnter ID to be modify: ";
                    cin>>id;
                    h.modify(id);

                    break;

            case 6: return 0;

            default:cout<<"\nIncorrect Choice";
        }
    }while(1);
    return 0;
}
