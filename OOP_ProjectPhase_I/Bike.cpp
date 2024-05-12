#include "Bike.h"


int Bike::bikeCount = 0;
Bike::Bike()
{
	type = "";
}
Bike::Bike(int id, string company, string model, int preYear, int currentYear, int price, string type):Vehicle(id, company, model, preYear, currentYear, price)
{
	this->type = type;
}
Bike::Bike(const Bike& b):Vehicle(b)
{
	type = b.type;
}

Bike::~Bike()
{
}

int Bike::getBikeCount()
{
	return bikeCount;
}

string Bike::getType() const
{
	return type;
}
void Bike::setType(const string type)
{
	this->type = type;
}


string Bike::getVehicle() const
{
	return Vehicle::getVehicle() + ", Type: " + type;

}

void Bike::setBikeCount() {
	bikeCount = Bike::recCount();
}

void Bike::setVehicle(int id, string company, string model, int preYear, int currentYear, int price, string wheelDrive, string type)
{
	Vehicle::setVehicle(id, company, model, preYear, currentYear, price, wheelDrive, type);
	this->type = type;
}

int Bike::alreadyExist(Bike b[], int size, int searchId)
{
	for (int i = 0; i < size; i++)
	{
		if (b[i].Vid == searchId)
		{
			return i;
		}
	}
	return -1;

}

void Bike::objToFile() {
	ofstream fout;
	fout.open("bikes.txt", ios::app);
	fout << getDetail() << endl;
	fout.close();
}

int Bike::recCount()
{
	ifstream fin;
	fin.open("bikes.txt");
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

void Bike::readFile(Bike b[], int size)
{
	ifstream fin;
	fin.open("bikes.txt");
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
		fin >> b[i].Vid >> b[i].company >> b[i].model >> b[i].year[0] >> b[i].year[1] >> b[i].price >> b[i].type;
	}
	fin.close();
}

void Bike::arrayToFile(Bike b[], int size)
{
	ofstream fout;
	fout.open("bikes.txt");
	for (int i = 0; i < size; i++)
	{
		if (b[i].Vid != 0)
		{
			fout << b[i].getDetail() << endl;
		}
	}
	fout.close();
}

string Bike::getDetail()
{
	return Vehicle::getDetail() + "\t" + type;
}

void Bike::add()
{
	Bike b;
	cin >> b;
	b.objToFile();
	cout << "Record Successfully Entered\n";
}

void Bike::view(Bike b[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << b[i] << endl;
		cout << "____________________________________________________________\n";
	}
	cout << endl;
}

int Bike::search(Bike b[], int size)
{
	cout << "Enter the ID: ";
	int searchId;
	cin >> searchId;
	return Bike::alreadyExist(b, size, searchId);
}

void Bike::update(Bike b[], int size)
{
	int target = Bike::search(b, size);
	if (target != -1)
	{
		cout << b[target] << endl;
		cout << "Enter the new price: ";
		cin >> b[target].price;
		Bike::arrayToFile(b, size);
		cout << "Price updated\n";
	}
	else
	{
		cout << "This id does not exist\n";
	}
}

void Bike::Delete(Bike b[], int size)
{
	int target = Bike::search(b, size);
	if (target != -1)
	{
		b[target].Vid = 0;
		b[target].company = "";
		b[target].model = "";
		b[target].year[0] = 0;
		b[target].year[1] = 0;
		b[target].price = 0;
		b[target].type = "";
		Bike::arrayToFile(b, size);
		cout << "Record deleted successfully\n";
	}
	else
	{
		cout << "This id does not exist\n";
	}
}

ostream& operator << (ostream& out, const Bike& b)
{
	out << "ID: " << b.Vid << ", Company: " << b.company << ", Model: " << b.model << ", Previous Model Year: " << b.year[0] << ", Latest Model Year: " << b.year[1] << ", Price: " << b.price << ", Type: " << b.type;
	return out;
}

istream& operator >> (istream& in, Bike& b)
{
	cout << "Enter ID: ";
	in >> b.Vid;
	cout << "Enter Company Name: ";
	in >> b.company;
	cout << "Enter Model Name: ";
	in >> b.model;
	cout << "Enter Previous Model Year: ";
	in >> b.year[0];
	cout << "Enter Latest Model Year: ";
	in >> b.year[1];
	cout << "Enter Price: ";
	in >> b.price;
	cout << "Enter Type(Quad_Wheeler/Bi_Wheeler/Tri_Wheeler): ";
	in >> b.type;
	return in;
}