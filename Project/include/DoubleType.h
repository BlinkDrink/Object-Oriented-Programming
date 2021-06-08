#pragma once
#include <iostream>
#include <string>
#include "./CellType.h"

class DoubleType : public CellType
{
private:
	double m_value;

public:
	/*
	*	@brief Initializes DoubleType object with given parameter
	*
	*	@param data - string object with which DoubleType will be initialized
	*/
	DoubleType(const string &data);

	/*
	*	@brief prints the real number on the console
	*/
	virtual void print() const override;

	/*
	*	@brief Creates dynamically allocated copy of this object
	*
	*	@returns The newly allocated DoubleType* object
	*/
	virtual DoubleType *clone() const override;

	/*
	*	@brief Getter
	*
	*	@returns Double to string
	*/
	virtual string toString() const override;

	/**
	 * @brief Gets the length of the calculated equation
	 * 
	 * @return size_t length of calculated equation
	 */
	size_t size() const;

	/**
	 * @brief Gets m_value
	 * 
	 * @return double the calculated equation
	 */
	double toDouble() const;

	/**
	 * @brief Adds other to current object
	 * 
	 * @param other object to sum up with
	 * @return double result after addition
	 */
	virtual double operator+(const CellType *other) const override;

	/**
	 * @brief Subtracts other from current object
	 * 
	 * @param other object to subtract with
	 * @return double result after subtraction
	 */
	virtual double operator-(const CellType *other) const override;

	/**
	 * @brief Multiplies other with current object
	 * 
	 * @param other object to multiply with
	 * @return double result after multiplication
	 */
	virtual double operator*(const CellType *other) const override;

	/**
	 * @brief Divides current object with other
	 * 
	 * @param other object to divide with
	 * @return double result after division
	 */
	virtual double operator/(const CellType *other) const override;

	/**
	 * @brief Raises current object to the power of other
	 * 
	 * @param other exponent
	 * @return double result after rasing to the exponent
	 */
	virtual double operator^(const CellType *other) const override;
};
