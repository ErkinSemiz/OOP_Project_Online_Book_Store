#include "MusicCD.h"
MusicCD::MusicCD(string name, double price, string singer, string type) :Product(name, price), singer(singer), type(type)
{
}
/*!
Properties of the MusicCD object will be printed
*/
void MusicCD::printProperties() const
{

	cout << "|   " << getID() << "  | " << setw(17) << left << getName() << "|   " << setw(8) << getPrice()
	 << "|  " << setw(15) << singer << "|      -      |    -   |    -    |  " <<setw(12) <<type << "|"<< endl;
}
/*! \return The singer of the MusicCD */
string MusicCD::getSinger() const
{
	return singer;
}
/*!
\param Singer "Singer" variable of MusicCD will be set
*/
void MusicCD::setSinger(const string& Singer)
{
	this->singer = singer;
}
/*! \return The type  of the MusicCD */
string MusicCD::getType() const
{
	return type;
}
/*!
\param type "type" variable of MusicCD will be set
*/
void MusicCD::setType(const string& type)
{
	this->type = type;
}

