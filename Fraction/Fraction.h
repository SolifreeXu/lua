#include <iostream>

class Fraction
{
	long m_iMolecule;
	long m_iDenominator;
	friend std::ostream& operator<<(std::ostream &os, const Fraction &fraction);
	friend std::istream& operator>>(std::istream &is, Fraction &fraction);
public:
	Fraction() :m_iMolecule(0), m_iDenominator(1){}
	Fraction(long molecule, long denominator) :m_iMolecule(molecule), m_iDenominator(denominator){}
	Fraction(long nNumber) :m_iMolecule(nNumber), m_iDenominator(1){}
	Fraction(const Fraction &fraction) :m_iMolecule(fraction.m_iMolecule), m_iDenominator(fraction.m_iDenominator){}
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