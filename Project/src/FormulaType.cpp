#include <iostream>
#include <cmath>
#include "../include/FormulaType.h"
#include "../include/StringHelper.h"

using std::cout;
using std::invalid_argument;
using std::to_string;

FormulaType::FormulaType(const string &equation)
{
	m_value = equation;
}

void FormulaType::print() const
{
	StringHelper sh;
	cout << sh.calculateEquationInString(m_value);
}

FormulaType *FormulaType::clone() const
{
	return new FormulaType(*this);
}

double FormulaType::toDouble() const
{
	return m_calculated;
}

string FormulaType::toString() const
{
	return m_value;
}

size_t FormulaType::size() const
{
	size_t len = 0;
	len += log10(m_calculated) + 1;
	if (m_calculated < 0)
		len++;

	return len;
}

double FormulaType::operator+(const CellType *other) const
{
	return toDouble() + other->toDouble();
}

double FormulaType::operator-(const CellType *other) const
{
	return toDouble() - other->toDouble();
}

double FormulaType::operator*(const CellType *other) const
{
	return toDouble() * other->toDouble();
}

double FormulaType::operator/(const CellType *other) const
{
	return toDouble() / other->toDouble();
}

double FormulaType::operator^(const CellType *other) const
{
	return pow(toDouble(), other->toDouble());
}
