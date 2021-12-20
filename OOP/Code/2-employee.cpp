/*
Employee management system
Name : Rushikesh Patade
Roll no : 19
Panel G
Batch : G2
*/

#include<iostream>
using namespace std;

// Class Employee
class Employee 
{
	// Private access specifier
	private:
	
		// Data members
		string empname, addr, qualification;
		static int empid;
		long int contact;
		float salary;

	// Public access specifier
	public:
		
		// Default constructor definition
		Employee()
		{
			empname = "";
			empid++;
			addr = "";
			contact = 0 ;
			qualification = "";
			salary = 0.0;

		}
		
		// Parameterized constructor definition
		Employee(string n, string a, string q, double s) 
		{
			empname = n;
			addr = a;
			salary = s;
			empid++;
			qualification = q;

		}
		
		// Default parameterized constructor definition	
		Employee(string n = "John", string a = "Home", string q = "B.Tech", double s = 10000.0) 
		{
			empname = n;
			addr = a;
			salary = s;
			empid++;
			qualification = q;

		}
		
		// Copy constructor definition
		Employee(Employee &e) 
		{
			empname = e.empname;
			addr = e.addr;
			empid++;
			salary = e.salary;
		}
		
		// Destructor definition
		~Employee()
		{
			empid--;
			cout << "Employee id removed :" << empid << endl;

		}
		
		void display();     

};

// Use of scope operator to define function - display
inline void Employee::display(){

      cout << "Employee Details" << endl;
      cout << "Employee name" << empname << endl;
      cout << "Employee ID" << empid << endl;
      cout << "Employee contact" << contact << endl;
      cout << "Employee qualification" << qualification << endl;
      cout << "Employee salary" << salary << endl;


}

// Initialization of the static variable
int Employee::empid = 0;    

// Driver code
int main(){

	// Accept size of array - n
	int n;
	cout << "Enter number of Employees"<<endl;
	cin >> n;

	
	Employee obj1;
	cout << "object 1"<<endl;
	obj1.display(); 

	Employee obj2;
	cout << "object 2"<<endl;
	obj2.display();

	Employee e3("abc","bcd","988989898",21);
	cout << "object 3"<<endl;
	e3.display();

	Employee e4(obj2);
	cout << "object 4" << endl;
	e4.display();

	// Making an array pointer of size of n - type Employee
	Employee *emp = new Employee[n];
	
	// Use of copy constructor
	emp[0] = Employee(obj2);
	
	// Use of parameterized constructor
	emp[1] = Employee("pqr", "be", "4534556", 6565454);
	
	// Display all Employees
	for(int i = 0; i < 3 ; i++)
		emp[i].display();

	delete []emp;

}



     
