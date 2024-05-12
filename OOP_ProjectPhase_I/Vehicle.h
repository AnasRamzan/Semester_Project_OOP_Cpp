#pragma once
#include <iostream>
#include <fstream>
#include<string>
using namespace std;
class Vehicle
{
protected:
	int Vid;
	string company;
	string model;
	int* year;
	int price;


public:
	Vehicle();
	Vehicle(int, string, string, int, int, int);
	Vehicle(const Vehicle&);
	virtual ~Vehicle();

	int getVId() const;
	string getCompany() const;
	string getModel() const;
	int getPrice() const;
	int getPreviousYear() const;
	int getCurrentYear() const;
	void setVId(const int);
	void setCompany(const  string);
	void setModel(const string);
	void setPrice(const int);
	void setPreviousYear(const int);
	void setCurrentYear(const int);
	virtual string getType() const;
	virtual string getWheelDrive() const;
	virtual void setType(const string);
	virtual void setWheelDrive(const string);

	virtual void objToFile() = 0;

	virtual void setVehicle(int, string, string, int, int, int, string, string);
	virtual string getDetail();
	virtual string getVehicle() const;
};

