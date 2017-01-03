#include "CustomerButton.h"
#include <string>

/*!
Constructor function for the CustomerButton class.
*/
CustomerButton::CustomerButton()
{
}
/*!
Destructor function for the CustomerButton class.
*/
CustomerButton::~CustomerButton()
{
}
/*!
The function for adding a customer to the system.
\param customers A list of customers in system
*/
void CustomerButton::Add(list<Customer>& customers)
{
	string _name;
	string _adress;
	string _phone;
	string _email;
	string _username;
	string _password;
	cin.ignore();
	while (true) {
		cout << "Enter name : ";
		getline(cin, _name);
		if (!_name.empty())
			break;
		cout << "You have to enter your name." << endl;
	}
	while (true) {
		cout << "Enter adress : ";
		getline(cin, _adress);
		if (!_adress.empty())
			break;
		cout << "You have to enter your adress." << endl;
	}
	while (true) {
		cout << "Enter phone as (5311234567): ";
		getline(cin, _phone);
		if (_phone.size() == 10)
			break;
		cout << "Enter a proper phone number." << endl;
	}
	cout << "Enter email : ";
	cin >> _email;

	while (true) {
		int flag = 0;
		cout << "Enter username : ";
		cin >> _username;
		auto iterator = customers.begin();
		for (int i = 0; i < customers.size(); i++)
		{
			if (_username == (*iterator).getUsername()) {
				cout << "This user name has already taken. Please enter a new one." << endl;
				flag = 1;
			}
			iterator = next(customers.begin(), (i + 1));
		}
		if (flag == 0)
			break;
	}
	cin.ignore();
	while (true) {
		cout << "Enter password : ";
		getline(cin, _password);
		if (!_password.empty())
			break;
		cout << "You have to set a password." << endl;
	}
	Customer* customer = new Customer(_name, _adress,_phone,_email,_username,_password);
	customers.push_back(*customer);
}
/*!
The function for showing the customers in the system.
\param customers A list of customers in system
*/
void CustomerButton::Show(list<Customer>& customers) const
{
	cout << "Customers\n-------------\n";
	auto iterator = customers.begin();
	for (int i = 0; i < customers.size(); i++)
	{
		cout << (i+1) << ". Customer:\n";
		cout << "Customer ID: " << (*iterator).getCustomerID() << endl;
		cout << "Customer name: " << (*iterator).getName() << endl;
		cout << "Customer adress: " << (*iterator).getAdress() << endl;
		cout << "Customer phone: " << (*iterator).getPhone() << endl;
		cout << "Customer bonus: " << (*iterator).getBonus() << endl;
		cout << "Customer email: " << (*iterator).getEmail() << endl << endl;
		iterator = next(customers.begin(), (i+1));
	}
}
