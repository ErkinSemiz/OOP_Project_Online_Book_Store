#include "ShoppingCart.h"
#include <iterator>
#include <algorithm>
#include "CreditCard.h"


ShoppingCart::ShoppingCart()
{
	customer = new Customer();
}


ShoppingCart::~ShoppingCart()
{
	while (!productsToPurchase.empty()) {
		productsToPurchase.pop_front();
	}
}

void ShoppingCart::setPaymentMethod(Payment* const payment_method)
{
	paymentMethod = payment_method;
}

void ShoppingCart::setCustomer(Customer* const customer)
{
	this->customer = customer;
}

void ShoppingCart::setBonusUsed(const bool is_bonus_used)
{
	isBonusUsed = is_bonus_used;
}

void ShoppingCart::addProduct(Product* product)
{
	ProductToPurchase* a = new ProductToPurchase();
	a->setProduct(product);
	cout << "How many: " << product->getName() << "do you want to add : ";
	int productCount;
	cin >> productCount;
	a->setQuantity(productCount);
	productsToPurchase.push_front(a);
}

void ShoppingCart::removeProduct(Product* product)
{
		auto iterator = find(productsToPurchase.begin(), productsToPurchase.end(), product);
		if((*iterator)->getProduct() == product)
		{
			cout << "How many " << product->getName() << " item do you want to delete ?" << endl;
			int delquan;
			cin >> delquan;
			if(delquan<(*iterator)->getQuantity())
			{
				(*iterator)->setQuantity((*iterator)->getQuantity() - delquan);
			}
			else
			{
				productsToPurchase.erase(iterator);
			}
		}
}

void ShoppingCart::placeOrder()
{
	cout << "What is your payment method ?"
		<< "1.)Credit Card" << endl
		<< "2.)Cash" << endl
		<< "3.)Check" << endl;
	int checkPayment;
	cin >> checkPayment;
	switch (checkPayment) {
	case 1:
		CreditCard* Card = new CreditCard();
		cout << "Please Enter Card Number : ";
		long cn;
		cin >> cn;
		Card->setNumber(cn);
		cout << "Please Enter Type Of The Card: ";
		string type;
		getline(cin, type);
		Card->setType(type);
		cout << "Please Enter The Expire Date: ";
		string ed;
		getline(cin, ed);
		Card->setExpDate(ed);
		setPaymentMethod(Card);
		break;
	}
}

Payment* const& ShoppingCart::getPaymentMethod() const
{
	return paymentMethod;
}

Customer* const& ShoppingCart::getCustomer() const
{
	return customer;
}
