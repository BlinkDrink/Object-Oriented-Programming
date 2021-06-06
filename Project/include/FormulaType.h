#pragma once
#include<string>
#include<vector>
#include "CellType.h"

using std::string;
using std::vector;

class FormulaType : public CellType {
public:
	/*
	*	@brief Initializes m_formula with given string
	*
	*	@param equation - string to be initialized with
	*/
	FormulaType(const string& equation);

	/*
	*	@brief Prints the formula result on the console
	*/
	virtual void print() const;

	/*
	*	@brief Creates dynamically allocated copy of this object
	*
	*	@returns The newly allocated FormulaType* object
	*/
	virtual FormulaType* clone() const override;

	/*
	*	@returns the DataType of the current object
	*/
	virtual DataType getDataType() const override;

	/*
	*	@brief Getter
	*
	*	@returns raw string format of formula after calculation
	*/
	virtual string getRawData() const override;
};