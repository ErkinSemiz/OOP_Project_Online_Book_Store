#include "Payment.h"


/*! Payment constructor. */
Payment::Payment()
{
}

/*! Payment destructor. */
Payment::~Payment()
{
}
/*! \return The amount*/
double Payment::getAmount() const
{
	return amount;
}
/*!
\param amount Amount to pay will be set to this
*/
void Payment::setAmount(double amount)
{
	this->amount = amount;
}

