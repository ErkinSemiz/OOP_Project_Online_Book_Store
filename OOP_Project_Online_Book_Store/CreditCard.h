#pragma once
#include "Payment.h"
/**
* @file CreditCard.h
* @Author Tahir Ozdemir (tahirozdemir34@gmail.com)
* @date December, 2016
* @brief Payment method for customer.
*/
class CreditCard :
	public Payment
{
private:
	long number;  /*!< Card Number */ 
	string type;  /*!< Card Type */ 
	string expDate; /*!< Expire date of card*/ 
public:
	//! Default constructor function
	CreditCard();
	//! Default deconstructor function
	~CreditCard();
	//! Return card number.
	long getNumber() const;

	//! Set card number.
	void setNumber(long number);

	//! Return card type.
	string getType() const;

	//! Set card type.
	void setType(const string& type);

	//! Return expire date of card.
	string getExpDate()const;

	//! Set expire date of card.
	void setExpDate(const string& expDate);

	//! Make a payment with credit card.
	void performPayment();
};

