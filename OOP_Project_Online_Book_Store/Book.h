#pragma once
#include "Product.h"
/**
* @file Book.h
* @Author Mahmut Bilgehan Serbest (bilgehanserbest@gmail.com)
* @date December, 2016
* @brief Class for creating "Book"s
*
* @details This class invloves functions and variables for "Book"s
*/
class Book :
	public Product
{
private:
	string author; /*!< Author of book */ 
	string publisher; /*!< Publisher of book */ 
	int page; /*!< Page count of book */ 
public:
	//! Default constructor function
	Book(string name, double price, string author, string publisher, int page);
	//! Default deconstructor function
	~Book();
	//! Print informations of book to screen.
	void printProperties() const;
	//! Get author name of book.
	string getAuthor() const;
	//! Set author name of book.
	void setAuthor(const string& author);
	//! Get publisher name of book product.
	string getPublisher() const;
	//! Set publisher name of book product.
	void setPublisher(const string& publisher);
	//! Get page count of book.
	int getPage()const;
	//! Set page count of book.
	void setPage(int page);
	string getproduct() const;
};

