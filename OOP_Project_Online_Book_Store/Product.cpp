#include "Product.h"

int Product::totalProduct = 0;

Product::Product()
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
\param name "name" variable of Product will be set
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
\param price "price" variable of Product will be set
*/
void Product::setPrice( double _price)
{
	this->price = _price;
}
/*!
Properties of the Product object will be printed
*/
void Product::printProperties()const
{
	cout << "The Product's ID is: " << ID << endl;
	cout << "The Product's Name is: " << name << endl;
	cout << "The Product's Price is: " << price << endl;
}

string Product::getproduct() const
{
	return "Product";
}
