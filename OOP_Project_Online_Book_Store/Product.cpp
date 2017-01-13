#include "Product.h"

int Product::totalProduct = 0;
/*! Product constructor.
Increase "totalProduct" by one and set "ID".
\param name Name of the product.
\param price Price of the product.
*/
Product::Product(string name, double price) : name(name), price(price)
{
	ID = ++totalProduct;
}

Product::~Product()
{
}

/*! \return The ID of the Product */
int Product::getID() const
{
	return ID;
}
/*! 
\param ID "ID" variable of Product will be set
*/
void Product::setID(int _ID)
{
	this->ID = _ID;
}
/*! \return The name of the Product */
string Product::getName() const
{
	return name;
}
/*! 
\param _name "name" variable of Product will be set
*/
void Product::setName(const string& _name)
{
	this->name = _name;
}
/*! \return The price of the Product  */
double Product::getPrice() const
{
	return price;
}
/*!
\param _price "price" variable of Product will be set
*/
void Product::setPrice( double _price)
{
	this->price = _price;
}

