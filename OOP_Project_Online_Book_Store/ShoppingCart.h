#pragma once
#include "ProductToPurchase.h"
#include "Payment.h"
#include "Customer.h"
#include <list>
#include <algorithm>
/**
* @file ShoppingCart.h
* @Authors Tahir Ozdemir (tahirozdemir34@gmail.com),Erkin Semiz (erkin1semiz@gmail.com),Mahmut Bilgehan Serbest (bilgehanserbest@gmail.com)
* @date December, 2016
* @brief Keeps products that will be bought and customer that using the "shopping cart"
*/
class ShoppingCart
{
private:
	list<ProductToPurchase*> productsToPurchase; /*!< Keeps a list of purchased products */ 
	Payment* paymentMethod; /*!< Payment method for shopping */
	Customer* customer; /*!< Current customer in the system */
	bool isBonusUsed; /*!< true if bonus will be used for shopping else false */
public:
	//! Default constructor function
	ShoppingCart();

	//! Default constructor function
	~ShoppingCart();
	
	//! Return payment method
	Payment* const& getPaymentMethod() const;

	//! Set payment method
	void setPaymentMethod(Payment* const payment_method);

	//! Return customer
	Customer* const& getCustomer() const;

	//! Set customer
	void setCustomer(Customer* const customer);

	//! Use bonus for shopping
	void setBonusUsed(const bool is_bonus_used);

	//! Add product to shopping char
	void addProduct(Product* product);
	
	//! Remove product from shopping char
	void removeProduct(Product* product);
	
	//! Place order
	void placeOrder();
	
	//! Cancel order
	void cancelOrder();
	
	//! Print products in shopping cart to screen
	bool printProducts() const;

	//! Print invoice to screen
	void showInvoice();
};

