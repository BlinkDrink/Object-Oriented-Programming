#include "DoubleType.h"
#include<iostream>
#include<string>

using std::string;
using std::to_string;
using std::cout;

DoubleType::DoubleType(double real, Sign sign) : m_real(real), m_sign(sign) {

}

void DoubleType::print() const {
	char sign = (int)m_sign != 0 ? (int)m_sign != 1 ? ' ' : '-' : '+';
	string doubleAsString(to_string(m_real));

	cout << sign << doubleAsString;
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

DoubleType* DoubleType::clone() const
{
	return new DoubleType(*this);
}
