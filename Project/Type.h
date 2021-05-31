#pragma once
#include "DataType.h"

class Type {
protected:
	DataType m_type;
public:
	virtual void print() const = 0;
	virtual DataType getType() const = 0;
	virtual void setType(DataType type) = 0;
};