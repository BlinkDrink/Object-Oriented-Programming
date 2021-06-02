#include "IntegerType.h"
#include<iostream>
#include<string>

using std::cout;
using std::string;
using std::to_string;

IntegerType::IntegerType(long long value, Sign s) {
	m_integer = value;
	m_sign = s;
}

void IntegerType::print() const {
	string sign;
	if (m_sign == Sign::PLUS)
	{
		sign = '+';
	}
	else if (m_sign == Sign::MINUS)
	{
		sign = '-';
	}

	cout << sign << m_integer;
}

void IntegerType::setNumber(long long value) {
	if (value > 0)
		m_sign = Sign::PLUS;
	else if (value < 0)
		m_sign = Sign::MINUS;
	else
		m_sign = Sign::NONE;

	m_integer = value;
}

DataType IntegerType::getType() const {
	return DataType::INTEGER;
}

long long IntegerType::getNumber() const {
	return m_integer;
}

IntegerType* IntegerType::clone() const
{
	return new IntegerType(*this);
}

bool IntegerType::hasSign() const {
	if (m_sign != Sign::NONE)
	{
		return true;
	}

	return false;
}

size_t IntegerType::getNumberLength() const {
	size_t len = 0;

	string integerAsString = to_string(m_integer);
	if (hasSign())
		len = integerAsString.size() + 1;
	else
		len = integerAsString.size();

	return len;
}