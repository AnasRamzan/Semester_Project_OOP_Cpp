#pragma once
#include "Vehicle.h"
class Car :
	public Vehicle
{
	static int carCount;
	string wheelDrive;

	static int alreadyExist(Car c[], int, int);

public:
	Car();
	Car(int, string, string, int, int, int, string);
	Car(const Car &);
	~Car();

	static int getCarCount();
	string getVehicle() const;
	static void setCarCount();
	virtual string getWheelDrive() const;
	virtual void setWheelDrive(const string);


	void setVehicle(int, string, string, int, int, int, string, string);


	virtual void objToFile();//called in add()
	static int recCount();
	static void readFile(Car c[], int);
	static void arrayToFile(Car c[], int);

	virtual string getDetail();

	static void add();
	static void view(Car c[], int);
	static int search(Car c[], int);
	static void update(Car c[], int);
	static void Delete(Car c[], int);

	friend ostream& operator << (ostream& out, const Car& c);
	friend istream& operator >> (istream& in, Car& c);

};


