#include "ProductToPurcase.h"



ProductToPurcase::ProductToPurcase()
{
	//product = new Product();
}


ProductToPurcase::~ProductToPurcase()
{
	delete product;
}

Product * ProductToPurcase::getProduct() const
{
	return product;
}
/*!
\param product "product" variable of ProductToPurcase will be set
*/
void ProductToPurcase::setProduct(Product * product)
{
	this->product = new Product();
	//TO DO code name, ID, price
}

int ProductToPurcase::getQuantity() const
{
	return quantity;
}
/*!
\param quantity "quantity" variable of ProductToPurchase will be set to
*/
void ProductToPurcase::setQuantity(int quantity)
{
	this->quantity = quantity;
}
