#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
/**
* @file Product.h
* @Author Erkin Semiz (erkin1semiz@gmail.com)
* @date December, 2016
* @brief Base class for other products.
*
* @details This class involves basic functions and a virtual function for other class that is inherted from this class.
*/
class Product
{
private:
	static int totalProduct;
	int ID; /*!< ID of product */ 
	string name; /*!< Name of product */ 
	double price; /*!< Price of product */ 
public:
	//! Default constructor function
	Product(string name, double price);
	//! Default deconstructor function
	~Product();
	//! Return ID of product.
	int getID() const;
	//! Set ID of product.
	void setID( int ID);
	//! Get name of product.
	string getName() const;
	//! Set name of product.
	void setName(const string& name);
	//! Get price of product.
	double getPrice() const;
	//! Set price of product.
	void setPrice(double price);
	//! Virtual function for inherit classes.
	virtual void printProperties() const = 0;
};