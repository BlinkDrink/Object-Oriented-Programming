#include<iostream>
#include<string>
#include "./DoubleType.h"
using std::string;
using std::invalid_argument;
using std::cout;

DoubleType::DoubleType(const string& data) {
	m_data = data;
}

void DoubleType::print() const {
	cout << m_data;
}

DataType DoubleType::getDataType() const {
	return DataType::DOUBLE;
}

DoubleType* DoubleType::clone() const
{
	return new DoubleType(*this);
}

string DoubleType::getRawData() const {
	return m_data;
}