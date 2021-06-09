#pragma once
#include <string>
#include <vector>
#include "./CellType.h"
#include "./StringType.h"
#include "./Table.h"

using std::string;

/**
 * @brief Represents formulas in electronic table. Holds refference to the table that contains it.
 * 
 */
class FormulaType : public CellType
{
private:
	string m_value;
	double m_calculated;

	/**
	 * @brief Applies operator(op) on a and b.
	 * 
	 * @param a left opperand
	 * @param b right opperand
	 * @param op operator(+,-,*,/,^)
	 * @return double result after performing operation
	 */
	double applyOperator(StringType &a, StringType &b, char op) const;

	/**
	 * @brief Checks for the precedence of the given operator(op)
	 * 
	 * @param op operator to check it's precedence
	 * @return size_t 1 if '+' or '-', 2 if '*' or '/'. 0 otherwise
	 */
	size_t precedence(char op) const;

	double calculateFormula() const;

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
	virtual double operator+(const CellType &other) const override;

	/**
	 * @brief Subtracts other from current object
	 * 
	 * @param other object to subtract with
	 * @return double result after subtraction
	 */
	virtual double operator-(const CellType &other) const override;

	/**
	 * @brief Multiplies other with current object
	 * 
	 * @param other object to multiply with
	 * @return double result after multiplication
	 */
	virtual double operator*(const CellType &other) const override;

	/**
	 * @brief Divides current object with other
	 * 
	 * @param other object to divide with
	 * @return double result after division
	 */
	virtual double operator/(const CellType &other) const override;

	/**
	 * @brief Raises current object to the power of other
	 * 
	 * @param other exponent
	 * @return double result after rasing to the exponent
	 */
	virtual double operator^(const CellType &other) const override;
};