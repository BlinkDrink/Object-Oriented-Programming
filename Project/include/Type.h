#pragma once
#include "DataType.h"

/*
*	@brief Abstract class, used for interface purposes only
*/
class Type {
protected:
	string m_data;
public:
	virtual void print() const = 0;
	virtual Type* clone() const = 0;
	virtual DataType getType() const = 0;
	virtual string getRawData() const = 0;
};