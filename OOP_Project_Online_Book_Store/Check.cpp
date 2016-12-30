#include "Check.h"


/*! Check constructor. */
Check::Check()
{
}

/*! Check destructor. */
Check::~Check()
{
}
/*! Performs the payment with check. */
void Check::performPayment()
{

	cout << getAmount() << " is paid with check." << endl;
	cout << "The Check's name is: " << getName() << endl;
	cout << "The Check's Bank Id is: " << getBankID() << endl;
}
/*!
\return The check name. 
*/
string Check::getName() const
{
	return name;
}
/*!
\param name Name value of check will be set to this
*/
void Check::setName(const string & name)
{
	this->name = name;
}
/*!
\return bankID of the check.
*/
string Check::getBankID() const
{
	return bankID;
}
/*!
\param bankId BankID of check will be set to this
*/
void Check::setBankID(const string & bankID)
{
	this->bankID = bankID;
}
