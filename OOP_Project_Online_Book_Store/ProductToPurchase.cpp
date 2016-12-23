#include "ProductToPurchase.h"



ProductToPurchase::ProductToPurchase()
{
	//product = new Product();
}


ProductToPurchase::~ProductToPurchase()
{
	delete product;
}

Product * ProductToPurchase::getProduct() const
{
	return product;
}
/*!
\param product "product" variable of ProductToPurchase will be set
*/
//void ProductToPurchase::setProduct(Product * product)
//{
//	this->product = product;
//	//TO DO code name, ID, price
//}

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
