#pragma once
#include <iostream>
#include <string>
#include "Product.h"
using namespace std;
class MusicCD :public Product {
	string singer;
	string type;
public:
	void printProperties()const;
	string getSinger() const;
	void setSinger(const string& Singer);
	string getType() const;
	void setType(const string& type);
};