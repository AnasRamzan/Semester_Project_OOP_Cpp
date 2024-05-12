#pragma once
#include "Vehicle.h"
class Bike :
	public Vehicle
{
	static int bikeCount;
	string type;

	static int alreadyExist(Bike b[], int, int);

public:
	Bike();
	Bike(int, string, string, int, int, int, string);
	Bike(const Bike&);
	~Bike();

	static int getBikeCount();
	string getVehicle() const;
	static void setBikeCount();
	void setVehicle(int, string, string, int, int, int, string, string);
	virtual string getType() const;
	virtual void setType(const string) ;


	virtual void objToFile();//called in add()
	static int recCount();
	static void readFile(Bike b[], int);
	static void arrayToFile(Bike b[], int);

	virtual string getDetail();

	static void add();
	static void view(Bike b[], int);
	static int search(Bike b[], int);
	static void update(Bike b[], int);
	static void Delete(Bike b[], int);

	friend ostream& operator << (ostream& out, const Bike& b);
	friend istream& operator >> (istream& in, Bike& b);

};

