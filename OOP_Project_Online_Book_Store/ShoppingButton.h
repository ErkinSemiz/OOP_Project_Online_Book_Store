#pragma once
#include <iostream>
#include "ShoppingCart.h"
#include "CustomerButton.h"
#include "ProductButton.h"

/**
* @file ShoppingButton.h
* @Authors Mahmut Bilgehan Serbest (bilgehanserbest@gmail.com)
* @date December, 2016
* @brief Class for creating "ShoppingButton"s to be used in the main menu.
*
* @details This class invloves functions and variables for "ShoppingButton"s
*/
using namespace std;
class ShoppingButton {
	ShoppingCart *shopping_cart;
public:
	//! Constructor function for ShoppingButton class.
	ShoppingButton(ShoppingCart* cart);
	//! Destructor function for ShoppingButton class.
	~ShoppingButton();
	//! Function for a customer to log in to the system.
	bool Login(list<Customer>& customers);
	//! Function for adding a product to the customer's shopping cart.
	void AddProduct(list<Product*>& products);
	//! Function for removing a product from the customer's shopping cart.
	void RemoveProduct(list<Product*>& products);
	//! Function for listing the customer's shopping cart.
	bool ListShoppingCart(list<Product*>& products);
	//! Function for showing the bonus that the customer has.
	void ShowBonus();
	//! Function for a customer to use bonus.
	void UseBonus();
	//! Function for a customer to place order.
	void PlaceOrder();
	//! Function for a customer to cancel order.
	void CancelOrder();
	//! Function to show a customer his/her invoice.
	void ShowInvoice();
};