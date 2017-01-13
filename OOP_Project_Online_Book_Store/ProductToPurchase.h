#pragma once
#include "Product.h"
/**
* @file ProductToPurchase.h
* @Author Erkin Semiz (erkin1semiz@gmail.com)
* @date December, 2016
* @brief Keeps informations about purchase that will be bought
*/
class ProductToPurchase
{
private:
	Product* product; /*!< Pointer that point product */ 
	int quantity; /*!< Quantity of purchased product */ 
public:
	//! Default constructor function
	ProductToPurchase();

	//! Default deconstructor function
	~ProductToPurchase();

	//! Return product
	Product* getProduct();

	//! Set product
	void setProduct(Product* product);

	//! Return quantity
	int getQuantity() const;

	//! Set quantity
	void setQuantity(int quantity);
};

