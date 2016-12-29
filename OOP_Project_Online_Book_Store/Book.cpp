#include "Book.h"

/*!
Properties of the Book object will be printed
*/
Book::Book()
{
}
Book::~Book()
{
}
void Book::printProperties() const
{
	Product::printProperties();
	cout << "The Book's Author is: " << author << endl;
	cout << "The Book's Publisher is: " << publisher << endl;
	cout << "The Book's Page is: " << page << endl;
}
/*! \return The author of the book */
string Book::getAuthor() const
{
	return author;
}
/*!
\param author "author" variable of Book will be set
*/
void Book::setAuthor(const string& author)
{
	this->author = author;
}
/*! \return The publisher of the book */
string Book::getPublisher() const
{
	return publisher;
}
/*!
\param Issue "publisher" variable of Book will be set
*/
void Book::setPublisher(const string& publisher)
{
	this->publisher = publisher;
}
/*! \return The page of the book */
int Book::getPage() const
{
	return page;
}
/*!
\param page "page" variable of Book will be set
*/
void Book::setPage(int page)
{
	this->page = page;
}

string Book::getproduct() const
{
	return "Book";
}
