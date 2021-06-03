#pragma once
#include<iostream>
#include<string>
#include "CellType.h"

class DoubleType : public CellType {
private:
	/*
	*	@brief Validates whether given string input is valid real number.
	*
	*	@returns true if valid, false otherwise
	*/
	bool validateData(const string& data) const;
public:
	/*
	*	@brief Initializes DoubleType object with given parameter
	*
	*	@param data - string object with which DoubleType will be initialized
	*/
	DoubleType(const string& data);

	/*
	*	@brief prints m_real and m_sign on the console
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

