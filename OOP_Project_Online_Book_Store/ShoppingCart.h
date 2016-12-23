#pragma once
#include "ProductToPurcase.h"
#include "Payment.h"
#include "Customer.h"
#include <list>
/**
* @file ShoppingCart.h
* @Author Tahir Ozdemir (tahirozdemir34@gmail.com)
* @date December, 2016
* @brief Keeps products that will be bought and customer that using the "shopping cart"
*/
class ShoppingCart
{
private:
	list<ProductToPurcase*> productsToPurchase; /*!< Keeps a list of purchased products */ 
	Payment* paymentMethod; /*!< Payment method for shopping */
	Customer* customer;
	bool isBonusUsed;
public:
	//! Default constructor function
	ShoppingCart();

	//! Default constructor function
	~ShoppingCart();
	
	//! Return payment method
	Payment* getPaymentMethod();
	
	//! Set payment method
	void setPaymentMethod(const Payment* paymentMethod);
	
	//! Return customer
	Customer* getCustomer();
	
	//! Set customer
	void setCustomer(const Customer* customer);
	
	//! Use bonu for shopping
	void setBonusUsed();

	//! Add product to shopping char
	void addProduct(const Product* product);
	
	//! Remove product from shopping char
	void removeProduct(const Product* procuct);
	
	//! Place order
	void placeOrder();
	
	//! Cancel order
	void cancelOrder();
	
	//! Print products in shopping cart to screen
	void printProducts() const;

	//! Print invoice to screen
	void showInvoice();
};

