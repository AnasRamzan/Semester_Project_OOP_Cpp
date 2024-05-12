#pragma once
#include <iostream>
#include <string>
#include "Car.h"
#include "Bike.h"
#include "Customer.h"
#include "Date.h"
class Transaction
{
	static int transactionCount;
	int tid;
	Customer buyer;
	char carOrBike;
	Vehicle* automobile;
	Date Tdate;
	string category;
	static int alreadyExist(Transaction t[], int, int);
public:
	Transaction();
	Transaction(int, int, string, string, int, int, string, string, char, int, int, int, string);
	Transaction(const Transaction& t);
	~Transaction();

	static int getTransactionCount();
	int getTid();
	string getCustomer();
	char getCarOrBike();
	string getAutomobile();
	string getTdate();
	string getCategory();
	static void setTransactionCount();
	void setTId(int);
	void setBuyer(int, string, string, int, int, string, string);
	void setCarOrBike(char);
	void setAutomobile(int, string, string, int, int, int, string, string);
	void setTdate(int, int, int);
	void setCategory(string);

	void setAutomobileCar();
	void setAutomobileBike();


	void objToFile();
	static int recCount();
	static void readFile(Transaction t[], int);
	static void arrayToFile(Transaction t[], int);

	string getDetail();

	static void add();
	static void view(Transaction t[], int);
	static int search(Transaction t[], int);
	static void update(Transaction t[], int);
	static void Delete(Transaction t[], int);

	friend ostream& operator << (ostream& out, const Transaction& t);
	friend istream& operator >> (istream& in, Transaction& t);
};

