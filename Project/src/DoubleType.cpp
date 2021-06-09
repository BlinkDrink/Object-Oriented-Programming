#include <iostream>
#include <string>
#include <cmath>
#include "../include/DoubleType.h"

using std::cout;
using std::string;
using std::to_string;

DoubleType::DoubleType(const string &data)
{
	m_value = stod(data);
}

void DoubleType::print() const
{
	cout << toString();
}

double DoubleType::toDouble() const
{
	return m_value;
}

DoubleType *DoubleType::clone() const
{
	return new DoubleType(*this);
}

size_t DoubleType::size() const
{
	size_t len = 0;
	len += log10(m_value) + 1;
	if (m_value < 0)
		len++;

	return len;
}

string DoubleType::toFileFormat() const
{
	return toString();
}

string DoubleType::toString() const
{
	return to_string(m_value);
}

double DoubleType::operator+(const CellType &other) const
{
	double result = 0;
	result = m_value + other.toDouble();
	return result;
}

double DoubleType::operator-(const CellType &other) const
{
	double result = 0;
	result = m_value - other.toDouble();
	return result;
}

double DoubleType::operator*(const CellType &other) const
{
	double result = 0;
	result = m_value * other.toDouble();
	return result;
}

double DoubleType::operator/(const CellType &other) const
{
	double result = 0;
	result = m_value / other.toDouble();
	return result;
}

double DoubleType::operator^(const CellType &other) const
{
	double result = 0;
	result = pow(m_value, other.toDouble());
	return result;
}