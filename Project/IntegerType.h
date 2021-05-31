#pragma once
#include "Type.h"
#include "Sign.h"

class IntegerType : public Type
{
private:
	long long m_integer;
	Sign m_sign;
public:
	void print() const override;
	DataType getType() const override;
	void setType(DataType type) override;

	long long getNumber() const;
	void setNumber(long long value);
};