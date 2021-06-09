#include <iostream>
#include <cmath>
#include <string>
#include "../include/StringHelper.h"
#include "../include/IntegerType.h"

using std::cout;
using std::string;
using std::to_string;

IntegerType::IntegerType(const string &data)
{
	m_value = stoi(data);
}

void IntegerType::print() const
{
	cout << m_value;
}

IntegerType *IntegerType::clone() const
{
	return new IntegerType(*this);
}

size_t IntegerType::size() const
{
	size_t len = 0;
	long long tmp = m_value;
	while (tmp != 0)
	{
		tmp /= 10;
		len++;
	}

	if (m_value < 0)
		len++;

	return len;
}

string IntegerType::toFileFormat() const
{
	return toString();
}

double IntegerType::toDouble() const
{
	return m_value;
}

string IntegerType::toString() const
{
	return to_string(m_value);
}

double IntegerType::operator+(const CellType &other) const
{
	double result = 0;
	result = m_value + other.toDouble();
	return result;
}

double IntegerType::operator-(const CellType &other) const
{
	double result = 0;
	result = m_value - other.toDouble();
	return result;
}

double IntegerType::operator*(const CellType &other) const
{
	double result = 0;
	result = m_value * other.toDouble();
	return result;
}

double IntegerType::operator/(const CellType &other) const
{
	double result = 0;
	result = m_value / other.toDouble();
	return result;
}

double IntegerType::operator^(const CellType &other) const
{
	double result = 0;
	result = pow(m_value, other.toDouble());
	return result;
}