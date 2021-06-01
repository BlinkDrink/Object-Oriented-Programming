#include "FormulaType.h"
#include<iostream>

using std::cout;
using std::invalid_argument;

FormulaType::FormulaType(const string& equation) : m_formula(equation) {
	if (!isFormulaValid()) {
		throw invalid_argument("Invalid formula.");
	}
}

bool FormulaType::isFormulaValid() const {
	return true;
}

double FormulaType::calculateFormula() {
	string delimeter = " ";
	vector<string> parts = splitBy(delimeter);

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
	cout << m_value;
}

Type* FormulaType::clone() const
{
	return new FormulaType(*this);
}

DataType FormulaType::getType() const
{
	return DataType::FORMULA;
}

void FormulaType::setType(DataType type)
{
}

vector<string> FormulaType::splitBy(string& delimeter) {
	vector<string> words;
	string cpy = m_formula;
	cpy.erase(cpy.begin());
	size_t pos = 0;

	while ((pos = cpy.find(delimeter)) != string::npos) {
		words.push_back(cpy.substr(0, pos));
		cpy.erase(0, pos + delimeter.length());
	}
	words.push_back(cpy);

	return words;
}
