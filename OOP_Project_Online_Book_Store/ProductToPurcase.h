#pragma once
#include "Product.h"
/**
* @file Product.h
* @Author Tahir Ozdemir (tahirozdemir34@gmail.com)
* @date December, 2016
* @brief Keeps informations about purchase that will be bought
*/
class ProductToPurcase
{
private:
	Product* product; /*!< Pointer that point product */ 
	int quantity; /*!< Quantity of purchased product */ 
public:
	//! Default constructor function
	ProductToPurcase();

	//! Default deconstructor function
	~ProductToPurcase();

	//! Return product
	Product* getProduct() const;

	//! Set product
	void setProduct(Product* product);

	//! Return quantity
	int getQuantity() const;

	//! Set quantity
	void setQuantity(int quantity);
};

