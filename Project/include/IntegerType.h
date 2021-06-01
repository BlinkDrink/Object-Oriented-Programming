#pragma once
#include "Type.h"
#include "Sign.h"

class IntegerType : public Type
{
private:
	long long m_integer;
	Sign m_sign;
public:
	IntegerType(long long value, Sign s);
	virtual void print() const override;
	virtual DataType getType() const override;
	virtual void setType(DataType type) override;
	virtual IntegerType* clone() const override;

	long long getNumber() const;
	void setNumber(long long value);
};