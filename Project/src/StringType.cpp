#include <iostream>
#include <cmath>
#include "../include/StringType.h"
#include "../include/StringHelper.h"

using std::cout;

StringType::StringType(const string &str)
{
	m_value = str;
}

void StringType::print() const
{
	cout << toString();
}

StringType *StringType::clone() const
{
	return new StringType(*this);
}

string StringType::toFileFormat() const
{
	return '"' + m_value + '"';
}

string StringType::toString() const
{
	return m_value;
}

double StringType::toDouble() const
{
	StringHelper sh;
	if (sh.isStringDouble(m_value) || sh.isStringInteger(m_value))
	{
		return stod(m_value);
	}

	return 0;
}

size_t StringType::size() const
{
	return m_value.size();
}

double StringType::operator+(const CellType &other) const
{
	return toDouble() + other.toDouble();
}

double StringType::operator-(const CellType &other) const
{
	return toDouble() - other.toDouble();
}

double StringType::operator*(const CellType &other) const
{
	return toDouble() * other.toDouble();
}

double StringType::operator/(const CellType &other) const
{
	return toDouble() / other.toDouble();
}

double StringType::operator^(const CellType &other) const
{
	return pow(toDouble(), other.toDouble());
}