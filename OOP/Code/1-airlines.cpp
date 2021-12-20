

#include<iostream>
using namespace std;

class Indigo_Airlines
{
 private:
 string P_name;
 int age;
 string F_info,dept,source,dest;
 public:
  void accept()
  {
  cout<<"\n Enter the details of passenger"<<endl;
  cout<<"\n Passenger name:"<<endl;
  cin>>P_name;
  cout<<"\n Passenger age:"<<endl;
  cin>>age;
  cout<<"\n Flight no.:" <<endl;
  cin>>F_info;
  cout<<"\n Departure time:" <<endl;
  cin>>dept;
  cout<<"\n Source:" <<endl;
  cin>>source;
  cout<<"\n Destination:" <<endl;
  cin>>dest;
  }

  void display();
};
