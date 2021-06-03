#include<iostream>
#include<string>
#include "./DoubleType.h"
using std::string;
using std::invalid_argument;
using std::cout;

DoubleType::DoubleType(const string& data) {
	if (!validateData(data))
	{
		throw invalid_argument("Invalid real number.");
	}

	m_data = data;
}

bool DoubleType::validateData(const string& data) const {
	size_t numberOfDots = 0;
	for (size_t i = 0; i < data.size(); i++)
	{
		if (data[i] == '.')
		{
			numberOfDots++;
		}

		if (numberOfDots >= 2)
		{
			return false;
		}

		if (data[i] == '=')
		{
			return false;
		}
	}

	return true;
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