#include "CreditCard.h"



CreditCard::CreditCard()
{
}


CreditCard::~CreditCard()
{
}
/*!
\return Number of credit card
*/
long CreditCard::getNumber() const
{
	return number;
}
/*!
\param number Number of credit card will be set to this
*/
void CreditCard::setNumber(long number)
{
	this->number = number;
}
/*!
\return Type of credit card
*/
string CreditCard::getType() const
{
	return type;
}
/*!
\param type Type of credit will be set to this
*/
void CreditCard::setType(const string & type)
{
	this->type = type;
}
/*!
\return Expire date of credit card
*/
string CreditCard::getExpDate() const
{
	return expDate;
}
/*!
\param expDate Expire date of credit card will be set to this
*/
void CreditCard::setExpDate(const string & expDate)
{
	this->expDate = expDate;
}

void CreditCard::performPayment()
{
	cout << "Payment is made with credit card." << endl;
}
