#pragma once
#include <iostream>
#include "Customer.h"
#include <list>
class CustomerButton
{
public:
	CustomerButton();
	~CustomerButton();
	void Add(list<Customer>& customers);
	void Show(list<Customer>& customers) const;
};

