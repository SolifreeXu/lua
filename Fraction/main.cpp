#include "Fraction.h"
#include <random>
#include <ctime>

Fraction generate()
{
	static std::default_random_engine random(time(NULL));
	static std::uniform_int_distribution<int> distribution(0, 10000);
	long molecule = distribution(random);
	long denominator = distribution(random) + 1;
	if (distribution(random) % 2)
		molecule = -molecule;
	return Fraction(molecule, denominator);
}

using std::cout;

int main()
{
	Fraction left = generate(), right = generate(), buff, result;
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
		cout << "回答正确\n";
	else
		cout << "回答错误\n";
	return 0;
}