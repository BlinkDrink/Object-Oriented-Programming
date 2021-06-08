#pragma once
#include "./CellType.h"

class IntegerType : public CellType
{
private:
	int m_value;

public:
	/*
	*	@brief Initializes IntegerType with given value and sign
	*
	*	@param data - string to be initialized with
	*/
	IntegerType(const string &data);

	/*
	*	@brief prints m_value on the console
	*/
	virtual void print() const override;

	/*
	*	@brief Creates dynamically allocated copy of this object
	*
	*	@returns The newly allocated IntegerType* object
	*/
	virtual IntegerType *clone() const override;

	/**
	 * @brief Gets the length of the integer
	 * 
	 * @return size_t length
	 */
	virtual size_t size() const;

	/*
	*	@brief Getter
	*
	*	@returns Integer as string
	*/
	virtual string toString() const override;

	/**
	 * @brief Returns int as double
	 * 
	 * @return double 
	 */
	double toDouble() const;

	/**
	 * @brief Sums IntegerType with other 
	 * 
	 * @param other other object type with which IntegerType will be summed
	 * @return double 
	 */
	double operator+(const CellType *other) const;

	/**
	 * @brief Subtracts IntegerType with other 
	 * 
	 * @param other other object type with which IntegerType will be subtracted
	 * @return double 
	 */
	double operator-(const CellType *other) const;

	double operator*(const CellType *other) const;
	double operator/(const CellType *other) const;
	double operator^(const CellType *other) const;
};