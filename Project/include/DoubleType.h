#include "Type.h"
#include "Sign.h"

class DoubleType : public Type {
private:
	double m_real;
	Sign m_sign;
public:
	/*
	*	@brief Initializes DoubleType object with given parameters
	*
	*	@param real - real number to be initialized with
	*	@param sign - sign to be initialized with
	*/
	DoubleType(double real, Sign sign);

	/*
	*	@brief prints m_real and m_sign on the console
	*/
	virtual void print() const override;

	/*
	*	@returns the DataType of the current object
	*/
	virtual DataType getType() const override;

	/*
	*	@brief Creates dynamically allocated copy of this object
	*
	*	@returns The newly allocated DoubleType* object
	*/
	virtual DoubleType* clone() const override;

	/*
	*	@brief Getter of m_real
	*/
	double getNumber() const;

	/*
	*	@brief Setter of m_real
	*/
	void setNumber(double value);

	/*
	*	@brief Tells if the number has a sign
	*/
	bool hasSign() const;

	/*
	*	@brief Getter
	*
	*	@returns length of m_real
	*/
	size_t getDoubleLength() const;

	/*
	*	@brief Getter
	*
	*	@returns raw data to string
	*/
	virtual string getRawData() const override;
};

