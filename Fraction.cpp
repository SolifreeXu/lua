#include "Fraction.h"

using std::ostream;
using std::istream;

ostream& operator<<(ostream &os, const Fraction &fraction)
{
	os << fraction.m_iMolecule << '/' << fraction.m_iDenominator;
	return os;
}

istream& operator>>(istream &is, Fraction &fraction)
{
	char ch;
	is >> fraction.m_iMolecule >> ch >> fraction.m_iDenominator;
	return is;
}

#include <cmath>

Fraction Fraction::operator+(Fraction fraction) const
{
	long commonNumber = minCommonMultiple(this->m_iDenominator, fraction.m_iDenominator);
	fraction.m_iMolecule *= commonNumber / fraction.m_iDenominator;
	fraction.m_iMolecule += commonNumber / this->m_iDenominator*this->m_iMolecule;
	fraction.m_iDenominator = commonNumber;
	commonNumber = maxCommonDivisor(abs(fraction.m_iMolecule), fraction.m_iDenominator);
	fraction.m_iMolecule /= commonNumber;
	fraction.m_iDenominator /= commonNumber;
	return fraction;
}

Fraction Fraction::operator-(Fraction fraction) const
{
	long commonNumber = minCommonMultiple(this->m_iDenominator, fraction.m_iDenominator);
	fraction.m_iMolecule *= commonNumber / fraction.m_iDenominator;
	fraction.m_iMolecule = commonNumber / this->m_iDenominator*this->m_iMolecule - fraction.m_iMolecule;
	fraction.m_iDenominator = commonNumber;
	commonNumber = maxCommonDivisor(abs(fraction.m_iMolecule), fraction.m_iDenominator);
	fraction.m_iMolecule /= commonNumber;
	fraction.m_iDenominator /= commonNumber;
	return fraction;
}

Fraction Fraction::operator*(Fraction fraction) const
{
	fraction.m_iMolecule *= this->m_iMolecule;
	fraction.m_iDenominator *= this->m_iDenominator;
	long commonNumber = maxCommonDivisor(abs(fraction.m_iMolecule), fraction.m_iDenominator);
	fraction.m_iMolecule /= commonNumber;
	fraction.m_iDenominator /= commonNumber;
	return fraction;
}

Fraction Fraction::operator/(Fraction fraction) const
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

bool Fraction::operator==(const Fraction &fraction) const
{
	return this->m_iMolecule == fraction.m_iMolecule \
		&& this->m_iDenominator == fraction.m_iDenominator;
}

Fraction& Fraction::operator=(Fraction &&fraction)
{
	this->m_iMolecule = fraction.m_iMolecule;
	this->m_iDenominator = fraction.m_iDenominator;
	fraction.m_iMolecule = 0;
	fraction.m_iDenominator = 1;
	return *this;
}

unsigned Fraction::maxCommonDivisor(unsigned first, unsigned second)
{
	if (first < second)	//��aС��bʱʵ����ֵ����
	{
		first ^= second;
		second ^= first;
		first ^= second;
	}
	unsigned temp = first%second;	//a��bȡ�ำ��c
	while (temp != 0)	//��c��Ϊ0ʱִ��ѭ�������
	{
		first = second;	//��b����a
		second = temp;	//��c��ֵ����b
		temp = first%second;	//����ȡ�ಢ����c
	}
	return second;
}

unsigned Fraction::minCommonMultiple(unsigned first, unsigned second)
{
	return first / maxCommonDivisor(first, second)*second;
}
