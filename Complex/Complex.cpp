#include "Complex.h"

Complex Complex::operator+(const Complex &other) const
{
	return Complex(this->realPart + other.realPart, this->imaginaryPart + other.imaginaryPart);
}

Complex Complex::operator-(const Complex &other) const
{
	return Complex(this->realPart - other.realPart, this->imaginaryPart - other.imaginaryPart);
}

Complex& Complex::operator+=(const Complex &other)
{
	this->realPart += other.realPart;
	this->imaginaryPart += other.imaginaryPart;
	return *this;
}

Complex& Complex::operator-=(const Complex &other)
{
	this->realPart -= other.realPart;
	this->imaginaryPart -= other.imaginaryPart;
	return *this;
}

Complex Complex::operator*(const Complex &other) const
{
	return Complex(this->realPart*other.realPart - this->imaginaryPart*other.imaginaryPart, \
		this->realPart*other.imaginaryPart + this->imaginaryPart*other.realPart);
}

Complex Complex::operator/(const Complex &other) const
{
	double denominator = other.realPart*other.realPart + other.imaginaryPart*other.imaginaryPart;
	return Complex((this->realPart*other.realPart + this->imaginaryPart*other.imaginaryPart) / denominator, \
		(-this->realPart*other.imaginaryPart + this->imaginaryPart*other.realPart) / denominator);
}

Complex& Complex::operator*=(const Complex &other)
{
	return *this = Complex(this->realPart*other.realPart - this->imaginaryPart*other.imaginaryPart, \
		this->realPart*other.imaginaryPart + this->imaginaryPart*other.realPart);
}

Complex& Complex::operator/=(const Complex &other)
{
	double denominator = other.realPart*other.realPart + other.imaginaryPart*other.imaginaryPart;
	return *this = Complex((this->realPart*other.realPart + this->imaginaryPart*other.imaginaryPart) / denominator, \
		(-this->realPart*other.imaginaryPart + this->imaginaryPart*other.realPart) / denominator);
}

std::ostream & operator <<(std::ostream &output, const Complex &complex)
{
	if (complex.imaginaryPart > 0)
		output << complex.realPart << '+' << complex.imaginaryPart << 'i';
	else if (complex.imaginaryPart == 0)
		output << complex.realPart;
	else
		output << complex.realPart << complex.imaginaryPart << 'i';
	return output;
}

std::istream & operator >>(std::istream &input, Complex &complex)
{
	return input >> complex.realPart >> complex.imaginaryPart;
}