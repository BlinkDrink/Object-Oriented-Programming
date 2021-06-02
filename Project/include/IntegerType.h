#pragma once
#include "Type.h"
#include "Sign.h"

class IntegerType : public Type
{
private:
	long long m_integer;
	Sign m_sign;
public:
	/*
	*	@brief Initializes IntegerType with given value and sign
	*
	*	@param value - value to be initialized with
	*	@param s	 - sign to be initialized with
	*/
	IntegerType(long long value, Sign s);

	/*
	*	@brief prints m_integer and m_sign on the console
	*/
	virtual void print() const override;

	/*
	*	@returns the DataType of the current object
	*/
	virtual DataType getType() const override;

	/*
	*	@brief Creates dynamically allocated copy of this object
	*
	*	@returns The newly allocated IntegerType* object
	*/
	virtual IntegerType* clone() const override;

	/*
	*	@brief Getter of the inner number
	*/
	long long getNumber() const;

	/*
	*	@brief Setter of the inner number
	*/
	void setNumber(long long value);

	/*
	*	@brief Tells if the number has a sign
	*/
	bool hasSign() const;

	/*
	*	@brief Getter
	*
	*	@returns length of number
	*/
	size_t getNumberLength() const;
};