#pragma once
#include <iostream>
#include <string>
using namespace std;
class Date
{
	int day;
	int month;
	int year;
public:
	Date();
	Date(int, int, int);
	Date(const Date& d);
	~Date();

	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(const int);
	void setMonth(const int);
	void setYear(const int);

	void setDate(int, int, int);
	string getDate() const;
	string getDetail();
};

