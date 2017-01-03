#include "ShoppingCart.h"
#include <iterator>
#include <string>
#include <algorithm>
#include "CreditCard.h"
#include "Cash.h"
#include "Check.h"

/*! Shopping Cart constructor. */
ShoppingCart::ShoppingCart()
{
	//customer = new Customer();
}
/*! Shopping Cart destructor. */
ShoppingCart::~ShoppingCart()
{
	while (!productsToPurchase.empty()) {
		productsToPurchase.pop_front();
	}
}
/*!
\param payment_method "paymentMethod" variable of the Shopping Cart will be set.
*/
void ShoppingCart::setPaymentMethod(Payment* const payment_method)
{
	paymentMethod = payment_method;
}
/*!
\param customer "customer" variable of the Shopping Cart will be set.
*/
void ShoppingCart::setCustomer(Customer* customer)
{
	this->customer = customer;
}
/*!
\param is_bonus_used Sets whether any bonus will be used.
*/
void ShoppingCart::setBonusUsed(const bool is_bonus_used)
{
	isBonusUsed = is_bonus_used;
}
/*!
\param product Adds a new product to the shopping cart.
*/
void ShoppingCart::addProduct(Product* product)
{
	auto iterator = productsToPurchase.begin();
	for (int i = 0; i < productsToPurchase.size(); i++)
	{
		if ((*iterator)->getProduct() == product)
		{
			cout << "How many " << product->getName() << " do you want to add : ";
			int productCount;
			cin >> productCount;
			if (productCount <= 0)
			{
				cout << "Invalid Entry!" << endl;
				break;
			}
			productCount += (*iterator)->getQuantity();
			(*iterator)->setQuantity(productCount);
			return;
		}
		iterator = next(productsToPurchase.begin(), i + 1);
	}
		ProductToPurchase* a = new ProductToPurchase();
		a->setProduct(product);
		cout << "How many " << product->getName() << " do you want to add : ";
		int productCount;
		cin >> productCount;
		if (productCount <= 0)
		{
			cout << "Invalid Entry!" << endl;
		}
		else
		{
			a->setQuantity(productCount);
			productsToPurchase.push_back(a);
			cout << "Product added to your shopping cart." << endl;
		}
	}
	/*!
	\param product Removes a product from the Shopping cart.
	*/
	void ShoppingCart::removeProduct(Product* product)
	{
		auto iterator = productsToPurchase.begin();
		for (int i = 0; i < productsToPurchase.size(); i++)
		{
			if ((*iterator)->getProduct() == product)
			{
				cout << "How many " << product->getName() << " item do you want to delete ?" << endl;
				int delquan;
				cin >> delquan;
				if (delquan <= 0)
				{
					cout << "Invalid Entry" << endl;
					break;
				}
				else if (delquan < (*iterator)->getQuantity())
				{
					(*iterator)->setQuantity((*iterator)->getQuantity() - delquan);
					cout << "Product removed from your shopping cart." << endl;
					return;
				}
				else
				{
					productsToPurchase.erase(iterator);
					cout << "Product removed from your shopping cart." << endl;
					return;
				}
			}
			iterator = next(productsToPurchase.begin(), i + 1);
		}
	}
	/*!
	Performs the payment for the items in the Shopping Cart.
	*/
	void ShoppingCart::placeOrder()
	{
		double totalPrice = 0;
		auto iterator = productsToPurchase.begin();
		for (int i = 0; i < productsToPurchase.size(); i++)
		{
			totalPrice += (*iterator)->getQuantity() * (*iterator)->getProduct()->getPrice();
			//getCustomer()->addBonus((*iterator)->getProduct()->getPrice() * (*iterator)->getQuantity() / 100);
			iterator = next(productsToPurchase.begin(), i + 1);
		}
		if(isBonusUsed)
		{
			cout << customer->getBonus() << " bonus Used" << endl;
			customer->useBonus(totalPrice);
			cout << "After using the bonus new cost is " << totalPrice << endl;
		}
		cout << "What is your payment method ?\n"
			<< "1.)Credit Card" << endl
			<< "2.)Cash" << endl
			<< "3.)Check" << endl
			<< "Choose one: ";
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

		if (checkPayment == 1) {
			CreditCard* Card = new CreditCard();
			cout << "Please Enter Card Number : ";
			long cn;
			cin >> cn;
			Card->setNumber(cn);
			cout << "Please Enter Type Of The Card: ";
			cin.ignore();
			getline(cin, type);
			Card->setType(type);
			cout << "Please Enter The Expire Date: ";
			getline(cin, ed);
			Card->setExpDate(ed);
			Card->setAmount(totalPrice);
			Card->setExpDate(ed);
			setPaymentMethod(Card);
		}
		else if (checkPayment == 2) {
			Cash* _Cash = new Cash();
			_Cash->setAmount(totalPrice);
			setPaymentMethod(_Cash);
		}
		else if (checkPayment == 3) {
			Check* _Check = new Check();
			cout << "Please Enter Name : ";
			cin.ignore();
			getline(cin, _name);
			//cin >> _name;
			_Check->setName(_name);
			cout << "Please Enter The Bank ID : ";
			cin >> _bankID;
			_Check->setBankID(_bankID);
			_Check->setAmount(totalPrice);
			setPaymentMethod(_Check);
		}
		getPaymentMethod()->performPayment();
		this->customer->sendBill();
		for (iterator = productsToPurchase.begin(); iterator != productsToPurchase.end(); iterator++)
		{
			delete(*iterator);
		}
		//delete(*productsToPurchase.end());
		//delete(*iterator);
		productsToPurchase.clear();
		isBonusUsed = false;
		customer->setBonus(totalPrice / 100);
	}
	/*!
	Cancels the order and empties the shopping cart.
	*/
	void ShoppingCart::cancelOrder()
	{
		cout << "The order has been canceled." << endl;
		auto iterator = productsToPurchase.begin();
		for (iterator = productsToPurchase.begin(); iterator != productsToPurchase.end(); iterator++)
		{
			delete(*iterator);
		}
		//delete(*iterator);
		productsToPurchase.clear();
	}
	/*!
	Prints the products of the shopping cart.
	*/
	void ShoppingCart::printProducts() const
	{
		auto iterator = productsToPurchase.begin();
		for (int i = 0; i < productsToPurchase.size(); i++)
		{
			cout << "The name of the product: " << (*iterator)->getProduct()->getName() << endl;
			cout << "The quantity of the product: " << (*iterator)->getQuantity() << endl;
			cout << "The price of the product (per quantity): " << (*iterator)->getProduct()->getPrice() << endl;
			iterator = next(productsToPurchase.begin(), i + 1);
		}
	}
	/*!
	Shows the invoice to the customer.
	*/
	void ShoppingCart::showInvoice()
	{
		//Show invoice product to purchase a degil payment methoda calismali
		if (productsToPurchase.empty())
		{
			cout << "Purchase List Is Empty.Please Add Product First" << endl;
		}
		else
		{
			//cout << "The payment method is: " << typeid(this->getPaymentMethod()).name() << endl;
			cout << "The products are: " << endl;
			auto iterator = productsToPurchase.begin();
			for (int i = 0; i < productsToPurchase.size(); i++)
			{
				cout << "Product name: " << (*iterator)->getProduct()->getName() << endl;
				cout << "Product ID: " << (*iterator)->getProduct()->getID() << endl;
				cout << "The product's price: " << (*iterator)->getProduct()->getPrice() << endl;
				iterator = next(productsToPurchase.begin(), i + 1);
			}
			cout << endl;
			//this->getPaymentMethod()->performPayment();
		}
	}
	/*!
	\return the payment method to be used by the customer.
	*/
	Payment* const& ShoppingCart::getPaymentMethod() const
	{
		return paymentMethod;
	}
	/*!
	\return the customer that owns the Shopping Cart.
	*/
	Customer* const& ShoppingCart::getCustomer() const
	{
		return customer;
	}