#include "StringType.h"
#include <iostream>

using std::cout;

StringType::StringType(const string& str) {
	m_data = str;
}

void StringType::print() const
{
	cout << m_data;
}

StringType* StringType::clone() const
{
	return new StringType(*this);
}

DataType StringType::getDataType() const
{
	return DataType::STRING;
}

string StringType::getRawData() const {
	return m_data;
}