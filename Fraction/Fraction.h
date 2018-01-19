#pragma once

#include <iostream>

class Fraction
{
	long m_iMolecule;
	long m_iDenominator;

	friend std::ostream& operator<<(std::ostream &os, const Fraction &fraction);
	friend std::istream& operator>>(std::istream &is, Fraction &fraction);
public:
	Fraction(long molecule = 0, long denominator = 1) \
		:m_iMolecule(molecule), m_iDenominator(denominator){}
	Fraction(const Fraction &fraction) \
		:m_iMolecule(fraction.m_iMolecule), m_iDenominator(fraction.m_iDenominator){}
	Fraction operator+(Fraction fraction) const;
	Fraction operator-(Fraction fraction) const;
	Fraction operator*(Fraction fraction) const;
	Fraction operator/(Fraction fraction) const;
	bool operator==(const Fraction &fraction) const;
	Fraction& operator=(Fraction &&fraction);
	operator double(){ return (double)m_iMolecule / m_iDenominator; }
	static unsigned maxCommonDivisor(unsigned first, unsigned second);
	static unsigned minCommonMultiple(unsigned first, unsigned second);
};
