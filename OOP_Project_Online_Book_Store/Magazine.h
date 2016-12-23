#pragma once
#include <iostream>
#include <string>
#include "Product.h"
using namespace std;
/**
* @file Magazine.h
* @Author Mahmut Bilgehan Serbest (bilgehanserbest@gmail.com)
* @date December, 2016
* @brief Class for creating "Magazine"s
*
* @details This class invloves functions and variables for "Magazine"s
*/
class Magazine :public Product {
	int Issue; /*! Issue of the magazine*/
	string type; /*! Type of the magazine*/
public:
	//! Prints the information of the magazine to screen.
	void printProperties()const;
	//! Gets Issue of the magazine.
	int getIssue() const;
	//! Sets Issue of the magazine.
	void setIssue(int Issue);
	//! Gets Type of the magazine.	
	string getType() const;
	//! Sets Type of the magazine.
	void setType(const string& type);
};