#include "CustomerButton.h"
#include <string>
CustomerButton::CustomerButton()
{
}
CustomerButton::~CustomerButton()
{
}
/*!
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
		cout << "Enter username : ";
		cin >> _username;
		auto iterator = std::find_if(customers.begin(), customers.end(), [&](const Customer c) { return c.getUsername() == _username; });
		if (iterator != customers.end()) {
			cout << "This user name has already taken. Please enter a new one." << endl;
		}
		else 
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
