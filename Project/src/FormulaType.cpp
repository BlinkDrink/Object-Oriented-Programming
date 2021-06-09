#include <iostream>
#include <cmath>
#include "../include/FormulaType.h"
#include "../include/StringHelper.h"

using std::cout;
using std::invalid_argument;
using std::queue;
using std::stack;
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

double FormulaType::shunting_yard(const vector<string> &tokens) const
{
	queue<StringType> output;
	stack<char> operators;

	StringHelper sh;
	for (size_t i = 0; i < tokens.size(); i++)
	{
		string cpy(tokens[i]);
		sh.trim(cpy);

		if (cpy == " ")
		{
			continue;
		}
		else if (cpy == "(")
		{
			operators.push(cpy.back());
		}
		// Push numbers onto the queue
		else if (sh.isStringDouble(cpy) || sh.isStringInteger(cpy))
		{
			output.push(cpy);
		}
		// If we encounter a right parenthesis, keep popping operators until seeing left parenthesis
		else if (cpy == ")")
		{
			while (!operators.empty() && operators.top() != '(')
			{
				string op;
				op += operators.top();
				operators.pop();

				output.push(op);
			}

			// Pop the remaining parenthesis
			if (!operators.empty())
				operators.pop();
		}
		// Last option is operator, check for operator precedence and adjust stack accordingly
		else
		{
			while (!operators.empty() && precedence(operators.top()) >= precedence(cpy.back()))
			{
				string op;
				op += operators.top();
				operators.pop();

				output.push(op);
			}

			operators.push(cpy.back());
		}
	}

	// Add remaining operators at the end of the queue
	while (!operators.empty())
	{
		string op;
		op += operators.top();
		operators.pop();

		output.push(op);
	}

	return postfix_equation(output);
}

double FormulaType::postfix_equation(queue<StringType> &output) const
{
	StringHelper sh;
	stack<StringType> result;
	while (!output.empty())
	{
		if (sh.isStringDouble(output.front().toString()) || sh.isStringInteger(output.front().toString()))
		{
			result.push(output.front());
			output.pop();
		}
		else
		{
			StringType val2 = result.top();
			result.pop();

			StringType val1 = result.top();
			result.pop();

			StringType op = output.front();
			char oper = op.toString().back();
			output.pop();

			result.push(to_string(applyOperator(val1, val2, oper)));
		}
	}

	return result.top().toDouble();
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

	for (size_t i = 0; i < parts.size(); i++)
	{
		if (sh.isStringValidCellAddress(parts[i]))
		{
			Pair<size_t, size_t> pair = sh.extractCellAddressDetails(parts[i]);
			parts[i] = to_string(m_table[pair.key][pair.value].getContentAsDouble());
		}
	}

	return shunting_yard(parts);
}

FormulaType::FormulaType(const string &equation, const Table &table_ref) : m_value(equation), m_table(table_ref)
{
}

void FormulaType::print() const
{
	cout << calculateFormula();
}

FormulaType *FormulaType::clone() const
{
	return new FormulaType(*this);
}

string FormulaType::toFileFormat() const
{
	return m_value;
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
	double res = calculateFormula();
	len += log10(res) + 1;
	if (res < 0)
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
