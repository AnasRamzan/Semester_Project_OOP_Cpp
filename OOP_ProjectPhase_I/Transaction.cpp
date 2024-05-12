#include "Transaction.h"


int Transaction::transactionCount = 0;

Transaction::Transaction()
{
	tid = 0;
	buyer = Customer();
	carOrBike = ' ';
	automobile = nullptr;
	Tdate = Date();
	category = "";
}
Transaction::Transaction(int tId, int cId, string cName, string cContact, int cHNo, int cSNo, string cColony, string cCity, char carOrBike, int day, int month, int year, string category)
{
	this->tid = tId;
	this->buyer.setCustomer(cId, cName, cContact, cHNo, cSNo, cColony, cCity);
	this->carOrBike = carOrBike;
	automobile = nullptr;
	if (carOrBike == 'c' || carOrBike == 'C')
	{
		int id, preYear, currentYear, price;
		string company, model, wheelDrive;
		cout << "Enter Car Id: ";
		cin >> id;
		cout << "Enter Company: ";
		cin >> company;
		cout << "Enter Model Name: ";
		cin >> model;
		cout << "Enter Previous Model Year: ";
		cin >> preYear;
		cout << "Enter Latest Model Year: ";
		cin >> currentYear;
		cout << "Enter Price of Car: ";
		cin >> price;
		cout << "Enter Wheel Drive of Car: ";
		cin >> wheelDrive;
		automobile = new Car(id, company, model, preYear, currentYear, price, wheelDrive);

	}
	else if (carOrBike == 'b' || carOrBike == 'B')
	{
		int id, preYear, currentYear, price;
		string company, model, type;
		cout << "Enter Car Id: ";
		cin >> id;
		cout << "Enter Company: ";
		cin >> company;
		cout << "Enter Model Name: ";
		cin >> model;
		cout << "Enter Previous Model Year: ";
		cin >> preYear;
		cout << "Enter Latest Model Year: ";
		cin >> currentYear;
		cout << "Enter Price of Car: ";
		cin >> price;
		cout << "Enter Wheel Drive of Car: ";
		cin >> type;
		automobile = new Bike(id, company, model, preYear, currentYear, price, type);
	}
	this->Tdate.setDate(day, month, year);
	this->category = category;
}
Transaction::Transaction(const Transaction& t)
{
	this->tid = t.tid;

	this->buyer.setCId(t.buyer.getCId());
	this->buyer.setName(t.buyer.getName());
	this->buyer.setContact(t.buyer.getContact());
	this->buyer.Caddress.setHNo(t.buyer.Caddress.getHNo());
	this->buyer.Caddress.setSNo(t.buyer.Caddress.getSNo());
	this->buyer.Caddress.setColony(t.buyer.Caddress.getColony());
	this->buyer.Caddress.setCity(t.buyer.Caddress.getCity());

	this->carOrBike = t.carOrBike;
	this->automobile = nullptr;
	if (carOrBike == 'c' || carOrBike == 'C')
	{
		automobile = new Car();
		automobile->setVId(t.automobile->getVId());
		automobile->setCompany(t.automobile->getCompany());
		automobile->setModel(t.automobile->getModel());
		automobile->setPreviousYear(t.automobile->getPreviousYear());
		automobile->setCurrentYear(t.automobile->getCurrentYear());
		automobile->setPrice(t.automobile->getPrice());
		automobile->setWheelDrive(t.automobile->getWheelDrive());
	}
	else if (carOrBike == 'b' || carOrBike == 'B')
	{
		automobile = new Bike();
		automobile->setVId(t.automobile->getVId());
		automobile->setCompany(t.automobile->getCompany());
		automobile->setModel(t.automobile->getModel());
		automobile->setPreviousYear(t.automobile->getPreviousYear());
		automobile->setCurrentYear(t.automobile->getCurrentYear());
		automobile->setPrice(t.automobile->getPrice());
		automobile->setType(t.automobile->getType());
	}
	this->Tdate.setDay(t.Tdate.getDay());
	this->Tdate.setMonth(t.Tdate.getMonth());
	this->Tdate.setYear(t.Tdate.getYear());
	this->category = t.category;
}

