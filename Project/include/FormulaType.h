#pragma once
#include "Type.h"
#include<string>
#include<vector>

using std::string;
using std::vector;

class FormulaType : public Type {
private:
	string m_formula;
	double m_calculated = 0;

	/*
	*	@brief Splits m_formula string by delimeter and puts the tokens in a vector of strings
	*
	*	@param delimeter - desired delimeter to split by
	*	@returns vector<string> filled with tokens
	*/
	vector<string> splitBy(string& delimeter);

	/*
	*	@brief Checks if a vector of strings contains multiplication sign
	*
	*	@param parts - vector of strings to check
	*	@returns true if vector contains '*', false otherwise
	*/
	bool containsMultiplication(const vector<string>& parts) const;

	/*
	*	@brief Checks if a vector of strings contains division sign
	*
	*	@param parts - vector of strings to check
	*	@returns true if vector contains '/', false otherwise
	*/
	bool containsDivision(const vector<string>& parts) const;

	/*
	*	@brief Checks if a vector of strings contains adition or subraction signs
	*
	*	@param parts - vector of strings to check
	*	@returns true if vector contains '+' or '-', false otherwise
	*/
	bool containsAditionOrSubtraction(const vector<string>& parts) const;

	/*
	*	@brief Checks if m_formula is a valid formula
	*
	*	@returns true if valid, false otherwise
	*/
	bool isFormulaValid() const;
public:
	/*
	*	@brief Initializes m_formula with given string
	*
	*	@param equation - string to be initialized with
	*/
	FormulaType(const string& equation);

	/*
	*	@brief Calculates the given formula(m_formula)
	*
	*	@returns the calculated result as double
	*/
	double calculateFormula();

	/*
	*	@brief Prints the formula result on the console
	*/
	virtual void print() const;

	/*
	*	@brief Creates dynamically allocated copy of this object
	*
	*	@returns The newly allocated FormulaType* object
	*/
	virtual Type* clone() const override;

	/*
	*	@returns the DataType of the current object
	*/
	virtual DataType getType() const override;

	/*
	*	@brief Getter
	*
	*	@returns the calculated formula as double
	*/
	double getCaluclatedFormula() const;

	/*
	*	@brief Gets the length of the calculated number
	*
	*	@returns the length of the number
	*/
	size_t getLengthOfNumber() const;
};