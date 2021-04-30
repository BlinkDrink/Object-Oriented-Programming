#pragma once
#include <iostream>
struct ComplexNumber {
	double real;
	double imaginary;
};

void addComplexNumbers(ComplexNumber* res, ComplexNumber* c1, ComplexNumber* c2);

void multiplyComplexNumbers(ComplexNumber* res, ComplexNumber* c1, ComplexNumber* c2);

void printComplexNumber(ComplexNumber* c);