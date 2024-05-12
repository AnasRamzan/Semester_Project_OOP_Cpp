#pragma once
#include <iostream>
#include "Address.h"
#include <fstream>
using namespace std;
class Customer
{
	static int customerCount;
	int Cid;
	string name;
	string contact;
	Address Caddress;
	static int alreadyExist(Customer cust[], int, int);


public:
	Customer();
	Customer(int, string, string, int, int, string, string);
	Customer(const Customer& cust);
	~Customer();

	int getCId() const;
	string getName() const;
	string getContact() const;
	string getCaddress() const;
	static int getCustomerCount();
	string getCustomer() const;
	void setCId(int);
	void setName(string);
	void setContact(string);
	void setCaddress(int, int, string, string);
	static void setCustomerCount();
	void setCustomer(int, string, string, int, int, string, string);

	int getHNo();
	int getSNo();
	string getColony();
	string getCity();

	void objToFile();
	static int recCount();
	static void readFile(Customer cust[], int);
	static void arrayToFile(Customer cust[], int);

	string getDetail();

	static void add();
	static void view(Customer cust[], int);
	static int search(Customer cust[], int);
	static void update(Customer cust[], int);
	static void Delete(Customer cust[], int);

	friend ostream& operator << (ostream& out, const Customer& cust);
	friend istream& operator >> (istream& in, Customer& cust);

	friend class Transaction;
};

