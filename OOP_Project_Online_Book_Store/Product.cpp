#include "Product.h"

/*! \return The ID of the Product */
int Product::getID() const
{
	return ID;
}
/*! 
\param ID "ID" variable of Product will be set
*/
void Product::setID(int ID)
{
	this->ID = ID;
}
/*! \return The name of the Product */
string Product::getName() const
{
	return name;
}
/*! 
\param name "name" variable of Product will be set
*/
void Product::setName(const string& name)
{
	this->name = name;
}
/*! \return The price of the Product  */
double Product::getPrice() const
{
	return price;
}
/*!
\param price "price" variable of Product will be set
*/
void Product::setPrice(double price)
{
	this->price = price;
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
