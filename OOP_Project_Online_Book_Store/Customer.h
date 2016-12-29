#pragma once
#include <string>
#include <iostream>
using namespace std;
/**
* @file Customer.h
* @Author Tahir Ozdemir (tahirozdemir34@gmail.com)
* @date December, 2016
* @brief Customer Class
*
* @details Contains basic functions and informations of a customer.
*/
class Customer
{
private:
	static int totalCustomer;
	long customerID;  /*!< Customer ID */ 
	string name; /*!< Customer name */ 
	string adress; /*!< Customer adress */ 
	string phone; /*!< Customer phone number */ 
	double bonus; /*!< Customer bonus amount */ 
	string email; /*!< Customer email */ 
	string username; /*!< Customer username for entering system */ 
	string password; /*!< Customer password for entering system */ 
public:
	//! Default constructor function
	Customer(string _name, string _adress, string _phone, string _email, string _username, string _password );
	//! Default deconstructor function
	~Customer();

	void sendBill() const;
	//! Return customer ID
	const long& getCustomerID() const;
	//! Set customer ID
	void setCustomerID(const long customer_id);
	//! Return customer name
	const string& getName() const;
	//! Set customer name
	void setName(const string& name);
	//! Return customer adress
	const string& getAdress() const;
	//! Set customer adress
	void setAdress(const string& adress);
	//! Return customer phone number
	const string& getPhone() const;
	//! Set customer number
	void setPhone(const string& phone);
	//! Return customer bonus amount
	const double& getBonus() const;
	//! Set customer bonus amount
	void setBonus(const double bonus);
	//! Return customer email adress
	const string& getEmail() const;
	//! Set customer email adress
	void setEmail(const string& email);
	//! Return customer user name
	const string& getUsername() const;
	//! Set customer user name
	void setUsername(const string& username);
	//! Return customer password
	const string& getPassword() const;
	//! Set customer password
	void setPassword(const string& password);

	//! Check if customer user name and password
	bool checkAccount(const string& username, const string& password) const;

	//! Incread bonus amount of customer
	void addBonus(double bonus);

	//! Use bonus for shopping
	void useBonus();
};

