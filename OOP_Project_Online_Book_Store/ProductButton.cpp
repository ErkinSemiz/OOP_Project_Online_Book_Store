#include "ProductButton.h"
#include <string>
#include <typeinfo>
using namespace std;
ProductButton::ProductButton()
{
}

ProductButton::~ProductButton()
{
}

void ProductButton::Add(list<Product*>& products)
{
	int _prdID,choice; 
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
		cout << "Enter Product name: ";
		cin.ignore();
		getline(cin, _prdname);
		//product_book->setName(_prdname);
		cout << "Enter Product price: ";
		cin >> _prdprice;
		//product_book->setPrice(_prdprice);
		cout << "Enter the Book's Author:";
		cin.ignore();
		getline(cin, _author);
		//product_book->setAuthor(_author);
		cout << "Enter the Book's Publisher:";
		cin.ignore();
		getline(cin, _publisher);
		//product_book->setPublisher(_publisher);
		cout << "Enter the Book's Page number:";
		cin >> _page;
		//product_book->setPage(_page);

		Product* product_book = new Book(_prdname, _prdprice,_author,_publisher,_page);
		products.push_back(product_book);
	}
	else if (choice == 2)
	{
		int _Issue;
		string _type;

		cout << "Enter Product name: ";
		cin.ignore();
		getline(cin, _prdname);
		//product_magazine->setName(_prdname);
		cout << "Enter Product price: ";
		cin >> _prdprice;
		//product_magazine->setPrice(_prdprice);
		cout << "Enter the Magazine's Issue:";
		cin >> _Issue;
		//product_magazine->setIssue(_Issue);
		cout << "Enter the Magazine's Type:";
		cin.ignore();
		getline(cin, _type);
		//product_magazine->setType(_type);
		Product* product_magazine = new Magazine(_prdname, _prdprice, _Issue, _type);
		products.push_back(product_magazine);
	}
	else if (choice == 3)
	{
		string _singer, _type;
		
		cout << "Enter Product name: ";
		cin.ignore();
		getline(cin, _prdname);
		//product_musiccd->setName(_prdname);
		cout << "Enter Product price: ";
		cin >> _prdprice;
		//product_musiccd->setPrice(_prdprice);
		cout << "Enter the Music Cd's Singer:";
		cin >> _singer;
		//product_musiccd->setSinger(_singer);
		cout << "Enter the Music Cd's Type:";
		cin.ignore();
		getline(cin, _type);
		//product_musiccd->setType(_type);

		Product * product_musiccd = new MusicCD(_prdname, _prdprice, _singer, _type);
		products.push_back(product_musiccd);
	}

}

void ProductButton::Show(list<Product*>& products) const
{
	cout << "Products\n-------------\n";
	auto iterator = products.begin();
	for (int i = 0; i < products.size(); i++)
	{
		cout << (i + 1) << ". Product:\n";
		(*iterator)->printProperties();
		iterator = next(products.begin(), (i + 1));
	}
	
}
