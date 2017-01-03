#include "ShoppingButton.h"
#include <string>
#include "Customer.h"
#include "ShoppingCart.h"
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
	for (int i = 0; i < customers.size(); i++)
	{		
		if (_username == (*iterator).getUsername() && _password == (*iterator).getPassword())
		{
			shopping_cart->setCustomer(&*iterator);
			return true;			
			flag = 1;
			break;
		}
		iterator = next(customers.begin(), (i + 1));
	}
	if (flag == 0)
	{
		return false;
	}

}
/*!
	Function for adding a product to the customer's shopping cart.
*/
void ShoppingButton::AddProduct(list<Product*>& products)
{

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	int flag = 0;
	string _productname;
	cout << "Enter the name of the product that you wish to add: ";
	getline(cin, _productname);
	auto iterator = products.begin();
	for (int i = 0; i < products.size(); i++)
	{
		if ((*iterator)->getName() == _productname)
		{
			shopping_cart->addProduct(*iterator);
			/*double current_bonus = shopping_cart->getCustomer()->getBonus();
			shopping_cart->getCustomer()->setBonus(current_bonus + ((*iterator)->getPrice()) / 100);*/
			flag = 1;		
		}
		iterator = next(products.begin(), (i + 1));
	}
	if (flag == 0)
	{
		cout << "Product not found." << endl;
	}
}
/*!
	Function for removing a product from the customer's shopping cart.
*/
void ShoppingButton::RemoveProduct(list<Product*>& products)
{	

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	int flag = 0;
	string _productname;
	cout << "Enter the name of the product that you wish to remove: ";
	
	getline(cin, _productname);
	auto iterator = products.begin();
	for (int i = 0; i < products.size(); i++)
	{
		if ((*iterator)->getName() == _productname)
		{
			shopping_cart->removeProduct(*iterator);
			flag = 1;
		}
		iterator = next(products.begin(), i + 1);
	}
	if (flag == 0)
	{
		cout << "Product not found." << endl;
	}
}
/*!
	Function for listing the customer's shopping cart.
*/
void ShoppingButton::ListShoppingCart(list<Product*>& products)
{
	shopping_cart->printProducts();
}
/*!
	 Function for showing the bonus that the customer has.
*/
void ShoppingButton::ShowBonus()
{
	this->shopping_cart->getCustomer()->getBonus();
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

