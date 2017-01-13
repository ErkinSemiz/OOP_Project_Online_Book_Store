#include "Book.h"
/*!
Constructor function for the Book class.
\param name Name of the book.
\param author Author of the book.
\param publisher Publisher of the book.
\param page Page count of the book.
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
	cout << "|   " << getID() << "  | " << setw(17) << left << getName() << "|   " << setw(8) << getPrice()
	 << "|  "<<setw(15) << author << "|  "<< setw(11) <<publisher << "|  "<<setw(6) << page <<"|    -    |       -      | " << endl;

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
\param publisher "publisher" variable of Book will be set
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