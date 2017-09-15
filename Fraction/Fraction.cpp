#include "Fraction.h"

using std::ostream;
using std::istream;

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
	fraction.m_iMolecule /= (long)commonNumber;
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
	fraction.m_iMolecule = 0;
	fraction.m_iDenominator = 1;
	return *this;
}

unsigned Fraction::maxCommonDivisor(unsigned a, unsigned b)
{
	if (a < b)	//��aС��b��ʵ����ֵ����
	{
		a ^= b;
		b ^= a;
		a ^= b;
	}
	unsigned c = a%b;	//a��bȡ�ำ��c
	while (c != 0)	//��c��Ϊ0ʱִ��ѭ�������
	{
		a = b;	//��b����a
		b = c;	//��c��ֵ����b
		c = a%b;	//����ȡ�ಢ����c
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