#pragma once
#include <iostream>
#include "Customer.h"
#include <list>
/**
* @file CustomerButton.h
* @Author Tahir Özdemir (tahirozdemir34@gmail.com)
* @date December, 2016
* @brief Class for creating "CustomerButton"s to be used in the main menu.
*
* @details This class involves functions and variables for "CustomerButton"s
*/
class CustomerButton
{
public:
	//! Constructor function for CustomerButton class.
	CustomerButton();
	//! Destructor function for CustomerButton class.
	~CustomerButton();
	//! The submenu for adding a customer to the system.
	void Add(list<Customer>& customers);
	//! The submenu for showing the customers in the system.
	void Show(list<Customer>& customers) const;
};