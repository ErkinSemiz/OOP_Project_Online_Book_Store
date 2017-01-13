#include "ShoppingButton.h"
#include <string>
/*!
  \param cart Sets shopping cart for the current shopping operation.
*/
ShoppingButton::ShoppingButton(ShoppingCart* cart)
{
	shopping_cart = cart;
}
ShoppingButton::~ShoppingButton()
{
}
/*!
\param customers A list of customers in the system.
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
\param products A list of Products in the system.
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
\param products A list of Products in the system.
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
\param products A list of Products in the system.
*/
bool ShoppingButton::ListShoppingCart(list<Product*>& products)
{
	return shopping_cart->printProducts();
}
void ShoppingButton::ShowBonus()
{
	cout << this->shopping_cart->getCustomer()->getName() << "' s Bonus: " << this->shopping_cart->getCustomer()->getBonus() << endl;
}
void ShoppingButton::UseBonus()
{
	shopping_cart->setBonusUsed(true);
}
void ShoppingButton::PlaceOrder()
{
	this->shopping_cart->placeOrder();
}
void ShoppingButton::CancelOrder()
{
	this->shopping_cart->cancelOrder();
}
void ShoppingButton::ShowInvoice()
{
	this->shopping_cart->showInvoice();
}