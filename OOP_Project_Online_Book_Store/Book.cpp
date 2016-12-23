#include "Book.h"

void Book::printProperties() const
{
	cout << "The Book's Author is: " << author << endl;
	cout << "The Book's Publisher is: " << publisher << endl;
	cout << "The Book's Page is: " << page << endl;
}

string Book::getAuthor() const
{
	return author;
}

void Book::setAuthor(const string& author)
{
	this->author = author;
}

string Book::getPublisher() const
{
	return publisher;
}

void Book::setPublisher(const string& publisher)
{
	this->publisher = publisher;
}

int Book::getPage() const
{
	return page;
}

void Book::setPage(int page)
{
	this->page = page;
}
