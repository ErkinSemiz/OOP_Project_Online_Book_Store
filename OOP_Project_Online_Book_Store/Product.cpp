#include "Product.h"

int Product::getID() const
{
	return ID;
}

void Product::setID(int ID)
{
	this->ID = ID;
}

string Product::getName() const
{
	return name;
}

void Product::setName(const string& name)
{
	this->name = name;
}

double Product::getPrice() const
{
	return price;
}

void Product::setPrice(double price)
{
	this->price = price;
}

void Product::printProperties()const
{
	cout << "The Product's ID is: " << ID << endl;
	cout << "The Product's Name is: " << name << endl;
	cout << "The Product's Price is: " << price << endl;
}
