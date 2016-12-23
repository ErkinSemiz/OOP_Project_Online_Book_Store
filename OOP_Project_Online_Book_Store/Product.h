#pragma once
#include <string>
#include <iostream>
using namespace std;
/**
* @file Product.h
* @Author Tahir Ozdemir (tahirozdemir34@gmail.com)
* @date December, 2016
* @brief Base class for other products.
*
* @details This class involves basic functions and a virtual function for other class that is inherted from this class.
*/
class Product
{
private:
	int ID; /*!< ID of product */ 
	string name; /*!< Name of product */ 
	double price; /*!< Price of product */ 
public:
	//! Default constructor function
	Product();
	//! Default deconstructor function
	~Product();
	//! Return ID of product.
	int getID() const;
	//! Set ID of product.
	void setID(int ID);
	//! Get name of product.
	string getName() const;
	//! Set name of product.
	void setName(const string& name);
	//! Get price of product.
	double getPrice() const;
	//! Set price of product.
	void setPrice(double price);
	//! Virtual function for inherit classes.
	/*!
	 Print informations of product to screen.
	*/
	virtual void printProperties() const;
};
