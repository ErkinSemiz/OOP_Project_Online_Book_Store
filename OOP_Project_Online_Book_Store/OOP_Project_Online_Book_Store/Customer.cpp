#include "Customer.h"

int Customer::totalCustomer = 0;

/*! Customer constructor. */
Customer::Customer()
{
	bonus = 0;
	customerID = ++totalCustomer;
}

/*! Customer destructor. */
Customer::~Customer()
{
}
/*! Sends the invoice to the customer as an e-mail. */
void Customer::sendBill() const
{
	cout << "Invoice sent to " << email << endl;
}
/* \return The customer's ID.*/
const long& Customer::getCustomerID() const
{
	return customerID;
}
/*! \param customer_id Sets the Customer's ID.*/
void Customer::setCustomerID(const long customer_id)
{
	customerID = customer_id;
}
/*! \return The customer's Name. */
const string& Customer::getName() const
{
	return name;
}
/*! \param name Sets the Customer's Name. */
void Customer::setName(const string& name)
{
	this->name = name;
}
/*! \return The customer's Adress. */
const string& Customer::getAdress() const
{
	return adress;
}
/*! \param adress Sets the Customer's Adress. */
void Customer::setAdress(const string& adress)
{
	this->adress = adress;
}
/*! \return The customer's Phone number. */
const string& Customer::getPhone() const
{
	return phone;
}
/*! \param phone Sets the Customer's Phone number.*/
void Customer::setPhone(const string& phone)
{
	this->phone = phone;
}
/*! \return The customer's Bonus. */
const double& Customer::getBonus() const
{
	return bonus;
}
/*! \param bonus Sets the Customer's Bonus.*/
void Customer::setBonus(const double bonus)
{
	this->bonus = bonus;
}
/*! \return The customer's E-mail. */
const string& Customer::getEmail() const
{
	return email;
}
/*! \param email Sets the Customer's E-mail.*/
void Customer::setEmail(const string& email)
{
	this->email = email;
}
/*! \return The customer's Username. */
const string& Customer::getUsername() const
{
	return username;
}
/*! \param username Sets the Customer's username.*/
void Customer::setUsername(const string& username)
{
	this->username = username;
}
/*! \return The customer's password*/
const string& Customer::getPassword() const
{
	return password;
}
/*! \param password Sets the Customer's password.*/
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
	//bunu yazdýk emme bunu mainde listten teker teker kontrol edip dönen boola göre gerekli customer nesnesini cagiracaz.
}

//bunlarý mainde bir ana islem bittikten sonra ekstradan impelement edecez
void Customer::addBonus(double bonus)
{
}

void Customer::useBonus()
{
}

