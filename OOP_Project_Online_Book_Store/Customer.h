#pragma once
#include <string>
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
	long customerID;  /*!< Customer ID */ 
	string Name; /*!< Customer name */ 
	string adress; /*!< Customer adress */ 
	string phone; /*!< Customer phone number */ 
	double bonus; /*!< Customer bonus amount */ 
	string email; /*!< Customer email */ 
	string username; /*!< Customer username for entering system */ 
	string password; /*!< Customer password for entering system */ 
public:
	//! Default constructor function
	Customer();
	//! Default deconstructor function
	~Customer();

	void sedBill();
	//! Return customer ID
	long getCustomerID() const;
	
	//! Set customer ID
	void setCustomerID(long customerID);
	
	//! Return customer name
	string getName() const;
	
	//! Set customer name
	void setName(const string& name);
	
	//! Return customer adress
	string getAdress() const;

	//! Set customer adress
	void setAdress(const string& adress);
	
	//! Return customer phone number
	string getPhone() const;
	
	//! Set customer number
	void setPhone(const string& phone);
	
	//! Return customer bonus amount
	double getBonus() const;

	//! Set customer bonus amount
	void setBonus(double bonus);
	
	//! Return customer email adress
	string getEmail() const;

	//! Set customer email adress
	void setEmail(const string& email);
	
	//! Return customer user name
	string getUserName() const;

	//! Set customer user name
	void setUserName(const string& username);
	
	//! Return customer password
	string getPassword() const;

	//! Set customer password
	void setPassword(const string& password);
	
	//! Check if customer user name and password
	bool checkAccount(const string& username, const string& password) const;

	//! Incread bonus amount of customer
	void addBonus(double bonus);

	//! Use bonus for shopping
	void useBonus();
};

