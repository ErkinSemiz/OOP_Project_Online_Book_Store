#pragma once
#include "ProductToPurcase.h"
#include "Payment.h"
#include <list>
//Complete this header after create customer class.

class ShoppingCart
{
private:
	list<ProductToPurcase*> productsToPurchase; /*!< Keeps a list of purchased products */ 
	Payment* paymentMethod; /*!< Payment method for shopping */
	//! Default constructor function
	ShoppingCart();

	//! Default constructor function
	~ShoppingCart();
};

