#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

class Fraction
{
	long m_iMolecule;
	long m_iDenominator;
	friend ostream& operator<<(ostream &os, const Fraction &fraction);
	friend istream& operator>>(istream &is, Fraction &fraction);
public:
	Fraction() :m_iMolecule(0), m_iDenominator(1){}
	Fraction(long molecule, long denominator) :m_iMolecule(molecule), m_iDenominator(denominator){}
	Fraction(long nNumber) :m_iMolecule(nNumber), m_iDenominator(1){}
	Fraction operator+(Fraction fraction);
	Fraction operator-(Fraction fraction);
	Fraction operator*(Fraction fraction);
	Fraction operator/(Fraction fraction);
	bool operator==(const Fraction &fraction);
	Fraction& operator=(Fraction &&fraction);
	operator float(){ return (float)m_iMolecule / m_iDenominator; }
	unsigned maxCommonDivisor(unsigned a, unsigned b);
	unsigned minCommonMultiple(unsigned a, unsigned b);
};

Fraction Fraction::operator+(Fraction fraction)
{
	unsigned commonNumber = minCommonMultiple(this->m_iDenominator, fraction.m_iDenominator);
	(fraction.m_iMolecule *= commonNumber / fraction.m_iDenominator)
		+= commonNumber / this->m_iDenominator*this->m_iMolecule;
	fraction.m_iDenominator = commonNumber;
	commonNumber = maxCommonDivisor(abs(fraction.m_iMolecule), fraction.m_iDenominator);
	fraction.m_iMolecule /= commonNumber;
	fraction.m_iDenominator /= commonNumber;
	return fraction;
}

Fraction Fraction::operator-(Fraction fraction)
{
	unsigned commonNumber = minCommonMultiple(this->m_iDenominator, fraction.m_iDenominator);
	fraction.m_iMolecule *= commonNumber / fraction.m_iDenominator;
	fraction.m_iMolecule = commonNumber / this->m_iDenominator*this->m_iMolecule - fraction.m_iMolecule;
	fraction.m_iDenominator = commonNumber;
	commonNumber = maxCommonDivisor(abs(fraction.m_iMolecule), fraction.m_iDenominator);
	fraction.m_iMolecule /= commonNumber;
	fraction.m_iDenominator /= commonNumber;
	return fraction;
}

Fraction Fraction::operator*(Fraction fraction)
{
	fraction.m_iMolecule *= this->m_iMolecule;
	fraction.m_iDenominator *= this->m_iDenominator;
	unsigned commonNumber = maxCommonDivisor(abs(fraction.m_iMolecule), fraction.m_iDenominator);
	fraction.m_iMolecule /= commonNumber;
	fraction.m_iDenominator /= commonNumber;
	return fraction;
}

Fraction Fraction::operator/(Fraction fraction)
{
	long lNumber = this->m_iMolecule*fraction.m_iDenominator;
	fraction.m_iDenominator = this->m_iDenominator*fraction.m_iMolecule;
	fraction.m_iMolecule = lNumber;
	if (fraction.m_iDenominator < 0)
	{
		fraction.m_iDenominator = -fraction.m_iDenominator;
		fraction.m_iMolecule = -fraction.m_iMolecule;
	}
	lNumber = maxCommonDivisor(abs(fraction.m_iMolecule), fraction.m_iDenominator);
	fraction.m_iMolecule /= lNumber;
	fraction.m_iDenominator /= lNumber;
	return fraction;
}

bool Fraction::operator==(const Fraction &fraction)
{
	return this->m_iMolecule == fraction.m_iMolecule && this->m_iDenominator == fraction.m_iDenominator;
}

Fraction& Fraction::operator=(Fraction &&fraction)
{
	this->m_iMolecule = fraction.m_iMolecule;
	this->m_iDenominator = fraction.m_iDenominator;
	return *this;
}

unsigned Fraction::maxCommonDivisor(unsigned a, unsigned b)
{
	if (a < b)	//当a小于b是实现两值互换
	{
		a ^= b;
		b ^= a;
		a ^= b;
	}
	unsigned c = a%b;	//a对b取余赋给c
	while (c != 0)	//当c不为0时执行循环体语句
	{
		a = b;	//将b赋给a
		b = c;	//将c的值赋给b
		c = a%b;	//继续取余并赋给c
	}
	return b;
}

unsigned Fraction::minCommonMultiple(unsigned a, unsigned b)
{
	return a*b / maxCommonDivisor(a, b);
}

ostream& operator<<(ostream &os, const Fraction &fraction)
{
	os << fraction.m_iMolecule << '/' << fraction.m_iDenominator;
	return os;
}

istream& operator>>(istream &is, Fraction &fraction)
{
	static char ch;
	is >> fraction.m_iMolecule >> ch >> fraction.m_iDenominator;
	return is;
}

Fraction generate()
{
	long molecule = rand() % 100;
	long denominator = rand() % 100 + 1;
	if (rand() % 2)
		molecule = -molecule;
	return Fraction(molecule, denominator);
}

int main()
{
	srand((unsigned)time(NULL));
	Fraction left = generate(), right = generate(), buff, result;
	switch (2)//rand() % 4)
	{
	case 0:
		buff = left + right;
		cout << left << " + " << right << " = ";
		break;
	case 1:
		buff = left - right;
		cout << left << " - " << right << " = ";
		break;
	case 2:
		buff = left*right;
		cout << left << " * " << right << " = ";
		break;
	case 3:
		buff = left / right;
		cout << left << " / " << right << " = ";
		break;
	}
	cin >> result;
	if (result == buff)
		cout << "回答正确\n";
	else
		cout << "回答错误\n";
	return 0;
}