#include "ProductToPurchase.h"



ProductToPurchase::ProductToPurchase()
{
}


ProductToPurchase::~ProductToPurchase()
{
}
/*! \return The product to purchase. */
Product * ProductToPurchase::getProduct()
{
	return product;
}
/*!
\param product "product" variable of ProductToPurchase will be set
*/
void ProductToPurchase::setProduct(Product * product)
{
	this->product = product;
}
/*! \return The quantity of the product to purchase. */
int ProductToPurchase::getQuantity() const
{
	return quantity;
}
/*!
\param quantity "quantity" variable of ProductToPurchase will be set to
*/
void ProductToPurchase::setQuantity(int quantity)
{
	this->quantity = quantity;
}
