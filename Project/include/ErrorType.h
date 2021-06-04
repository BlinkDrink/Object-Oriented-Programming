#pragma once
#include "CellType.h"

class ErrorType : public CellType {
public:
	ErrorType();

	virtual void print() const override;

	virtual ErrorType* clone() const override;

	virtual DataType getDataType() const override;

	virtual string getRawData() const override;
};