#include "ErrorType.h"
#include<iostream>

ErrorType::ErrorType()
{
	m_data = "#ERROR";
}

void ErrorType::print() const
{
	std::cout << m_data;
}

ErrorType* ErrorType::clone() const
{
	return new ErrorType(*this);
}

DataType ErrorType::getDataType() const
{
	return DataType::ERROR_TYPE;
}

string ErrorType::getRawData() const
{
	return m_data;
}
