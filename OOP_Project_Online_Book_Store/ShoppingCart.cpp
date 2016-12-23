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

void ShoppingCart::setPaymentMethod(Payment* const payment_method)
{
	paymentMethod = payment_method;
}

void ShoppingCart::setCustomer(Customer* const customer)
{
	this->customer = customer;
}

void ShoppingCart::setBonusUsed(const bool is_bonus_used)
{
	isBonusUsed = is_bonus_used;
}

Payment* const& ShoppingCart::getPaymentMethod() const
{
	return paymentMethod;
}

Customer* const& ShoppingCart::getCustomer() const
{
	return customer;
}
