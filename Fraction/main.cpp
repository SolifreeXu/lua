#include "Fraction.h"
#include <random>
#include <ctime>

Fraction generate(long upperLimit)
{
	static std::default_random_engine random(time(NULL));
	static std::uniform_int_distribution<long> distribution(0, upperLimit);
	long molecule = distribution(random);
	long denominator = distribution(random) + 1;
	if (distribution(random) % 2)
		molecule = -molecule;
	return Fraction(molecule, denominator);
}

using std::cout;

int main()
{
	Fraction left = generate(10000), right = generate(10000), buff, result;
	switch (rand() % 4)
	{
	case 0:
		buff = left + right;
		cout << left << " + ";
		if (right < 0)
			cout << '(' << right << ')';
		else
			cout << right;
		cout << " = ";
		break;
	case 1:
		buff = left - right;
		cout << left << " - ";
		if (right < 0)
			cout << '(' << right << ')';
		else
			cout << right;
		cout << " = ";
		break;
	case 2:
		buff = left*right;
		cout << left << " * ";
		if (right < 0)
			cout << '(' << right << ')';
		else
			cout << right;
		cout << " = ";
		break;
	case 3:
		buff = left / right;
		cout << left << " / ";
		if (right < 0)
			cout << '(' << right << ')';
		else
			cout << right;
		cout << " = ";
		break;
	}
	std::cin >> result;
	if (result == buff)
		cout << "»Ø´ðÕýÈ·\n";
	else
		cout << "»Ø´ð´íÎó\n";
	return 0;
}
