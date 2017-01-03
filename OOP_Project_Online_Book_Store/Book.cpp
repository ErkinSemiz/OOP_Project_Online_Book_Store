#include "Book.h"
/*!
Constructor function for the Book class.
*/
Book::Book(string name, double price, string author, string publisher, int page):Product(name,price), author(author), publisher(publisher), page(page)
{
}
/*!
Destructor function for the Book class.
*/
Book::~Book()
{
}

/*!
Properties of the Book object will be printed
*/
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
/*! \return The page number of the book */
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
/*! \return The name of class. */
string Book::getproduct() const
{
	return "Book";
}
