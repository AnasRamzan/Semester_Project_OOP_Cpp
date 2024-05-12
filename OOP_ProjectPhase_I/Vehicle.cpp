#include "Vehicle.h"



Vehicle::Vehicle()
{
	Vid = 0;
	company = "";
	model = "";
	year = new int[2];
	year[0] = 0;
	year[1] = 0;
	price = 0;
}

Vehicle::Vehicle(int id, string company, string model, int preYear, int currentYear, int price)
{
	this->Vid = id;
	this->company = company;
	this->model = model;
	year = new int[2];
	year[0] = preYear;
	year[1] = currentYear;
	this->price = price;
}

Vehicle::Vehicle(const Vehicle & v)
{
	this->Vid = v.Vid;
	this->company = v.company;
	this->model = v.model;
	year = new int[2];
	year[0] = v.year[0];
	year[1] = v.year[1];
	this->price = v.price;
}
Vehicle::~Vehicle()
{
	delete[] year;
}

int Vehicle::getVId() const
{
	return Vid;
}
string Vehicle::getCompany() const
{
	return company;
}
string Vehicle::getModel() const
{
	return model;
}
int Vehicle::getPrice() const
{
	return price;
}
int Vehicle::getPreviousYear() const
{
	return year[0];
}
int Vehicle::getCurrentYear()const
{
	return year[1];
}
void Vehicle::setVId(const int id)
{
	this->Vid = id;
}

void Vehicle::setCompany(const string company)
{
	this->company = company;
}
void Vehicle::setModel(const string model)
{
	this->model = model;
}
void Vehicle::setPrice(const int price)
{
	this->price = price;
}

void Vehicle::setPreviousYear(const int y)
{
	year[0] = y;
}
void Vehicle::setCurrentYear(const int y)
{
	year[1] = y;
}
string Vehicle::getType() const
{
	return"";
}
string Vehicle::getWheelDrive() const
{
	return"";
}
void Vehicle::setType(string)
{

}
void Vehicle::setWheelDrive(string)
{

}


string Vehicle::getDetail()
{
	return to_string(Vid) + "\t" + company + "\t" + model + "\t" + to_string(year[0]) + "\t" + to_string(year[1]) + "\t" + to_string(price) ;
}
string Vehicle::getVehicle() const
{
	return "ID: " + to_string(Vid) + ", Company: " + company + ", Model: " + model + ", Previous Model Year: " + to_string(year[0]) + ", Latest Model Year: " + to_string(year[1]) + ", Price: " + to_string(price);
}
void Vehicle::setVehicle(int id, string company, string model, int preYear, int currentYear, int price, string wheelDrive, string type)
{
	this->Vid = id;
	this->company = company;
	this->model = model;
	this->year[0] = preYear;
	this->year[1] = currentYear;
	this->price = price;
}


