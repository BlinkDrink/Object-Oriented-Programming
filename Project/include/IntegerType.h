#pragma once
#include "./CellType.h"

class IntegerType : public CellType
{
private:
	long long m_value;

public:
	/**
	*	@brief Initializes IntegerType with given value and sign
	*
	*	@param data - string to be initialized with
	*/
	IntegerType(const string &data);

	/**
	*	@brief prints m_value on the console
	*/
	virtual void print() const override;

	/**
	*	@brief Creates dynamically allocated copy of this object
	*
	*	@returns The newly allocated IntegerType* object
	*/
	virtual IntegerType *clone() const override;

	/**
	*	@brief Getter
	*
	*	@returns Integer as string
	*/
	virtual string toString() const override;

	/**
	 * @brief Creates m_content string fit for file format
	 * 
	 * @return string formated content
	 */
	virtual string toFileFormat() const;

	/**
	 * @brief Returns integer as double
	 * 
	 * @return double 
	 */
	double toDouble() const;

	/**
	 * @brief Gets the length of the integer
	 * 
	 * @return size_t length
	 */
	virtual size_t size() const;

	/**
	 * @brief Sums IntegerType with other 
	 * 
	 * @param other object with which addition will be made
	 * @return double 
	 */
	double operator+(const CellType &other) const;

	/**
	 * @brief Subtracts IntegerType with other 
	 * 
	 * @param other object with which subtraction will be made
	 * @return double result after subtraction
	 */
	double operator-(const CellType &other) const;

	/**
	 * @brief Multiplies other with current object's inner value
	 * 
	 * @param other object with which multiplication will be made
	 * @return double result after multiplication
	 */
	double operator*(const CellType &other) const;

	/**
	 * @brief Divides inner integer with other
	 * 
	 * @param other object with which division will be made
	 * @return double result after multiplication
	 */
	double operator/(const CellType &other) const;

	/**
	 * @brief Raises inner integer to the power exponent other
	 * 
	 * @param other exponent value
	 * @return double result after raising to the power
	 */
	double operator^(const CellType &other) const;
};