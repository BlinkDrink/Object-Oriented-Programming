#include<iostream>
#include<string>
#include "IntegerType.h"

using std::cout;
using std::string;
using std::to_string;

IntegerType::IntegerType(const string& data) {
	m_data = data;
}

void IntegerType::print() const {
	cout << m_data;
}

DataType IntegerType::getDataType() const {
	return DataType::INTEGER;
}

IntegerType* IntegerType::clone() const
{
	return new IntegerType(*this);
}

string IntegerType::getRawData() const {
	return m_data;
}