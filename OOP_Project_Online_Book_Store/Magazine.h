#pragma once
#include <iostream>
#include <string>
#include "Product.h"
using namespace std;
class Magazine :public Product {
	int Issue;
	string type;
public:
	void printProperties()const;
	int getIssue() const;
	void setIssue(int Issue);
	string getType() const;
	void setType(const string& type);
};