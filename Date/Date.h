#include <iostream>

class Date
{
	int year;
	unsigned month;
	unsigned day;

	friend std::istream &operator >> (std::istream&, Date&);
	friend std::ostream &operator << (std::ostream&, Date&);
public:
	Date();
	Date(int, unsigned, unsigned);
	Date& operator = (const Date&);
	bool operator == (const Date&);
	bool operator > (const Date&);
	bool operator < (const Date&);
	bool operator >= (const Date&);
	bool operator <= (const Date&);
	int getYear()
	{
		return year;
	}
	unsigned getMonth()
	{
		return month;
	}
	unsigned getDay()
	{
		return day;
	}
	void setYear(const int year);
	bool setMonth(const unsigned month);
	bool setDay(const unsigned day);
};