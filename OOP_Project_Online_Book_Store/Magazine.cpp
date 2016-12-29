#include "Magazine.h"
/*!
Properties of the Magazine object will be printed
*/
void Magazine::printProperties() const
{
	cout << "The Magazine's Issue is: " << Issue << endl;
	cout << "The Magazine's Type is: " << type << endl;
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

string Magazine::getproduct() const
{
	return "Magazine";
}
