#include <iostream>
#include <list>
#include "Customer.h"
#include "ShoppingCart.h"
#include "Product.h"
#include "CustomerButton.h"
#include "ProductButton.h"

list<Customer> customers;
list<Product*> products;

int main() {
	CustomerButton customerButton;
	ProductButton productButton;
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
				system("pause");
			}
			system("cls");
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
				system("pause");
			}
			system("cls");
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
			cout << "9. Canscel Order" << endl;
			cout << "10. Show Invoice" << endl;
			cout << "11. Quit" << endl;
			cout << "Choose one: ";
			cin >> choice;
			if (choice == 1) {
				//TO DO
			}
			else if (!loggedIn) {
				cout << "\nPlease log in to system first." << endl;
				cout << "Do you want to log in now?" << endl;
				cout << "1. Yes\n2. No\n";
				cout << "Choose one: ";
				int subChoice;
				cin >> subChoice;

				if (subChoice == 1) {
					//TO DO call login method of ShoppingButton

				}
			}
			else if (choice == 2) {
				//TO DO
			}
			else if (choice == 3) {
				//TO DO
			}
			else if (choice == 4) {
				//TO DO
			}
			else if (choice == 5) {
				//TO DO
			}
			else if (choice == 6) {
				//TO DO
			}
			else if (choice == 7) {
				//TO DO
			}
			else if (choice == 8) {
				//TO DO
			}
			else if (choice == 9) {
				//TO DO
			}
			else if (choice == 10) {
				//TO DO
			}


			system("cls");
		}//Shopping Menu
	}//main while
}//main