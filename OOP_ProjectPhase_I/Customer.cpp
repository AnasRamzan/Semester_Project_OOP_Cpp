#include "Customer.h"

int Customer::customerCount = 0;

Customer::Customer()
{
	Cid = 0;
	name = "";
	contact = "";
	Caddress = Address();
}
Customer::Customer(int id, string name, string contact, int houseNo, int streetNo, string colony, string city)
{
	this->Cid = id;
	this->name = name;
	this->contact = contact;
	Caddress.setAddress(houseNo, streetNo, colony, city);

}
Customer::Customer(const Customer& cust)
{
	this->Cid = cust.Cid;
	this->name = cust.name;
	this->contact = cust.contact;
	this->Caddress.setHNo(cust.Caddress.getHNo());
	this->Caddress.setSNo(cust.Caddress.getSNo());
	this->Caddress.setColony(cust.Caddress.getColony());
	this->Caddress.setCity(cust.Caddress.getCity());

}
Customer::~Customer()
{
}
int Customer::getCId() const
{
	return Cid;
}
string Customer::getName() const
{
	return name;
}
string Customer::getContact() const
{
	return contact;
}
string Customer::getCaddress() const
{
	return Caddress.getAddress();
}
int Customer::getCustomerCount()
{
	return customerCount;
}
string Customer::getCustomer() const
{
	return "ID: " + to_string(Cid) + ", Name: " + name + ", Contact: " + contact + ", Address: " + Caddress.getAddress();
}
void Customer::setCId(int id)
{
	this->Cid = id;
}
void Customer::setName(string name)
{
	this->name = name;
}
void Customer::setContact(string contact)
{
	this->contact = contact;
}
void Customer::setCaddress(int houseNo, int streetNo, string colony, string city)
{
	this->Caddress.setAddress(houseNo, streetNo, colony, city);
}
void Customer::setCustomerCount()
{
	customerCount = Customer::recCount();
}
void Customer::setCustomer(int id, string name, string contact, int Hno, int Sno, string colony, string city)
{
	this->Cid = id;
	this->name = name;
	this->contact = contact;
	Caddress.setAddress(Hno, Sno, colony, city);
}

int Customer::getHNo()
{
	return Caddress.getHNo();
}
int Customer::getSNo()
{
	return Caddress.getSNo();
}
string Customer::getColony()
{
	return Caddress.getColony();
}
string Customer::getCity()
{
	return Caddress.getCity();
}

int Customer::alreadyExist(Customer cust[], int size, int searchId)
{
	for (int i = 0; i < size; i++)
	{
		if (cust[i].Cid == searchId)
		{
			return i;
		}
	}
	return -1;

}
void Customer::objToFile()
{
	ofstream fout;
	fout.open("customers.txt", ios::app);
	fout << getDetail() << endl;
	fout.close();
}
int Customer::recCount()
{
	ifstream fin;
	fin.open("customers.txt");
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
void Customer::readFile(Customer cust[], int size)
{
	ifstream fin;
	fin.open("customers.txt");
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
	int tempHno, tempSno;
	string tempColony, tempCity;
	for (int i = 0; i < size; i++)
	{
		fin >> cust[i].Cid >> cust[i].name >> cust[i].contact >> tempHno >> tempSno >> tempColony >> tempCity;
		cust[i].Caddress.setHNo(tempHno);
		cust[i].Caddress.setSNo(tempSno);
		cust[i].Caddress.setColony(tempColony);
		cust[i].Caddress.setCity(tempCity);
	}
	fin.close();
}
void Customer::arrayToFile(Customer cust[], int size)
{
	ofstream fout;
	fout.open("customers.txt");
	for (int i = 0; i < size; i++)
	{
		if (cust[i].Cid != 0)
		{
			fout << cust[i].getDetail() << endl;
		}
	}
	fout.close();
}
string Customer::getDetail()
{
	return to_string(Cid) + "\t" + name + "\t" + contact + "\t" + Caddress.getDetail();
}
void Customer::add()
{
	Customer cust;
	cin >> cust;
	cust.objToFile();
	cout << "Record Successfully Entered\n";
}
void Customer::view(Customer cust[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << cust[i] << endl;
		cout << "____________________________________________________________\n";
	}
	cout << endl;
}
int Customer::search(Customer cust[], int size)
{
	cout << "Enter the ID: ";
	int searchId;
	cin >> searchId;
	return Customer::alreadyExist(cust, size, searchId);
}
void Customer::update(Customer cust[], int size)
{
	int target = Customer::search(cust, size);
	if (target != -1)
	{
		cout << cust[target] << endl;
		cout << "Enter the new contact: ";
		cin >> cust[target].contact;
		Customer::arrayToFile(cust, size);
		cout << "Contact updated\n";
	}
	else
	{
		cout << "This id does not exist\n";
	}
}
void Customer::Delete(Customer cust[], int size)
{
	int target = Customer::search(cust, size);
	if (target != -1)
	{
		cust[target].Cid = 0;
		cust[target].name = "";
		cust[target].contact = "";
		cust[target].Caddress.setAddress(0, 0, "", "");
		Customer::arrayToFile(cust, size);
		cout << "Record deleted successfully\n";
	}
	else
	{
		cout << "This id does not exist\n";
	}
}
ostream& operator << (ostream& out, const Customer& cust)
{
	out << "ID: " << cust.Cid << ", Name: " << cust.name << ", Contact: " << cust.contact << ", Address: " << cust.Caddress.getAddress();
	return out;
}
istream& operator >> (istream& in, Customer& cust)
{
	cout << "Enter ID: ";
	in >> cust.Cid;
	cout << "Enter Customer Name: ";
	in >> cust.name;
	cout << "Enter Customer Contact: ";
	in >> cust.contact;
	int tempHno, tempSno;
	string tempColony, tempCity;
	cout << "Enter Customer's House Number: ";
	in >> tempHno;
	cout << "Enter Customer's Street Number: ";
	in >> tempSno;
	cout << "Enter Customer's Colony: ";
	in >> tempColony;
	cout << "Enter Customer's City: ";
	in >> tempCity;
	cust.Caddress.setAddress(tempHno, tempSno, tempColony, tempCity);
	return in;
}
