#pragma once
#include <iostream>
#include <string>
using namespace std;
class Address
{
	int hNo, sNo;
	string colony, city;
public:
	Address();
	Address(int, int, string, string);
	Address(Address& a);
	~Address();

	int getHNo() const;
	int getSNo() const;
	string getColony() const;
	string getCity() const;
	void setHNo(int);
	void setSNo(int);
	void setColony(string);
	void setCity(string);

	void setAddress(int hNo, int sNo, string colony, string city);
	string getAddress() const;
	string getDetail();
};

