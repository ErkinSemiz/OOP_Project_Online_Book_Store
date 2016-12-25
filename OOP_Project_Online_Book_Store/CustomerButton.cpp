#include "CustomerButton.h"
#include <string>

CustomerButton::CustomerButton()
{
}


CustomerButton::~CustomerButton()
{
}

void CustomerButton::Add(list<Customer>& customers)
{
	string _name;
	string _adress;
	string _phone;
	string _email;
	string _username;
	string _password;
	Customer* customer = new Customer();
	cout << "Enter name : ";
	cin.ignore();
	getline(cin, _name);
	customer->setName(_name);
	cout << "Enter adress : ";
	getline(cin, _adress);
	customer->setAdress(_adress);
	cout << "Enter phone : ";
	getline(cin, _phone);
	customer->setPhone(_phone);
	cout << "Enter email : ";
	cin >> _email;
	customer->setEmail(_email);
	cout << "Enter username : ";
	cin >> _username;
	customer->setUsername(_username);
	cout << "Enter password : ";
	cin.ignore();
	getline(cin, _password);
	customer->setPassword(_password);
	customers.push_back(*customer);
}

void CustomerButton::Show(list<Customer>& customers) const
{
	cout << "Customers\n-------------\n";
	auto iterator = customers.begin();
	for (int i = 0; i < customers.size(); i++)
	{
		cout << i << ". Customer:\n";
		cout << "Customer ID: " << (*iterator).getCustomerID() << endl;
		cout << "Customer name: " << (*iterator).getName() << endl;
		cout << "Customer adress: " << (*iterator).getName() << endl;
		cout << "Customer phone: " << (*iterator).getPhone() << endl;
		cout << "Customer bonus: " << (*iterator).getBonus() << endl;
		cout << "Customer email: " << (*iterator).getEmail() << endl << endl;
		iterator = next(customers.begin(), i);
	}
}
