#pragma once
#include <iostream>
#include "Product.h"
#include "Book.h"
#include "Magazine.h"
#include "MusicCD.h"
#include <list>
/**
* @file ProductButton.h
* @Author Mahmut Bilgehan Serbest (bilgehanserbest@gmail.com)
* @date December, 2016
* @brief Class for creating "ProductButton"s to be used in the main menu.
*
* @details This class invloves functions and variables for "ProductButton"s
*/
class ProductButton {
public:
	//! Default constructor function for ProductButton class.
	ProductButton();
	//! Destructor function for ProductButton class.
	~ProductButton();
	//! The submenu for adding a product to the system.
	void Add(list<Product*>& products);
	//! The submenu for showing the products in the system.
	void Show(list<Product*>& products) const;
};
