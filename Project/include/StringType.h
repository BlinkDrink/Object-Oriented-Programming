#pragma once
#include "./CellType.h"
#include <string>

using std::string;

class StringType : public CellType
{
private:
	string m_value;

public:
	/*
	*	@brief Initializes string
	*
	*	@param str - string to be initialized with
	*/
	StringType(const string &str);

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
	virtual StringType *clone() const override;

	/*
	*	@brief Getter
	*
	*	@returns inner string
	*/
	virtual string toString() const override;

	double toDouble() const;
	size_t size() const;
	virtual double operator+(const CellType *other) const override;
	virtual double operator-(const CellType *other) const override;
	virtual double operator*(const CellType *other) const override;
	virtual double operator/(const CellType *other) const override;
	virtual double operator^(const CellType *other) const override;
};