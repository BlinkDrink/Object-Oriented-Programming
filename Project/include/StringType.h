#pragma once
#include "Type.h"
#include<string>

using std::string;

class StringType : public Type
{
private:
	string m_string;
public:
	/*
	*	@brief Initializes string
	*
	*	@param str - string to be initialized with
	*/
	StringType(const string& str);

	/*
	*	@brief prints m_string on the console
	*
	*/
	virtual void print() const override;

	/*
	*	@brief Creates dynamically allocated copy of this object
	*
	*	@returns The newly allocated StringType* object
	*/
	virtual StringType* clone() const override;

	/*
	*	@returns the DataType of the current object
	*/
	virtual DataType getType() const override;

	/*
	*	@brief Getter of m_string
	*/
	string getString() const;
};