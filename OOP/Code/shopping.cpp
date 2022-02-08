#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void showlist(list<string> l)
{
	list<string>::iterator it;
	for (it = l.begin(); it != l.end(); ++it)
		cout << '\n'
		     << *it;
	cout << '\n';
}

int main()
{
	list<string> shopping;
	shopping.push_back("eggs");
	shopping.push_back("milk");
	shopping.push_back("sugar");
	shopping.push_back("chocolate");
	shopping.push_back("flour");

	list<string>::iterator it;
	cout << endl
	     << "Shopping List" << endl;
	showlist(shopping);

	shopping.pop_front();
	shopping.push_front("coffee");

	cout << endl
	     << "Shopping List after Popping and adding Coffee";
	showlist(shopping);

	for (it = shopping.begin(); it != shopping.end(); ++it)
	{
		if (*it == "sugar")
		{
			*it = "honey";
			break;
		}
	}

	for (it = shopping.begin(); it != shopping.end(); ++it)
	{
		if (*it == "milk")
		{
			break;
		}
	}

	shopping.insert(it, "baking powder");

	cout << endl
	     << "Shopping List after replacing and adding elements";
	showlist(shopping);

	shopping.sort();

	cout << endl
	     << "Final Sorted List";
	showlist(shopping);

	string s;
	bool flag;
	int i = 0;
	cout << "\nEnter element to search in list:";
	cin >> s;

	for (it = shopping.begin(); it != shopping.end(); ++it)
	{
		if (*it == s)
		{
			flag = true;
			break;
		}
		i++;
	}

	if (!flag)
		cout << "\nElement not found!";
	else
	{
		cout << "\nElement " << s << " found at index: " << i << endl;
	}
	return 0;
}