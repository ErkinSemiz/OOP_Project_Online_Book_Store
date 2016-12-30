#include <iostream>
#include <list>
#include "Customer.h"
#include "ShoppingCart.h"
#include "Product.h"
#include "CustomerButton.h"
#include "ProductButton.h"
#include "ShoppingButton.h"
#include "ShoppingCart.h"

list<Customer> customers;
list<Product*> products;

int main() {
	CustomerButton customerButton;
	ProductButton productButton;
	
	ShoppingCart shopping_cart;
	ShoppingButton shoppingButton(&shopping_cart);

	Customer *customer = new Customer("bilgehan", "buyukdere", "123456789", "bilg@esk.com", "bilgehan", "123");
	customers.push_back(*customer);
	customer = new Customer("erkin", "hastane", "123456789", "erk@esk.com", "erkin", "123");
	customers.push_back(*customer);
	customer = new Customer("tahir", "kutahya", "123456789", "tah@esk.com", "tahir", "123");
	customers.push_back(*customer);

	Product* product = new Magazine("oyungezer", 12, 66, "game");
	products.push_back(product);
	product = new Book("Tutunamayanlar", 30, "Oguz Atay", "Iletisim", 724);
	products.push_back(product);
	product = new MusicCD("Best of MFO", 24, "MFO", "Pop, Rock");
	products.push_back(product);
	product = new Book("aa", 10, "Oguz Atay", "Iletisim", 724);
	products.push_back(product);
	product = new Magazine("bb", 5, 34, "TV");
	products.push_back(product);
	
	bool loggedIn = false;
	while (true) {
		cout << "Menu\n----\n";
		cout << "1. Customer" << endl;
		cout << "2. Product" << endl;
		cout << "3. Shopping" << endl;
		cout << "4. Quit" << endl;
		cout << "Choose one: ";
		int choice;
		cin >> choice;
		system("cls");
		if (choice == 1) {
			cout << "Customer Menu\n----------\n";
			cout << "1. Add a new customer to system" << endl;
			cout << "2. Show customers in system" << endl;
			cout << "3. Back" << endl;
			cout << "Choose one: ";
			cin >> choice;
			if (choice == 1) {
				customerButton.Add(customers);
			}
			else if (choice == 2) {
				customerButton.Show(customers);
				//system("pause");
			}
			//system("cls");
		}
		else if (choice == 2) {
			cout << "Product Menu\n----------\n";
			cout << "1. Add a new product to system" << endl;
			cout << "2. Show products in system" << endl;
			cout << "3. Back" << endl;
			cout << "Choose one: ";
			cin >> choice;
			if (choice == 1) {
				productButton.Add(products);
			}
			else if (choice == 2) {
				productButton.Show(products);
				//system("pause");
			}
			//system("cls");
		}

		else if (choice == 3) {
			cout << "Shopping Menu\n----------\n";
			cout << "1. Login" << endl;
			cout << "2. Add Product" << endl;
			cout << "3. Remove Product" << endl;
			cout << "4. List All Products" << endl;
			cout << "5. List Shopping Cart" << endl;
			cout << "6. Show Bonus" << endl;
			cout << "7. Use Bonus" << endl;
			cout << "8. Place Order" << endl;
			cout << "9. Cancel Order" << endl;
			cout << "10. Show Invoice" << endl;
			cout << "11. Quit" << endl;
			cout << "Choose one: ";
			cin >> choice;
			system("cls");
			if (choice == 1) {
				if (shoppingButton.Login(customers) == true)
				{
					loggedIn = true;
					cout << "Success! " << endl;
				}
				else
				{
					loggedIn = false;
					cout << "Invalid Username or Password!" << endl;
				}
			}
			else if (!loggedIn) {
				cout << "\nPlease log in to system first." << endl;
				cout << "Do you want to log in now?" << endl;
				cout << "1. Yes\n2. No\n";
				cout << "Choose one: ";
				int subChoice;
				cin >> subChoice;

				if (subChoice == 1) {
					if (shoppingButton.Login(customers) == true)
					{
						loggedIn = true;
						cout << "Success! " << endl;
					}
					else {
						loggedIn = false;
						cout << "Invalid Username or Password!" << endl;
					}

				}
			}
			else if (choice == 2) {
				shoppingButton.AddProduct(products);
			}
			else if (choice == 3) {
				shoppingButton.RemoveProduct(products);
			}
			else if (choice == 4) {
				productButton.Show(products);
			}
			else if (choice == 5) {
				shoppingButton.ListShoppingCart(products);
			}
			else if (choice == 6) {
				cout << shopping_cart.getCustomer()->getName() << "' s Bonus: " << shopping_cart.getCustomer()->getBonus() << endl;
				
				//shoppingButton.ShowBonus();
			}
			else if (choice == 7) {
				shopping_cart.getCustomer()->useBonus();
				//TO DO
			}
			else if (choice == 8) {
				shoppingButton.PlaceOrder();
			}
			else if (choice == 9) {
				shoppingButton.CancelOrder();
			}
			else if (choice == 10) {
				shoppingButton.ShowInvoice();
			}
			else if (choice == 11)
			{
				system("pause");
			}
		}//Shopping Menu
//cout << "Press any key to return the menu...";
//if (getchar())
//{
//	system("cls");
//}
		system("pause");
		system("cls");
	}//main while
}//main