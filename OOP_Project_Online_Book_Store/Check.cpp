#include "Check.h"



Check::Check()
{
}


Check::~Check()
{
}

void Check::performPayment()
{
	cout << "Payment is made with check." << endl;
}

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
