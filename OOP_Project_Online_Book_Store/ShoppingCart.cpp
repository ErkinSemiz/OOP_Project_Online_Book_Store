#include "ShoppingCart.h"
#include <iterator>
#include <string>
#include <algorithm>
#include "CreditCard.h"
#include "Cash.h"
#include "Check.h"


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
	double totalPrice = 0;
	auto iterator = productsToPurchase.begin();
	for (int i = 0; i < productsToPurchase.size();i++)
	{
		totalPrice += (*iterator)->getQuantity() * (*iterator)->getProduct()->getPrice();
		iterator = next(productsToPurchase.begin(),i);
	}
	
	

	cout << "What is your payment method ?"
		<< "1.)Credit Card" << endl
		<< "2.)Cash" << endl
		<< "3.)Check" << endl;
	int checkPayment;
	while (true) {
		cin >> checkPayment;
		if (checkPayment > 0 && checkPayment < 4)
			break;
		cout << "Wrong Entry!" << endl;
	}
	string type;
	string ed;
	string _name;
	string _bankID;
	
	switch (checkPayment) {
	case 1:
		CreditCard* Card = new CreditCard();
		cout << "Please Enter Card Number : ";
		long cn;
		cin >> cn;
		Card->setNumber(cn);
		cout << "Please Enter Type Of The Card: ";		
		getline(cin, type);
		Card->setType(type);
		cout << "Please Enter The Expire Date: ";		
		getline(cin, ed);
		Card->setAmount(totalPrice);
		Card->setExpDate(ed);
		setPaymentMethod(Card);
		break;
	case 2:
		Cash* _Cash = new Cash();
		_Cash->setAmount(totalPrice);
		setPaymentMethod(_Cash);
		break;
	case 3:
		Check* _Check = new Check();
		cout << "Please Enter Check Name : ";		
		cin >> _name;
		_Check->setName(_name);
		cout << "Please Enter The Bank ID : ";		
		cin >> _bankID;
		_Check->setAmount(totalPrice);
		setPaymentMethod(_Check);
		break;
	default:
		break;
	}
	getPaymentMethod()->performPayment();
	this->customer->sendBill();
		//To Do listeyi bosaltýn ha
}

void ShoppingCart::cancelOrder()
{
	//To Do cout cancel edildi bosalt yine stackleri listeleri
}

void ShoppingCart::printProducts() const
{
	//To do productsToPurchasedaki,product name ve quantityleri coutlýcaz 
}

void ShoppingCart::showInvoice()
{
	//To do faturaya iste payment detaylarý felandý coutlýcaz
}

Payment* const& ShoppingCart::getPaymentMethod() const
{
	return paymentMethod;
}

Customer* const& ShoppingCart::getCustomer() const
{
	return customer;
}
