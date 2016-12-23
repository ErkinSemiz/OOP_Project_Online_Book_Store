#include "Magazine.h"

void Magazine::printProperties() const
{
	cout << "The Magazine's Issue is: " << Issue << endl;
	cout << "The Magazine's Type is: " << type << endl;
}

int Magazine::getIssue() const
{
	return Issue;
}

void Magazine::setIssue(int Issue)
{
	this->Issue = Issue;
}

string Magazine::getType() const
{
	return type;
}

void Magazine::setType(const string& type)
{
	this->type = type;
}
