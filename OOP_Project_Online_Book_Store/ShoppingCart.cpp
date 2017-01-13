#include "ShoppingCart.h"
#include <iterator>
#include <string>
#include <algorithm>
#include "CreditCard.h"
#include "Cash.h"
#include "Check.h"
#include <time.h>
/*! Shopping Cart constructor. */
ShoppingCart::ShoppingCart()
{
}
/*! Shopping Cart destructor. */
ShoppingCart::~ShoppingCart()
{
	while (!productsToPurchase.empty()) {
		productsToPurchase.pop_front();
	}
	productsToPurchase.clear();
	delete paymentMethod;
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
\param product The product that will be added to the shopping cart
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
\param product The product that will be removed from the shopping cart
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
	if (productsToPurchase.empty()) {
		cout << "Purchase List Is Empty.Please Add Product First" << endl;
		return;
	}
	double totalPrice = 0;
	auto iterator = productsToPurchase.begin();
	for (int i = 0; i < productsToPurchase.size(); i++)
	{
		totalPrice += (*iterator)->getQuantity() * (*iterator)->getProduct()->getPrice();
		iterator = next(productsToPurchase.begin(), i + 1);
	}
	if (isBonusUsed)
	{
		cout << customer->getBonus() << " bonus used." << endl;
		customer->useBonus(totalPrice);
		cout << "After using the bonus new cost is " << totalPrice << endl;
		if (totalPrice == 0) {
			cout << "You don't have to pay for this purchase." << endl;
			return;
		}
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
		int failFlag = 0;
		CreditCard* Card = new CreditCard();
		cout << "Please Enter Card Number : ";
		long long cn;
		cin >> cn;

		while (true) {
			if (cn > pow(10, 15) && cn < pow(10, 17))
				break;
			cout << "Your card number must be 16 digit long. Enter a valid card number: " << endl;
			cin >> cn;
		}
		Card->setNumber(cn);
		cin.ignore();
		int cardTypeDefiner = cn / pow(10, 15);
		if (cardTypeDefiner == 3) {
			cout << "Your card type is American Express." << endl;
			Card->setType("American Express");
			
		}
		else if (cardTypeDefiner == 4) {
			cout << "Your card type is Visa." << endl;
			Card->setType("VISA");

		}
		else if (cardTypeDefiner == 5) {
			cout << "Your card type is Master Card." << endl;
			Card->setType("Master Card");

		}
		else{

		while (true) {
			cout << "Unknown card type. Please Enter Type Of The Card: ";
			getline(cin, type);
			if (!type.empty())
				break;
			cout << "Enter a valid card type." << endl;
		}

		Card->setType(type);
		}
		while (true) {
			cout << "Please Enter The Expire Date(MM/YY): ";
			getline(cin, ed);
			if (ed.empty() || ed.length() != 5 || stoi(ed.substr(0, ed.length() - 2)) > 12) {
				cout << "Enter a valid ExpDate." << endl;
			}
			else {
				struct tm newtime;
				__time64_t long_time;

				// Get time as 64-bit integer.  
				_time64(&long_time);
				// Convert to local time.  
				_localtime64_s(&newtime, &long_time);
				int year = newtime.tm_year + 1900;
				int month = newtime.tm_mon + 1;
				string expYear = ed.substr(ed.length() - 2);
				string expMonth = ed.substr(0, ed.length() - 2);
				if (stoi(expYear) < year - 2000 || stoi(expYear) == year - 2000 && stoi(expMonth) < month) {
					cout << "Your card is expired!" << endl;
					cout << "1. Try a new payment method" << endl;
					cout << "2. Cancel Order" << endl;
					cout << "Choose one: ";
					int subChoice;
					cin >> subChoice;
					if (subChoice == 1) {
						system("cls");
						placeOrder();
					}
					else if (subChoice == 2)
						cancelOrder();
					return;
				}
				break;
			}
		}
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
		cin.ignore();
		while (true) {
			cout << "Please Enter Name : ";
			getline(cin, _name);
			if (!_name.empty())
				break;
			cout << "Enter a valid name." << endl;
		}

		_Check->setName(_name);

		cout << "Please Enter The Bank ID : ";
		cin >> _bankID;
		_Check->setBankID(_bankID);
		_Check->setAmount(totalPrice);
		setPaymentMethod(_Check);
	}
	system("cls");
	getPaymentMethod()->performPayment();
	showInvoice();
	this->customer->sendBill();
	for (iterator = productsToPurchase.begin(); iterator != productsToPurchase.end(); iterator++)
	{
		delete(*iterator);
	}
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
	productsToPurchase.clear();
}
/*!
Prints the products of the shopping cart.
*/
bool ShoppingCart::printProducts() const
{
	if (productsToPurchase.empty()) {
		cout << "Purchase List Is Empty.Please Add Product First" << endl;
		return false;
	}
	cout << "+-----------------------------------------------------------------+" << endl;
	cout << "|  ID  |       Name       |    Quantity    |  Price Per Quantity  |" << endl;
	cout << "+-----------------------------------------------------------------+" << endl;
	auto iterator = productsToPurchase.begin();
	for (int i = 0; i < productsToPurchase.size(); i++)
	{
		cout << "|  " << setw(4) << (*iterator)->getProduct()->getID() << "|  " << left << setw(16) << (*iterator)->getProduct()->getName() << "|  " << setw(14) << (*iterator)->getQuantity() << "|  " << setw(20) << (*iterator)->getProduct()->getPrice() << "|" << endl;
		iterator = next(productsToPurchase.begin(), i + 1);
	}
	cout << "+-----------------------------------------------------------------+" << endl;
	return true;
}
/*!
Shows the invoice to the customer.
*/
void ShoppingCart::showInvoice()
{
	if (productsToPurchase.empty())
	{
		cout << "Purchase List Is Empty.Please Add Product First" << endl;
	}
	else
	{
		double total = 0;
		cout << "+----------------------------------------------------------+" << endl;
		cout << "|       Name       |    Quantity    |  Price Per Quantity  |" << endl;
		cout << "+----------------------------------------------------------+" << endl;
		auto iterator = productsToPurchase.begin();
		for (int i = 0; i < productsToPurchase.size(); i++)
		{
			cout << "|  " << left << setw(16) << (*iterator)->getProduct()->getName() << "|  " << setw(14) << (*iterator)->getQuantity() << "|  " << setw(20) << (*iterator)->getProduct()->getPrice() << "|" << endl;
			total += (*iterator)->getQuantity() * (*iterator)->getProduct()->getPrice();
			iterator = next(productsToPurchase.begin(), i + 1);
		}
		cout << "+----------------------------------------------------------+" << endl;
		cout << "|  Customer Name :  " << left << setw(39) << customer->getName() << "|" << endl;
		cout << "|  Customer Email:  " << setw(39) << customer->getEmail() << "|" << endl;
		cout << "|  Customer Phone:  " << setw(39) << customer->getPhone() << "|" << endl;
		cout << "+----------------------------------------------------------+" << endl;
		cout << "|  Total Price   :  " << setw(39) << total << "|" << endl;
		cout << "+----------------------------------------------------------+" << endl;

		cout << endl;
	}
}
/*!
\return The payment method to be used by the customer.
*/
Payment* const& ShoppingCart::getPaymentMethod() const
{
	return paymentMethod;
}
/*!
\return The customer that owns the Shopping Cart.
*/
Customer* const& ShoppingCart::getCustomer() const
{
	return customer;
}