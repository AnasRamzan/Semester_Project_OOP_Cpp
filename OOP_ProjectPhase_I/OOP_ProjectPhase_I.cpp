
#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include "Customer.h"
#include "Transaction.h"

using namespace std;
void mainMenu();

void adminMenu();
void carMenu();
void bikeMenu();
void customerMenu();
void transactionMenu();

void buyerMenu();

int main()
{
	while (true)
	{
		mainMenu();
	}
}
void mainMenu()
{
	char choice;
	cout << "Enter 'A' if you are Admin or Enter 'B' if you are Buyer\nEnter 'E' to EXIT\n";
	cin >> choice;
	if (choice == 'A' || choice == 'a')
	{
		adminMenu();
	}
	else if (choice == 'B' || choice == 'b')
	{
		buyerMenu();
	}
	else if (choice == 'E' || choice == 'e')
	{
		cout << "The Program has been Turned Off\n";
		exit(0);
	}
	else
	{
		cout << "You have Entered Invalid Option!\n";
	}
}
void adminMenu()
{
	cout << "1. Manage Cars\n2. Manage Bikes\n3. Manage Customers\n4. Manage Transactions:\n";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		carMenu();
	}
	else if (choice == 2)
	{
		bikeMenu();
	}
	else if (choice == 3)
	{
		customerMenu();
	}
	else if (choice == 4)
	{
		transactionMenu();
	}
	else
	{
		cout << "Invalid Choice!\n";
	}
}
void carMenu()
{
	cout << "1. Add Car\n2. View All Cars\n3. Search a car\n4. Update Price of a Car\n5. Delete a Car\n";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		Car::add();
	}
	else
	{
		int size = Car::recCount();
		Car* carRecord;
		carRecord = new Car[size];
		Car::readFile(carRecord, size);
		if (choice == 2)
		{
			Car::setCarCount();
			cout << "Total Car Inventory: " << Car::getCarCount() << endl ;
			Car::view(carRecord, size);
		}
		else if (choice == 3)
		{
			int index = Car::search(carRecord, size);
			if (index != -1)
			{
				cout << "Record exists\n";
				cout << carRecord[index] << endl;
			}
			else
			{
				cout << "Record doesn't exist\n";
			}
		}
		else if (choice == 4)
		{
			Car::update(carRecord, size);
		}
		else if (choice == 5)
		{
			Car::Delete(carRecord, size);
		}
		else
		{
			cout << "You have entered invalid option\n";
		}
	}
}

void bikeMenu()
{
	cout << "1. Add Bike\n2. View All Bikes\n3. Search a Bike\n4. Update Price of a Bike\n5. Delete a Bike\n";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		Bike::add();
	}
	else
	{
		int size = Bike::recCount();
		Bike* bikeRecord;
		bikeRecord = new Bike[size];
		Bike::readFile(bikeRecord, size);
		if (choice == 2)
		{
			Bike::setBikeCount();
			cout << "Total Bike Inventory: " << Bike::getBikeCount() << endl;
			Bike::view(bikeRecord, size);
		}
		else if (choice == 3)
		{
			int index = Bike::search(bikeRecord, size);
			if (index != -1)
			{
				cout << "Record exists\n";
				cout << bikeRecord[index] << endl;
			}
			else
			{
				cout << "Record doesn't exist\n";
			}
		}
		else if (choice == 4)
		{
			Bike::update(bikeRecord, size);
		}
		else if (choice == 5)
		{
			Bike::Delete(bikeRecord, size);
		}
		else
		{
			cout << "You have entered invalid option\n";
		}
	}
}

void customerMenu()
{
	cout << "1. Add Customer\n2. View All Customers' Record\n3. Search a Customer\n4. Update Contact of a Customer\n5. Delete a Customer Record\n";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		Customer::add();
	}
	else
	{
		int size = Customer::recCount();
		Customer* customerRecord;
		customerRecord = new Customer[size];
		Customer::readFile(customerRecord, size);
		if (choice == 2)
		{
			Customer::setCustomerCount();
			cout << "Total Customers Entered in Record: " << Customer::getCustomerCount() << endl;
			Customer::view(customerRecord, size);
		}
		else if (choice == 3)
		{
			int index = Customer::search(customerRecord, size);
			if (index != -1)
			{
				cout << "Record exists\n";
				cout << customerRecord[index];
			}
			else
			{
				cout << "Record doesn't exist\n";
			}
		}
		else if (choice == 4)
		{
			Customer::update(customerRecord, size);
		}
		else if (choice == 5)
		{
			Customer::Delete(customerRecord, size);
		}
		else
		{
			cout << "You have entered invalid option\n";
		}
	}
}
void transactionMenu()
{
	cout << "1. Add Transaction\n2. View All Transactions\n3. Search a Transaction\n4. Update Category of a Transaction\n5. Delete a Transaction\n";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		Transaction::add();
	}
	else
	{
		int size = Transaction::recCount();
		Transaction* transactionRecord;
		transactionRecord = new Transaction[size];
		Transaction::readFile(transactionRecord, size);
		if (choice == 2)
		{
			Transaction::setTransactionCount();
			cout << "Total Transactions Entered in Record: " << Transaction::getTransactionCount() << endl;
			Transaction::view(transactionRecord, size);
		}
		else if (choice == 3)
		{
			int signal = Transaction::search(transactionRecord, size);
			if (signal != -1)
			{
				cout << "Record exists\n";
			}
			else
			{
				cout << "Record doesn't exist\n";
			}
		}
		else if (choice == 4)
		{
			Transaction::update(transactionRecord, size);
		}
		else if (choice == 5)
		{
			Transaction::Delete(transactionRecord, size);
		}
		else
		{
			cout << "You have entered invalid option\n";
		}
	}
}

