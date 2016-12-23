#include "Customer.h"



Customer::Customer()
{
}


Customer::~Customer()
{
}

void Customer::sendBill() const
{
	cout << "Invoice sent to " << email << endl;
}

const long& Customer::getCustomerID() const
{
	return customerID;
}

void Customer::setCustomerID(const long customer_id)
{
	customerID = customer_id;
}

const string& Customer::getName() const
{
	return name;
}

void Customer::setName(const string& name)
{
	this->name = name;
}

const string& Customer::getAdress() const
{
	return adress;
}

void Customer::setAdress(const string& adress)
{
	this->adress = adress;
}

const string& Customer::getPhone() const
{
	return phone;
}

void Customer::setPhone(const string& phone)
{
	this->phone = phone;
}

const double& Customer::getBonus() const
{
	return bonus;
}

void Customer::setBonus(const double bonus)
{
	this->bonus = bonus;
}

const string& Customer::getEmail() const
{
	return email;
}

void Customer::setEmail(const string& email)
{
	this->email = email;
}

const string& Customer::getUsername() const
{
	return username;
}

void Customer::setUsername(const string& username)
{
	this->username = username;
}

const string& Customer::getPassword() const
{
	return password;
}

void Customer::setPassword(const string& password)
{
	this->password = password;
}

bool Customer::checkAccount(const string& username, const string& password) const
{
	if (this->username == username&&this->password == password)
		return true;
	else
		return false;
	
}

void Customer::addBonus(double bonus)
{
}

void Customer::useBonus()
{
}

