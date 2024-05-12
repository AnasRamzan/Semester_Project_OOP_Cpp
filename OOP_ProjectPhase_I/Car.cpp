#include "Car.h"


int Car::carCount = 0;
Car::Car() :Vehicle()
{
	wheelDrive = "";
}
Car::Car(int id, string company, string model,int preYear, int currentYear, int price, string drive):Vehicle(id, company, model, preYear, currentYear, price), wheelDrive(drive)
{
	wheelDrive = drive;
}
Car::Car(const Car& c):Vehicle(c)
{
	wheelDrive = c.wheelDrive;
}
Car::~Car()
{
}

int Car::getCarCount()
{
	return carCount;
}
string  Car::getVehicle() const
{
	return Vehicle::getVehicle() + ", Wheel Drive: " + wheelDrive;
}

void Car::setCarCount() {
	carCount = Car::recCount();
}
string Car::getWheelDrive() const
{
	return wheelDrive;
}
void Car::setWheelDrive(const string drive)
{
	this->wheelDrive = drive;
}


void Car::setVehicle(int id, string company, string model, int preYear, int currentYear, int price, string wheelDrive, string type)
{
	Vehicle::setVehicle(id, company, model, preYear, currentYear, price, wheelDrive, type);
	this->wheelDrive = wheelDrive;
}

int Car::alreadyExist(Car c[], int size, int searchId)
{
	for (int i = 0; i < size; i++)
	{
		if (c[i].Vid == searchId)
		{
			return i;
		}
	}
	return -1;

}

void Car::objToFile() {
	ofstream fout;
	fout.open("cars.txt", ios::app);
	fout << getDetail() << endl;
	fout.close();
}

int Car::recCount()
{
	ifstream fin;
	fin.open("cars.txt");
	try {
		if (fin.fail())
		{
			throw runtime_error("File cannot be opened!\n");
		}
	}
	catch (runtime_error & e)
	{
		cout << "Error " << e.what();
	}
	string line;
	int count = 0;
	while (getline(fin, line))
	{
		count++;
	}
	fin.close();
	return count;
}

void Car::readFile(Car c[], int size)
{
	ifstream fin;
	fin.open("cars.txt");
	try {
		if (fin.fail())
		{
			throw runtime_error("File cannot be opened!\n");
		}
	}
	catch (runtime_error & e)
	{
		cout << "Error " << e.what();
	}
	for (int i = 0; i < size; i++)
	{
		fin >> c[i].Vid >> c[i].company >> c[i].model >> c[i].year[0] >> c[i].year[1] >> c[i].price >> c[i].wheelDrive;
	}
	fin.close();
}

void Car::arrayToFile(Car c[], int size)
{
	ofstream fout;
	fout.open("cars.txt");
	for (int i = 0; i < size; i++)
	{
		if (c[i].Vid != 0)

		{
			fout << c[i].getDetail() << endl;
		}
	}
	fout.close();
}


string Car::getDetail()
{
	return Vehicle::getDetail() + "\t" + wheelDrive;
}

void Car::add()
{
	Car c;
	cin >> c;
	c.objToFile();
	cout << "Record Successfully Entered\n";
}


void Car::view(Car c[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << c[i] << endl;
		cout << "____________________________________________________________\n";
	}
	cout << endl;
}

int Car::search(Car c[], int size)
{
	cout << "Enter the ID: ";
	int searchId;
	cin >> searchId;
	return Car::alreadyExist(c, size, searchId);
}

void Car::update(Car c[], int size)
{
	int target = Car::search(c, size);
	if (target != -1)
	{
		cout << c[target] << endl;
		cout << "Enter the new price: ";
		cin >> c[target].price;
		Car::arrayToFile(c, size);
		cout << "Price updated\n";
	}
	else 
	{
		cout << "This id does not exist\n";
	}
}

void Car::Delete(Car c[], int size)
{
	int target = Car::search(c, size);
	if (target != -1)
	{
		c[target].Vid = 0;
		c[target].company = "";
		c[target].model = "";
		c[target].year[0] = 0;
		c[target].year[1] = 0;
		c[target].price = 0;
		c[target].wheelDrive = "";
		Car::arrayToFile(c, size);
		cout << "Record deleted successfully\n";
	}
	else
	{
		cout << "This id does not exist\n";
	}
}

ostream& operator << (ostream& out, const Car& c)
{
	out << "ID: " << c.Vid << ", Company: " << c.company << ", Model: " << c.model << ", Previous Model Year: " << c.year[0] << ", Latest Model Year: " << c.year[1] << ", Price: " << c.price << ", Wheel Drive: " << c.wheelDrive;
	return out;
}

istream& operator >> (istream& in, Car& c)
{
	cout << "Enter ID: ";
	in >> c.Vid;
	cout << "Enter Company Name: ";
	in >> c.company;
	cout << "Enter Model Name: ";
	in >> c.model;
	cout << "Enter Previous Model Year: ";
	in >> c.year[0];
	cout << "Enter Latest Model Year: ";
	in >> c.year[1];
	cout << "Enter Price: ";
	in >> c.price;
	cout << "Enter Wheel Drive(FWD/RWD/4WD): ";
	in >> c.wheelDrive;
	return in;
}

