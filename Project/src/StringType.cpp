#include "StringType.h"
#include <iostream>

using std::cout;

StringType::StringType(const string& str) {
	m_string = str;
}

void StringType::print() const
{
	cout << m_string;
}

StringType* StringType::clone() const
{
	return new StringType(*this);
}

DataType StringType::getType() const
{
	return DataType::STRING;
}

string StringType::getString() const {
	return m_string;
}