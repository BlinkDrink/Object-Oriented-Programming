#include <iostream>
#include "../include/IntegerType.h"

using std::cout;

IntegerType::IntegerType(long long value, Sign s)
{
	m_integer = value;
	m_sign = s;
}

void IntegerType::print() const
{
	char sign = (int)m_sign != 0 ? (int)m_sign != 1 ? ' ' : '-' : '+';
	cout << sign << m_integer;
}

DataType IntegerType::getType() const
{
	return DataType::INTEGER;
}

void IntegerType::setType(DataType type)
{
	m_type = type;
}

IntegerType *IntegerType::clone() const
{
	return new IntegerType(*this);
}

long long IntegerType::getNumber() const
{
	return m_integer;
}

void IntegerType::setNumber(long long value)
{
	if (value > 0)
		m_sign = Sign::PLUS;
	else if (value < 0)
		m_sign = Sign::MINUS;
	else
		m_sign = Sign::NONE;

	m_integer = value;
}