Transaction::~Transaction()
{
	delete automobile;
}

int Transaction::getTransactionCount()
{
	return transactionCount;
}
int Transaction::getTid()
{
	return tid;
}
string Transaction::getCustomer()
{
	return buyer.getCustomer();
}

char Transaction::getCarOrBike()
{
	return carOrBike;
}
string Transaction::getAutomobile()
{
	return automobile->getVehicle();
}
string Transaction::getTdate()
{
	return Tdate.getDate();
}
string Transaction::getCategory()
{
	return category;
}
void Transaction::setTransactionCount()
{
	transactionCount = Transaction::recCount();
}
void Transaction::setTId(int id)
{
	this->tid = id;
}
void Transaction::setBuyer(int bid, string name, string contact, int Hno, int Sno, string colony, string city)
{
	buyer.setCustomer(bid, name, contact, Hno, Sno, colony, city);
}

void Transaction::setCarOrBike(char carOrBike)
{
	this->carOrBike = carOrBike;
}
void Transaction::setAutomobile(int vid, string company, string model, int preYear, int currentYear, int price, string wheelDrive, string type)
{
	automobile->setVehicle(vid, company, model, preYear, currentYear, price, wheelDrive, type);
}
void Transaction::setTdate(int day, int month, int year)
{
	Tdate.setDate(day, month, year);
}
void Transaction::setCategory(string category)
{
	this->category = category;
}
void Transaction::setAutomobileCar()
{
	automobile = new Car;
}
void Transaction::setAutomobileBike()
{
	automobile = new Bike;
}

