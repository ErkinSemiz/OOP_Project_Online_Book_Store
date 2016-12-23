#include "ShoppingCart.h"



ShoppingCart::ShoppingCart()
{
	customer = new Customer();
}


ShoppingCart::~ShoppingCart()
{
	while (!productsToPurchase.empty()) {
		productsToPurchase.pop_front();
	}
}
