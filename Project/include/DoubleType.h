#pragma once
#include<iostream>
#include<string>
#include "CellType.h"

class DoubleType : public CellType {
public:
	/*
	*	@brief Initializes DoubleType object with given parameter
	*
	*	@param data - string object with which DoubleType will be initialized
	*/
	DoubleType(const string& data);

	/*
	*	@brief prints the real number on the console
	*/
	virtual void print() const override;

	/*
	*	@returns the DataType of the current object
	*/
	virtual DataType getDataType() const override;

	/*
	*	@brief Creates dynamically allocated copy of this object
	*
	*	@returns The newly allocated DoubleType* object
	*/
	virtual DoubleType* clone() const override;

	/*
	*	@brief Getter
	*
	*	@returns Double to string
	*/
	virtual string getRawData() const override;
};

