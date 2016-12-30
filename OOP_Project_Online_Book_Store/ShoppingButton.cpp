#include "ShoppingButton.h"
#include <string>
#include "Customer.h"
#include "ShoppingCart.h"
ShoppingButton::ShoppingButton(ShoppingCart* cart)
{
	shopping_cart = cart;
}
ShoppingButton::~ShoppingButton()
{
}
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
			cout << "Product added to your shopping cart." << endl;
		}
		iterator = next(products.begin(), (i + 1));
	}
	if (flag == 0)
	{
		cout << "Product not found." << endl;
	}
}

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
			cout << "Product removed from your shopping cart." << endl;
		}
		iterator = next(products.begin(), i + 1);
	}
	if (flag == 0)
	{
		cout << "Product not found." << endl;
	}
}

void ShoppingButton::ListShoppingCart(list<Product*>& products)
{
	shopping_cart->printProducts();
}

void ShoppingButton::ShowBonus()
{
	this->shopping_cart->getCustomer()->getBonus();
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

