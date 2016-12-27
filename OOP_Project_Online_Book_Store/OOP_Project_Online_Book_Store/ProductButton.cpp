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
		Book* product_book = new Book();
		string _author, _publisher;
		int _page;

		cout << "Enter Product name: ";
		cin.ignore();
		getline(cin, _prdname);
		product_book->setName(_prdname);
		cout << "Enter Product price: ";
		cin >> _prdprice;
		product_book->setPrice(_prdprice);
		cout << "Enter the Book's Author:";
		cin.ignore();
		getline(cin, _author);
		product_book->setAuthor(_author);
		cout << "Enter the Book's Publisher:";
		cin.ignore();
		getline(cin, _publisher);
		product_book->setPublisher(_publisher);
		cout << "Enter the Book's Page number:";
		cin >> _page;
		product_book->setPage(_page);
		products.push_back(product_book);
	}
	else if (choice == 2)
	{
		int _Issue;
		string _type;
		Magazine* product_magazine = new Magazine();
		cout << "Enter Product name: ";
		cin.ignore();
		getline(cin, _prdname);
		product_magazine->setName(_prdname);
		cout << "Enter Product price: ";
		cin >> _prdprice;
		product_magazine->setPrice(_prdprice);
		cout << "Enter the Magazine's Issue:";
		cin >> _Issue;
		product_magazine->setIssue(_Issue);
		cout << "Enter the Magazine's Type:";
		cin.ignore();
		getline(cin, _type);
		product_magazine->setType(_type);
		products.push_back(product_magazine);
	}
	else if (choice == 3)
	{
		string _singer, _type;
		MusicCD * product_musiccd = new MusicCD();
		cout << "Enter Product name: ";
		cin.ignore();
		getline(cin, _prdname);
		product_musiccd->setName(_prdname);
		cout << "Enter Product price: ";
		cin >> _prdprice;
		product_musiccd->setPrice(_prdprice);
		cout << "Enter the Music Cd's Singer:";
		cin >> _singer;
		product_musiccd->setSinger(_singer);
		cout << "Enter the Music Cd's Type:";
		cin.ignore();
		getline(cin, _type);
		product_musiccd->setType(_type);
		products.push_back(product_musiccd);
	}

}

void ProductButton::Show(list<Product*>& products) const
{
	cout << "Products\n-------------\n";
	auto iterator = products.begin();
	for (int i = 0; i < products.size(); i++)
	{
		cout << (i+1) << ". Product:\n";
		(*iterator)->printProperties();

		if ((*iterator)->getproduct() == "Book")
		{
			cout << "Product(Book)'s Author: " << static_cast<Book*>(*iterator)->getAuthor()<<endl;
			cout << "Product(Book)'s Publisher: " << static_cast<Book*>(*iterator)->getPublisher()<<endl;
			cout << "Product(Book)'s Page Number: " << static_cast<Book*>(*iterator)->getPage() << endl;
		}
		else if((*iterator)->getproduct() == "Magazine")
		{
			cout << "Product(Magazine)'s Issue: " << static_cast<Magazine*>(*iterator)->getIssue()<< endl;
			cout << "Product(Magazine)'s Type: " << static_cast<Magazine*>(*iterator)->getType() << endl;
		}
		else if ((*iterator)->getproduct() == "MusicCD")
		{
			cout << "Product(Music CD)'s Singer: " << static_cast<MusicCD*>(*iterator)->getSinger()<< endl;
			cout << "Product(Music CD)'s Type: " << static_cast<MusicCD*>(*iterator)->getType() << endl;
		}

		iterator = next(products.begin(), (i+1));
	}
}
