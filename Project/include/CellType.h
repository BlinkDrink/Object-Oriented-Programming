#pragma once
#include<string>
#include "DataType.h"

using std::string;

/*
*	@brief Abstract class, used for interface purposes only
*/
class CellType {
protected:
	string m_data;
public:
	virtual void print() const = 0;
	virtual CellType* clone() const = 0;
	virtual DataType getDataType() const = 0;
	virtual string getRawData() const = 0;
};