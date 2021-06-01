#pragma once
#include "Type.h"
#include<string>
#include<vector>

using std::string;
using std::vector;

class FormulaType : public Type {
private:
	string m_formula;
	double m_value = 0;

	vector<string> splitBy(string& delimeter);
	bool containsMultiplication(const vector<string>& parts) const;
	bool containsDivision(const vector<string>& parts) const;
	bool containsAditionOrSubtraction(const vector<string>& parts) const;
	bool isFormulaValid() const;
public:
	FormulaType(const string& equation);
	double calculateFormula();

	virtual void print() const;
	virtual Type* clone() const override;
	virtual DataType getType() const override;
	virtual void setType(DataType type) override;
};