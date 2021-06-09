#include <iostream>
#include <cmath>
#include "../include/FormulaType.h"
#include "../include/StringHelper.h"

using std::cout;
using std::invalid_argument;
using std::to_string;

double FormulaType::applyOperator(StringType &a, StringType &b, char op) const
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	case '^':
		return a ^ b;
	}

	return 0;
}

size_t FormulaType::precedence(char op) const
{
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	if (op == '^')
		return 3;

	return 0;
}

double FormulaType::calculateFormula() const
{
	StringHelper sh;
	string cpy(m_value);
	cpy.erase(cpy.begin());
	sh.addSpaceInBetweenWords(cpy);
	sh.trim(cpy);
	vector<string> parts = sh.splitBy(cpy, " ");
	sh.removeEmptyStringsInVector(parts);

	vector<StringType> values;
	vector<char> operators;

	for (size_t i = 0; i < parts.size(); i++)
	{
		sh.trim(parts[i]);
		if (parts[i] == " ")
		{
			continue;
		}
		else if (parts[i] == "(")
		{
			operators.push_back(parts[i].back());
		}
		else if (sh.isStringDouble(parts[i]) || sh.isStringInteger(parts[i]))
		{
			values.push_back(parts[i]);
		}
		else if (parts[i] == ")")
		{
			while (!operators.empty() && operators.back() != '(')
			{
				StringType val2 = values.back();
				values.back();

				StringType val1 = values.back();
				values.back();

				char op = operators.back();
				operators.back();

				values.push_back(to_string(applyOperator(val1, val2, op)));
			}

			if (!operators.empty())
				operators.pop_back();
		}
		else
		{
			while (!operators.empty() && precedence(operators.back()) >= precedence(parts[i].back()))
			{
				StringType val2 = values.back();
				values.pop_back();

				StringType val1 = values.back();
				values.pop_back();

				char op = operators.back();
				operators.pop_back();

				values.push_back(to_string(applyOperator(val1, val2, op)));
			}

			operators.push_back(parts[i].back());
		}
	}

	while (!operators.empty())
	{
		StringType val2 = values.back();
		values.pop_back();

		StringType val1 = values.back();
		values.pop_back();

		char op = operators.back();
		operators.pop_back();

		values.push_back(to_string(applyOperator(val1, val2, op)));
	}

	return values.back().toDouble();
}

FormulaType::FormulaType(const string &equation) : m_value(equation)
{
}

void FormulaType::print() const
{
	cout << m_calculated;
}

FormulaType *FormulaType::clone() const
{
	return new FormulaType(*this);
}

double FormulaType::toDouble() const
{
	return calculateFormula();
}

string FormulaType::toString() const
{
	return m_value;
}

size_t FormulaType::size() const
{
	size_t len = 0;
	len += log10(m_calculated) + 1;
	if (m_calculated < 0)
		len++;

	return len;
}

double FormulaType::operator+(const CellType &other) const
{
	return toDouble() + other.toDouble();
}

double FormulaType::operator-(const CellType &other) const
{
	return toDouble() - other.toDouble();
}

double FormulaType::operator*(const CellType &other) const
{
	return toDouble() * other.toDouble();
}

double FormulaType::operator/(const CellType &other) const
{
	return toDouble() / other.toDouble();
}

double FormulaType::operator^(const CellType &other) const
{
	return pow(toDouble(), other.toDouble());
}
