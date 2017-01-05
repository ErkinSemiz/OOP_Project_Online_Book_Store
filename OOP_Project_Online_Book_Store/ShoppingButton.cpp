#include "ShoppingButton.h"
#include <string>
//#include "Customer.h"
//#include "ShoppingCart.h"

/*!
	Constructor function for ShoppingButton class.
*/
ShoppingButton::ShoppingButton(ShoppingCart* cart)
{
	shopping_cart = cart;
}
/*!
	Destructor function for ShoppingButton class.
*/
ShoppingButton::~ShoppingButton()
{
}
/*!
Function for a customer to log in to the system.
*/
bool ShoppingButton::Login(list<Customer>& customers)
{
	string _username, _password;
	int flag = 0;
	auto iterator = customers.begin();
	cout << "Please Enter Your Username: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//discard characters until newline is found
	getline(cin, _username);
	cout << "Please Enter Your Password: ";
	getline(cin, _password);
	auto it = std::find_if(customers.begin(), customers.end(), [&](const Customer c) { return c.checkAccount(_username,_password); });
	if (it != customers.end()) {
		shopping_cart->setCustomer(&*it);
		return true;
	}
		
	return false;
}
/*!
	Function for adding a product to the customer's shopping cart.
*/
void ShoppingButton::AddProduct(list<Product*>& products )
{

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	int ID;
	cout << "Enter the ID of the product that you wish to add: ";
	cin >> ID;
	auto iterator = std::find_if(products.begin(), products.end(), [&](const Product* pr) { return pr->getID() == ID; });

	if (iterator != products.end()) {
		shopping_cart->addProduct(*iterator);
	}
	else {
		cout << "Product not found." << endl;
	}
}
/*!
	Function for removing a product from the customer's shopping cart.
*/
void ShoppingButton::RemoveProduct(list<Product*>& products)
{	
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	int ID;
	cout << "Enter the ID of the product that you wish to remove: ";
	cin >> ID;
	auto iterator = std::find_if(products.begin(), products.end(), [&](const Product* pr) { return pr->getID() == ID; });

	if (iterator != products.end()) {
		shopping_cart->removeProduct(*iterator);
	}
	else {
		cout << "Product not found." << endl;
	}
}
/*!
	Function for listing the customer's shopping cart.
*/
bool ShoppingButton::ListShoppingCart(list<Product*>& products)
{
	return shopping_cart->printProducts();
}
/*!
	 Function for showing the bonus that the customer has.
*/
void ShoppingButton::ShowBonus()
{
	cout << this->shopping_cart->getCustomer()->getName() << "' s Bonus: " << this->shopping_cart->getCustomer()->getBonus() << endl;
}
/*!
//! Function for a customer to use bonus.
*/
void ShoppingButton::UseBonus()
{
	shopping_cart->setBonusUsed(true);
}
/*!
Function for a customer to place order.
*/
void ShoppingButton::PlaceOrder()
{
	this->shopping_cart->placeOrder();
}
/*!
	Function for a customer to cancel order.
*/
void ShoppingButton::CancelOrder()
{
	this->shopping_cart->cancelOrder();
}
/*!
	 Function to show a customer his/her invoice.
*/
void ShoppingButton::ShowInvoice()
{
	this->shopping_cart->showInvoice();
}