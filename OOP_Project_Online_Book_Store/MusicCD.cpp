#include "MusicCD.h"

void MusicCD::printProperties() const
{
	cout << "The Singer is: " << singer << endl;
	cout << "The Type is: " << type << endl;
}

string MusicCD::getSinger() const
{
	return singer;
}

void MusicCD::setSinger(const string& Singer)
{
	this->singer = singer;
}

string MusicCD::getType() const
{
	return type;
}

void MusicCD::setType(const string& type)
{
	this->type = type;
}
