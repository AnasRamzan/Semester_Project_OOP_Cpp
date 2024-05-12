#include "Address.h"



Address::Address()
{
	hNo = 0;
	sNo = 0;
	colony = "";
	city = "";
}
Address::Address(int hNo, int sNo, string colony, string city)
{
	this->hNo = hNo;
	this->sNo = sNo;
	this->colony = colony;
	this->city = city;
}
Address::Address(Address& a)
{
	this->hNo = a.hNo;
	this->sNo = a.sNo;
	this->colony = a.colony;
	this->city = a.city;
}

Address::~Address()
{
}

int Address::getHNo() const
{
	return hNo;
}
int Address::getSNo() const
{
	return sNo;
}
string Address::getColony() const
{
	return colony;
}
string Address::getCity() const
{
	return city;
}
void Address::setHNo(int hNo)
{
	this->hNo = hNo;
}
void Address::setSNo(int sNo)
{
	this->sNo = sNo;
}
void Address::setColony(string colony)
{
	this->colony = colony;
}
void Address::setCity(string city)
{
	this->city = city;
}
void Address::setAddress(int hNo, int sNo, string colony, string city)
{
	this->hNo = hNo;
	this->sNo = sNo;
	this->colony = colony;
	this->city = city;
}
string Address::getAddress() const
{
	return "House #: " + to_string(hNo) + ", Street #: " + to_string(sNo) + ", Colony: " + colony + ", City: " + city;
}
string Address::getDetail()
{
	return to_string(hNo) + "\t" + to_string(sNo) + "\t" + colony + "\t" + city;
}
