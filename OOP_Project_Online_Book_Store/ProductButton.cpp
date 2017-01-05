#include "ProductButton.h"
#include <string>
#include <typeinfo>
using namespace std;
/*!
Constructor function for the ProductButton class.
*/
ProductButton::ProductButton()
{
}
/*!
Destructor function for the ProductButton class.
*/
ProductButton::~ProductButton()
{
}
/*!
	The function for adding a product to the system.
*/
void ProductButton::Add(list<Product*>& products)
{
	int choice; 
	string _prdname;
	double _prdprice;
	cout << "Product Type Menu\n----------\n";
	cout << "1. Book" << endl;
	cout << "2. Magazine " << endl;
	cout << "3. Music CD" << endl;
	cout << "Choose a product type for the product you have entered: " << endl;
	cin >> choice;
	if (choice == 1)
	{	
		
		string _author, _publisher;
		int _page;
		cin.ignore();
		while (true) {
			cout << "Enter Product name: ";

			getline(cin, _prdname);
			if (!_prdname.empty())
				break;
			cout << "You have to enter a product name." << endl;
		}

		cout << "Enter Product price: ";
		cin >> _prdprice;
		cin.ignore();
		while (true) {
			cout << "Enter the Book's Author:";
			getline(cin, _author);
			if (!_author.empty())
				break;
			cout << "Enter the name of author of the book." << endl;
		}
		while (true) {
			cout << "Enter the Book's Publisher:";
			getline(cin, _publisher);
			if (!_publisher.empty())
				break;
			cout << "Enter the name of publisher of the book." << endl;
		}
		cout << "Enter the Book's Page number:";
		cin >> _page;

		Product* product_book = new Book(_prdname, _prdprice,_author,_publisher,_page);
		products.push_back(product_book);
	}
	else if (choice == 2)
	{
		int _Issue;
		string _type;
		cin.ignore();
		while (true) {
			cout << "Enter Product name: ";
			getline(cin, _prdname);
			if (!_prdname.empty())
				break;
			cout << "You have to enter a product name." << endl;
		}

		cout << "Enter Product price: ";
		cin >> _prdprice;

		cout << "Enter the Magazine's Issue:";
		cin >> _Issue;

		cin.ignore();
		while (true) {
			cout << "Enter the Magazine's Type:";
			getline(cin, _type);
			if (!_type.empty())
				break;
			cout << "Enter type of the magazine." << endl;
		}

		Product* product_magazine = new Magazine(_prdname, _prdprice, _Issue, _type);
		products.push_back(product_magazine);
	}
	else if (choice == 3)
	{
		string _singer, _type;
		cin.ignore();
		while (true) {
			cout << "Enter Product name: ";

			getline(cin, _prdname);
			if (!_prdname.empty())
				break;
			cout << "You have to enter a product name." << endl;
		}


		cout << "Enter Product price: ";
		cin >> _prdprice;

		cin.ignore();
		while (true) {
			cout << "Enter the Music Cd's Singer:";
			getline(cin, _singer);
			if (!_singer.empty())
				break;
			cout << "Enter a singer name." << endl;
		}
		while (true) {
			cout << "Enter the Music Cd's Type:";
			getline(cin, _type);
			if (!_type.empty()) {
				break;
			}
			cout << "Enter a music type." << endl;
		}
		Product * product_musiccd = new MusicCD(_prdname, _prdprice, _singer, _type);
		products.push_back(product_musiccd);
	}

}
/*!
The function for showing the products in the system.
*/
void ProductButton::Show(list<Product*>& products) const
{
	cout << "+-------------------------------------------------------------------------------------------------------+" << endl;
	cout << "|  ID  |       Name       |   Price   |  Author/Singer  |  Publisher  |  Page  |  Issue  |     Type     |" << endl;
	cout << "+-------------------------------------------------------------------------------------------------------+" << endl;
	auto iterator = products.begin();
	for (int i = 0; i < products.size(); i++)
	{
		(*iterator)->printProperties();
		iterator = next(products.begin(), (i + 1));
	}
	cout << "+-------------------------------------------------------------------------------------------------------+" << endl;
}
