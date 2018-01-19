#include "Date.h"

#include <time.h>

std::istream &operator >> (std::istream &input, Date &object)
{
	input >> object.year >> object.month >> object.day;
	return input;
}

std::ostream &operator << (std::ostream &output, Date &object)
{
	output << object.year << '-';
	if (object.month < 10)
		output << '0';
	output << object.month << '-';
	if (object.day < 10)
		output << '0';
	output << object.day << ' ';
	return output;
}

Date::Date()
{
	time_t timen;
	struct tm *tb = localtime(&(timen = time(NULL)));
	year = tb->tm_year + 1900;
	month = tb->tm_mon + 1;
	day = tb->tm_mday;
}

Date::Date(int year, unsigned month, unsigned day)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

Date& Date::operator = (const Date &other)
{
	year = other.year;
	month = other.month;
	day = other.day;
	return *this;
}

bool Date::operator==(const Date &other)
{
	if (year == other.year && month == other.month && day == other.day)
		return true;
	return false;
}

bool Date::operator>(const Date &other)
{
	if (this->year > other.year)
		return true;
	if (this->year == other.year && this->month > other.month)
		return true;
	if (this->year == other.year && this->month == other.month && this->day > other.day)
		return true;
	return false;
}

bool Date::operator<(const Date &other)
{
	if (year < other.year)
		return true;
	if (year == other.year && month < other.month)
		return true;
	if (year == other.year && month == other.month && day < other.day)
		return true;
	return false;
}

bool Date::operator>=(const Date &other)
{
	if (this->year > other.year)
		return true;
	else if (this->year == other.year && this->month > other.month)
		return true;
	else if (this->year == other.year && this->month == other.month && this->day >= other.day)
		return true;
	return false;
}

bool Date::operator<=(const Date &other)
{
	if (year < other.year)
		return true;
	else if (year == other.year && month < other.month)
		return true;
	else if (year == other.year && month == other.month && day <= other.day)
		return true;
	return false;
}

void Date::setYear(const int year)
{
	this->year = year;
	if (year % 4 == 0 && month == 2 && day > 28)
		day = 28;
}

bool Date::setMonth(const unsigned month)
{
	if (month > 0 && month <= 12)
	{
		this->month = month;
		if (month == 2)
		{
			if (year % 4 != 0 && day > 29)
				day = 29;
			if (year % 4 == 0 && day > 28)
				day = 28;
		}
		else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			day = 30;
		return true;
	}
	return false;
}

bool Date::setDay(const unsigned day)
{
	if (month == 2 && day <= 29)
	{
		if (year % 4 != 0)
		{
			this->day = day;
			return true;
		}
		else if (year % 4 == 0 && day<29)
		{
			this->day = day;
			return true;
		}
	}
	else if ((month > 0 && month < 8 && month % 2 == 1 || month >= 8 && month <= 12 && month % 2 == 0) && day <= 31)
	{
		this->day = day;
		return true;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day < 31)
	{
		this->day = day;
		return true;
	}
	return false;
}