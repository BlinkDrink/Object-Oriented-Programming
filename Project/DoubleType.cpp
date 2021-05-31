#include "DoubleType.h"
#include<iostream>

using std::cout;

void DoubleType::print() const {
	char sign = (int)m_sign != 0 ? (int)m_sign != 1 ? ' ' : '-' : '+';
	cout << sign << m_real;
}

void DoubleType::setNumber(double value) {
	if (value > 0)
		m_sign = Sign::PLUS;
	else if (value < 0)
		m_sign = Sign::MINUS;
	else
		m_sign = Sign::NONE;

	m_real = value;
}

double DoubleType::getNumber() const {
	return m_real;
}

DataType DoubleType::getType() const {
	return DataType::DOUBLE;
}

void DoubleType::setType(DataType type) {
	m_type = type;
}