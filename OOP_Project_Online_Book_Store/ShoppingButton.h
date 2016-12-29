#pragma once
#include <iostream>
#include "ShoppingCart.h"
#include "CustomerButton.h"
#include "ProductButton.h"
using namespace std;
class ShoppingButton {
	ShoppingCart *shopping_cart;
public:
	ShoppingButton();
	~ShoppingButton();
	bool Login(list<Customer>& customers);
	void AddProduct(list<Product*>& products);
	void RemoveProduct(list<Product*>& products);
	void ListShoppingCart(list<Product*>& products);
	void ShowBonus();
	//void UseBonus();
	void PlaceOrder();
	void CancelOrder();
	void ShowInvoice();
};