#include "Date.h"



Date::Date()
{
	day = 1;
	month = 1;
	year = 1;
}
Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}
Date::Date(const Date& d)
{
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;
}
Date::~Date()
{
}
int Date::getDay() const
{
	return day;
}
int Date::getMonth() const
{
	return month;
}
int Date::getYear() const
{
	return year;
}
void Date::setDay(const int day)
{
	this->day = day;
}
void Date::setMonth(const int month)
{
	this->month = month;
}
void Date::setYear(const int year)
{
	this->year = year;
}

void Date::setDate(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;

}
string Date::getDate() const
{
	return " " + to_string(day) + " - " + to_string(month) + " - " + to_string(year);
}
string Date::getDetail()
{
	return to_string(day) + "\t" + to_string(month) + "\t" + to_string(year);

}
