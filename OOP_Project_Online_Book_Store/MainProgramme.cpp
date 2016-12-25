#include <iostream>
#include <list>
#include "Customer.h"
#include "ShoppingCart.h"
#include "Product.h"
#include "CustomerButton.h"

list<Customer> customers;
list<Product*> products;

int main() {
	CustomerButton customerButton;

	cout << "Menu\n----\n";
	cout << "1. Customer" << endl;
	cout << "2. Item" << endl;
	cout << "3. Shopping" << endl;
	cout << "4. Quit" << endl;
	cout << "Choose one: ";
	int choice;
	cin >> choice;
	if (choice == 1) {
		cout << "Add a new customer to system" << endl;
		cout << "Show customers in system" << endl;
		cout << "Back" << endl;
		cin >> choice;
		if (choice == 1) {
			customerButton.Add(customers);
		}
	}
	

	system("pause");
}