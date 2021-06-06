#pragma once
#include "CellType.h"

class IntegerType : public CellType
{
public:
	/*
	*	@brief Initializes IntegerType with given value and sign
	*
	*	@param data - string to be initialized with
	*/
	IntegerType(const string& data);

	/*
	*	@brief prints m_integer and m_sign on the console
	*/
	virtual void print() const override;

	/*
	*	@returns the DataType of the current object
	*/
	virtual DataType getDataType() const override;

	/*
	*	@brief Creates dynamically allocated copy of this object
	*
	*	@returns The newly allocated IntegerType* object
	*/
	virtual IntegerType* clone() const override;

	/*
	*	@brief Getter
	*
	*	@returns Integer as string
	*/
	virtual string getRawData() const override;
};