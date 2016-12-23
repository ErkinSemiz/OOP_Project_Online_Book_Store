#pragma once
#include <iostream>
#include <string>
using namespace std;
/**
* @file Payment.h
* @Author Tahir Ozdemir (tahirozdemir34@gmail.com)
* @date December, 2016
* @brief Base class for other payment types.
*
* @details This class involves basic functions and a virtual function for other class that is inherted from this class.
*/
class Payment
{
private:
	double amount; /*!< Payment amount */ 
public:
	//! Default constructor function
	Payment();
	//! Default deconstructor function
	~Payment();
	//! Return amount
	double getAmount() const;
	//! Set amount
	void setAmount(double amount);
	//! Virtual function for inhert classes.
	/*!
		Make a payment.
	*/
	virtual void performPayment();
};

