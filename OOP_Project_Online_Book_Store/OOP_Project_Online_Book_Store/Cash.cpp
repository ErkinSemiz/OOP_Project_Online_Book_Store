#include "Cash.h"


/*! Cash constructor. */
Cash::Cash()
{
}

/*! Cash destructor. */
Cash::~Cash()
{
}
/*! Performs the payment with cash. */
void Cash::performPayment()
{
	cout << getAmount() << " is paid with cash." << endl;
}