void buyerMenu()
{
	cout << "Are you Our Old Customer or new Customer('O'/'N'): ";
	char choice;
	cin >> choice;
	Transaction t;
	int customerCount = Customer::recCount();
	Customer* customerRecord = new Customer[customerCount];
	Customer::readFile(customerRecord, customerCount);
	int carCount = Car::recCount();
	Car* carRecord = new Car[carCount];
	Car::readFile(carRecord, carCount);
	int bikeCount = Bike::recCount();
	Bike* bikeRecord = new Bike[bikeCount];
	Bike::readFile(bikeRecord, bikeCount);
	int transactionCount = Transaction::recCount();
	Transaction* transactionRecord = new Transaction[transactionCount];
	Transaction::readFile(transactionRecord, transactionCount);
	Transaction::view(transactionRecord, transactionCount);
	cout << "Enter the Transaction ID(Enter a unique ID From those previously Entered in Record): ";
	int tid;
	cin >> tid;
	t.setTId(tid);
	if (choice == 'N' || choice == 'n')
	{
		int cid, cHno, cSno;
		string cname, ccontact, ccolony, ccity;
		Customer::view(customerRecord, customerCount);
		cout << "Enter the Customer ID(Enter a unique ID From those previously Entered in Record): ";
		cin >> cid;
		cout << "Enter your Name: ";
		cin >> cname;
		cout << "Enter your Contact Number: ";
		cin >> ccontact;
		cout << "Provide Your Address:\n";
		cout << "Enter your House Number: ";
		cin >> cHno;
		cout << "Enter your Street Number: ";
		cin >> cSno;
		cout << "Enter your Colony Name: ";
		cin >> ccolony;
		cout << "Enter your City Name: ";
		cin >> ccity;
		Customer c(cid, cname, ccontact, cHno, cSno, ccolony, ccity);
		c.objToFile();
		t.setBuyer(cid, cname, ccontact, cHno, cSno, ccolony, ccity);
		
	}
	else if (choice == 'O' || choice == 'o')
	{
		Customer::view(customerRecord, customerCount);
		cout << "Identify your ID From the Shown Record of Customers:\n";
		int index = Customer::search(customerRecord, customerCount);
		int cid, cHno, cSno;
		string cname, ccontact, ccolony, ccity;
		cid = customerRecord[index].getCId();
		cname = customerRecord[index].getName();
		ccontact = customerRecord[index].getContact();
		cHno = customerRecord[index].getHNo();
		cSno = customerRecord[index].getSNo();
		ccolony = customerRecord[index].getColony();
		ccity = customerRecord[index].getCity();
		t.setBuyer(cid, cname, ccontact, cHno, cSno, ccolony, ccity);	
	}
	else
	{
		cout << "You have Entered Invalid Option!\n";
	}
	cout << "Do you Want to Buy Car or Motor Bike('C'/'B'): ";
	char vehicle;
	cin >> vehicle;
	t.setCarOrBike(vehicle);
	int vid, vpreYear, vcurrentYear, vprice;
	string vmodel, vcompany, vwheelDrive, vtype;
	if (vehicle == 'B' || vehicle == 'b')
	{
		t.setAutomobileBike();
		Bike::view(bikeRecord, bikeCount);
		cout << "Identify the Bike You want to Buy(Enter the ID of your Desired Bike from the Bikes shown):\n";
		int index = Bike::search(bikeRecord, bikeCount);
		vid = bikeRecord[index].getVId();
		vcompany = bikeRecord[index].getCompany();
		vmodel = bikeRecord[index].getModel();
		vpreYear = bikeRecord[index].getPreviousYear();
		vcurrentYear = bikeRecord[index].getCurrentYear();
		vprice = bikeRecord[index].getPrice();
		vtype = bikeRecord[index].getType();
		t.setAutomobile(vid, vcompany, vmodel, vpreYear, vcurrentYear, vprice, vwheelDrive, vtype);
	}
	else if (vehicle == 'C' || vehicle == 'c')
	{
		t.setAutomobileCar();
		Car::view(carRecord, carCount);
		cout << "Identify the Car You want to Buy(Enter the ID of your Desired Car from the Cars shown):\n";
		int index = Car::search(carRecord, carCount);
		vid = carRecord[index].getVId();
		vcompany = carRecord[index].getCompany();
		vmodel = carRecord[index].getModel();
		vpreYear = carRecord[index].getPreviousYear();
		vcurrentYear = carRecord[index].getCurrentYear();
		vprice = carRecord[index].getPrice();
		vwheelDrive = carRecord[index].getWheelDrive();
		t.setAutomobile(vid, vcompany, vmodel, vpreYear, vcurrentYear, vprice, vwheelDrive, vtype);
	}
	else
	{
		cout << "You have Entered Invalid Option!\n";
	}
	int dday, dmonth, dyear;
	cout << "Enter Today's Date(Enter Day First, Then Month and Finally Year):\n";
	cin >> dday >> dmonth >> dyear;
	t.setTdate(dday, dmonth, dyear);
	cout << "Enter Transaction Category(Cash/Check): ";
	string cat;
	cin >> cat;
	t.setCategory(cat);
	t.objToFile();
	cout << "\nCongratulations! You have Completed the Process of Buying Your Vehicle\n";
	cout << "___*Thank you for Choosing to have your Dream Vehicle*___\n\n";
}