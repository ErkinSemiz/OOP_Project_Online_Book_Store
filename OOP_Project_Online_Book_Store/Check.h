#pragma once
#include "Payment.h"
/**
* @file Check.h
* @Author Mahmut Bilgehan Serbest (bilgehanserbest@gmail.com)
* @date December, 2016
* @brief Payment method for customer.
*/
class Check :
	public Payment
{
private:
	string name; /*!< Name area of check */ 
	string bankID; /*!< Bank ID */ 
public:
	//! Default constructor function
	Check();
	//! Default deconstructor function
	~Check();
	//! Make a payment with check.
	void performPayment();

	//! Return name
	string getName()const;

	//! Set name
	void setName(const string& name);

	//! Return bank ID
	string getBankID() const;

	//! Set bank ID
	void setBankID(const string& bankID);
};

