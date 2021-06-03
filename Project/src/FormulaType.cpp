#include<iostream>
#include "FormulaType.h"
#include "StringHelper.h"

using std::cout;
using std::invalid_argument;
using std::to_string;

FormulaType::FormulaType(const string& equation) {
	if (!isFormulaValid()) {
		throw invalid_argument("Invalid formula.");
	}

	m_data = equation;
	m_data = to_string(calculateFormula());
}

bool FormulaType::isFormulaValid() const {
	return true;
}


//vector<string> FormulaType::splitBy(string& delimeter) {
//	vector<string> words;
//	string cpy = m_data;
//	cpy.erase(cpy.begin());
//	size_t pos = 0;
//
//	while ((pos = cpy.find(delimeter)) != string::npos) {
//		words.push_back(cpy.substr(0, pos));
//		cpy.erase(0, pos + delimeter.length());
//	}
//	words.push_back(cpy);
//
//	return words;
//}

double FormulaType::calculateFormula() {
	StringHelper sh;
	string cpy = m_data;
	cpy.erase(cpy.begin());

	sh.trim(cpy);
	vector<string> parts = sh.splitBy(cpy, " ");

	while (containsMultiplication(parts))
	{
		for (size_t i = 0; i < parts.size(); i++)
		{
			if (parts[i] == "*")
			{
				parts[i - 1] = std::to_string(stod(parts[i - 1]) * stod(parts[i + 1]));
				parts.erase(parts.begin() + i);
				parts.erase(parts.begin() + i);
				break;
			}
		}
	}

	while (containsDivision(parts))
	{
		for (size_t i = 0; i < parts.size(); i++)
		{
			if (parts[i] == "/")
			{
				parts[i - 1] = std::to_string(stod(parts[i - 1]) / stod(parts[i + 1]));
				parts.erase(parts.begin() + i);
				parts.erase(parts.begin() + i);
				break;
			}
		}
	}

	while (containsAditionOrSubtraction(parts))
	{
		for (size_t i = 0; i < parts.size(); i++)
		{
			if (parts[i] == "+")
			{
				parts[i - 1] = std::to_string(stod(parts[i - 1]) + stod(parts[i + 1]));
				parts.erase(parts.begin() + i);
				parts.erase(parts.begin() + i);
				break;
			}
			else if (parts[i] == "-")
			{
				parts[i - 1] = std::to_string(stod(parts[i - 1]) - stod(parts[i + 1]));
				parts.erase(parts.begin() + i);
				parts.erase(parts.begin() + i);
				break;
			}
		}
	}

	return stod(parts[0]);
}

bool FormulaType::containsMultiplication(const vector<string>& parts) const {
	for (size_t i = 0; i < parts.size(); i++)
	{
		if (parts[i] == "*")
		{
			return true;
		}
	}

	return false;
}

bool FormulaType::containsDivision(const vector<string>& parts) const {
	for (size_t i = 0; i < parts.size(); i++)
	{
		if (parts[i] == "/")
		{
			return true;
		}
	}

	return false;
}

bool FormulaType::containsAditionOrSubtraction(const vector<string>& parts) const {
	for (size_t i = 0; i < parts.size(); i++)
	{
		if (parts[i] == "+" || parts[i] == "-")
		{
			return true;
		}
	}

	return false;
}

void FormulaType::print() const {
	cout << m_data;
}

FormulaType* FormulaType::clone() const
{
	return new FormulaType(*this);
}

DataType FormulaType::getDataType() const
{
	return DataType::FORMULA;
}

string FormulaType::getRawData() const {
	return m_data;
}
