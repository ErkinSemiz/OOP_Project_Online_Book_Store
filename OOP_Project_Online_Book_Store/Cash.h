#pragma once
#include "Payment.h"
/**
* @file Cash.h
* @Author Mahmut Bilgehan Serbest (bilgehanserbest@gmail.com)
* @date December, 2016
* @brief Payment method for customer.
*/
class Cash :
	public Payment
{
public:
	//! Default constructor function
	Cash();
	//! Default deconstructor function
	~Cash();
	//! Make a payment with cash.
	void performPayment();
};

