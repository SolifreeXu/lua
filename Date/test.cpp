#include "Date.h"

int main()
{
	Date date;
	std::cout << date.getYear() << '/' << date.getMonth() << '/' << date.getDay() << std::endl;
	date.setYear(-100);
	date.setMonth(0);
	date.setDay(-1);
	std::cout << date.getYear() << '/' << date.getMonth() << '/' << date.getDay() << std::endl;
	return 0;
}