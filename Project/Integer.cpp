#include "IntegerType.h"
#include<iostream>

using std::cout;

void IntegerType::print() const {
	char sign = (int)m_sign != 0 ? (int)m_sign != 1 ? ' ' : '-' : '+';
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

void IntegerType::setType(DataType type) {
	m_type = type;
}
