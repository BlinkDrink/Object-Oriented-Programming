#include<iostream>
#include "FormulaType.h"
#include "StringHelper.h"

using std::cout;
using std::invalid_argument;
using std::to_string;

FormulaType::FormulaType(const string& equation) {
	m_data = equation;
}

void FormulaType::print() const {
	StringHelper sh;
	cout << sh.calculateEquationInString(m_data);
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