int Transaction::alreadyExist(Transaction t[], int size, int searchId)
{
	for (int i = 0; i < size; i++)
	{
		if (t[i].tid == searchId)
		{
			return i;
		}
	}
	return -1;

}
void Transaction::objToFile()
{
	ofstream fout;
	fout.open("transactions.txt", ios::app);
	fout << getDetail() << endl;
	fout.close();
}
int Transaction::recCount()
{
	ifstream fin;
	fin.open("transactions.txt");
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
void Transaction::readFile(Transaction t[], int size)
{
	ifstream fin;
	fin.open("transactions.txt");
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
	int cid, cHno, cSno;
	string cname, ccontact, cColony, cCity;
	int vid, vpreYear, vcurrentYear, vprice;
	string vmodel, vcompany, vwheelDrive, vtype;
	int dday, dmonth, dyear;
	for (int i = 0; i < size; i++)
	{
		fin >> t[i].tid >> cid >> cname >> ccontact >> cHno >> cSno >> cColony >> cCity;
		t[i].buyer.setCustomer(cid, cname, ccontact, cHno, cSno, cColony, cCity);
		fin >> t[i].carOrBike;
		if (t[i].carOrBike == 'c' || t[i].carOrBike == 'C')
		{
			t[i].automobile = new Car();
			fin >> vid >> vcompany >> vmodel >> vpreYear >> vcurrentYear >> vprice >> vwheelDrive;
			t[i].automobile->setVehicle(vid, vcompany, vmodel, vpreYear, vcurrentYear, vprice, vwheelDrive, vtype);
		}
		else if (t[i].carOrBike == 'b' || t[i].carOrBike == 'B')
		{
			t[i].automobile = new Bike();
			fin >> vid >> vcompany >> vmodel >> vpreYear >> vcurrentYear >> vprice >> vtype;
			t[i].automobile->setVehicle(vid, vcompany, vmodel, vpreYear, vcurrentYear, vprice, vwheelDrive, vtype);
		}
		fin >> dday >> dmonth >> dyear;
		t[i].Tdate.setDate(dday, dmonth, dyear);
		fin >> t[i].category;
	}
	fin.close();
}
void Transaction::arrayToFile(Transaction t[], int size)
{
	ofstream fout;
	fout.open("transactions.txt");
	for (int i = 0; i < size; i++)
	{
		if (t[i].tid != 0)
		{
			fout << t[i].getDetail() << endl;
		}
	}
	fout.close();
}
string Transaction::getDetail()
{
	return to_string(tid) + "\t" + buyer.getDetail() + "\t" + carOrBike + "\t" + automobile->getDetail() + "\t" + Tdate.getDetail() + "\t" + category;
}
void Transaction::add()
{
	Transaction t;
	cin >> t;
	t.objToFile();
	cout << "Record Successfully Entered\n";
}
void Transaction::view(Transaction t[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << t[i] << endl;
		cout << "____________________________________________________________\n";
	}
	cout << endl;
}
int Transaction::search(Transaction t[], int size)
{
	cout << "Enter the ID: ";
	int searchId;
	cin >> searchId;
	return Transaction::alreadyExist(t, size, searchId);
}
void Transaction::update(Transaction t[], int size)
{
	int target = Transaction::search(t, size);
	if (target != -1)
	{
		cout << t[target] << endl;
		cout << "Enter the new category(Cash/Check): ";
		cin >> t[target].category;
		Transaction::arrayToFile(t, size);
		cout << "Transaction updated\n";
	}
	else
	{
		cout << "This id does not exist\n";
	}
}
void Transaction::Delete(Transaction t[], int size)
{
	int target = Transaction::search(t, size);
	if (target != -1)
	{
		t[target].tid = 0;
		Transaction::arrayToFile(t, size);
		cout << "Record deleted successfully\n";
	}
	else
	{
		cout << "This id does not exist\n";
	}
}
ostream& operator << (ostream& out, const Transaction& t)
{
	out << "Transaction ID: " << t.tid << ", Customer: " << t.buyer.getCustomer() << ", Car or Bike: " << t.carOrBike << ", Automobile: " << t.automobile->getVehicle() << ", Transaction Date: " << t.Tdate.getDate() << ", Transaction Category:" << t.category;
	return out;
}
istream& operator >> (istream& in, Transaction& t)
{
	cout << "Enter Transaction ID: ";
	cin >> t.tid;
	int cid, cHno, cSno;
	string cname, ccontact, cColony, cCity;
	cout << "Enter Customer ID: ";
	in >> cid;
	cout << "Enter Customer Name: ";
	in >> cname;
	cout << "Enter Customer Contact: ";
	in >> ccontact;
	cout << "Enter Customer's House Number: ";
	in >> cHno;
	cout << "Enter Customer's Street Number: ";
	in >> cSno;
	cout << "Enter Customer's Colony: ";
	in >> cColony;
	cout << "Enter Customer's City: ";
	in >> cCity;
	t.buyer.setCustomer(cid, cname, ccontact, cHno, cSno, cColony, cCity);
	cout << "Enter 'C' for Car and 'B' for Motor Bike: ";
	in >> t.carOrBike;
	int vid, vpreYear, vcurrentYear, vprice;
	string vmodel, vcompany, vwheelDrive, vtype;
	cout << "Enter Vehicle ID: ";
	in >> vid;
	cout << "Enter Company Name: ";
	in >> vcompany;
	cout << "Enter Model Name: ";
	in >> vmodel;
	cout << "Enter Previous Model Year: ";
	cin >> vpreYear;
	cout << "Enter Latest Model Year: ";
	cin >> vcurrentYear;
	cout << "Enter Price: ";
	in >> vprice;
	if (t.carOrBike == 'c' || t.carOrBike == 'C')
	{
		cout << "Enter Wheel Drive(FWD/RWD/4WD): ";
		in >> vwheelDrive;
		t.automobile = new Car(vid, vcompany, vmodel, vpreYear, vcurrentYear, vprice, vwheelDrive);
	}
	else if (t.carOrBike == 'b' || t.carOrBike == 'B')
	{
		cout << "Enter Type of Motor Bike(Bi_Wheeler/Tri_Wheeler/Quad_wheeler): ";
		in >> vtype;
		t.automobile = new Bike(vid, vcompany, vmodel, vpreYear, vcurrentYear, vprice, vtype);
	}
	int dday, dmonth, dyear;
	cout << "Enter Date of Transaction(Enter day first, then month, then year):\n";
	in >> dday >> dmonth >> dyear;
	t.Tdate.setDate(dday, dmonth, dyear);
	cout << "Enter Category of Transaction(Cash/Check): ";
	in >> t.category;
	return in;
}