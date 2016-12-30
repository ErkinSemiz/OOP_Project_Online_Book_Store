#pragma once
#include <iostream>
#include <string>
#include "Product.h"
using namespace std;
/**
* @file MusicCD.h
* @Author Mahmut Bilgehan Serbest (bilgehanserbest@gmail.com)
* @date December, 2016
* @brief Class for creating "MusicCD"s
*
* @details This class invloves functions and variables for "MusicCD"s
*/
class MusicCD :public Product {
	string singer; /*! Name of the singer of the MusicCd */
	string type; /*! Type of the MusicCd */
public:
	//! Default constructor function
	MusicCD(string name, double price, string singer, string type);

	//! Prints the information of the MusicCd to the screen.
	void printProperties()const;
	//! Gets the name of the singer.
	string getSinger() const;
	//! Sets the name of the singer.
	void setSinger(const string& Singer);
	//! Gets the type of the MusicCd.
	string getType() const;
	//! Sets the type of the MusicCd.
	void setType(const string& type);
	string getproduct() const;
};