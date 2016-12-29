#pragma once
#include <iostream>
#include "Product.h"
#include "Book.h"
#include "Magazine.h"
#include "MusicCD.h"
#include <list>
class ProductButton {
public:
	ProductButton();
	~ProductButton();
	void Add(list<Product*>& products);
	void Show(list<Product*>& products) const;
};
