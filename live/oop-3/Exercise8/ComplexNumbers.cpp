#include "ComplexNumber.h"

using std::cout;

void addComplexNumbers(ComplexNumber* result, ComplexNumber* c1, ComplexNumber* c2)
{
	result->real = c1->real + c2->real;
	result->imaginary = c1->imaginary + c2->imaginary;
}

void multiplyComplexNumbers(ComplexNumber* result, ComplexNumber* c1, ComplexNumber* c2)
{
	double realPart = c1->real * c2->real - (c1->imaginary * c2->imaginary);
	double imaginaryPart = c1->real * c2->imaginary + (c2->real * c1->imaginary);

	result->real = realPart;
	result->imaginary = imaginaryPart;
}

void printComplexNumber(ComplexNumber* c) {
	cout << c->real << (c->imaginary > 0 ? "+" : "") << c->imaginary << 'i';
}

