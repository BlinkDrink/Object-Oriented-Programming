#pragma once
#include <string>
#include <vector>
#include "./CellType.h"

using std::string;

class FormulaType : public CellType
{
private:
	string m_value;
	double m_calculated;

public:
	/*
	*	@brief Initializes m_formula with given string
	*
	*	@param equation - string to be initialized with
	*/
	FormulaType(const string &equation);

	/*
	*	@brief Prints the formula result on the console
	*/
	virtual void print() const;

	/*
	*	@brief Creates dynamically allocated copy of this object
	*
	*	@returns The newly allocated FormulaType* object
	*/
	virtual FormulaType *clone() const override;

	/*
	*	@brief Getter
	*
	*	@returns raw string format of formula after calculation
	*/
	virtual string toString() const override;

	/**
	 * @brief Gets the length of the calculated equation
	 * 
	 * @return size_t length of calculated equation
	 */
	size_t size() const;

	/**
	 * @brief Gets m_calculated
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