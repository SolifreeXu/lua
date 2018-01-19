#pragma once

#include <iostream>

class Complex
{
	double realPart;
	double imaginaryPart;

	friend Complex operator + (double dNumber, const Complex &complex)
	{
		return Complex(dNumber + complex.realPart, complex.imaginaryPart);
	}
	friend std::ostream & operator <<(std::ostream &output, const Complex &complex);
	friend std::istream & operator >>(std::istream &input, Complex &complex);
public:
	Complex(const double real = 0, const double imag = 0)
	{
		realPart = real; imaginaryPart = imag;
	}
	Complex operator +(const Complex &other) const;
	Complex operator -(const Complex &other) const;
	Complex& operator +=(const Complex &other);
	Complex& operator -=(const Complex &other);
	Complex operator *(const Complex &other) const;
	Complex operator /(const Complex &other) const;
	Complex& operator *=(const Complex &other);
	Complex& operator /=(const Complex &other);
};