#include "Magazine.h"
Magazine::Magazine(string name, double price, int issue, string type):Product(name, price), Issue(issue), type(type)
{
}
/*!
Properties of the Magazine object will be printed
*/
void Magazine::printProperties() const
{
	cout << "|   " << getID() << "  | " << setw(17) << left << getName() << "|   " << setw(8) << getPrice()
	 << "|        -        |      -      |    -   |   "<< setw(6)<< Issue << "|  "<< setw(12) << type << "|"<< endl;
}
/*! \return The Issue of the Magazine */
int Magazine::getIssue() const
{
	return Issue;
}
/*!
\param Issue "Issue" variable of Magazine will be set
*/
void Magazine::setIssue(int Issue)
{
	this->Issue = Issue;
}
/*! \return The type of the Magazine */
string Magazine::getType() const
{
	return type;
}
/*!
\param type "type" variable of Magazine will be set
*/
void Magazine::setType(const string& type)
{
	this->type = type;
}
