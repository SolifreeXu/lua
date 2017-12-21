#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

class Date
{
private:
	int year;
	unsigned month;
	unsigned day;
public:
	Date();
	Date(int, unsigned, unsigned);
	Date operator = (const Date&);
	bool operator == (const Date&);
	bool operator > (const Date&);
	bool operator < (const Date&);
	bool operator >= (const Date&);
	bool operator <= (const Date&);
	friend istream &operator >> (istream&, Date&);
	friend ostream &operator << (ostream&, Date&);
	int get_year();
	unsigned get_month();
	unsigned get_day();
	void set_year(const int year);
	bool set_month(const unsigned month);
	bool set_day(const unsigned day);
};