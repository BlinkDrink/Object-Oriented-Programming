#include "Type.h"
#include "Sign.h"

class DoubleType : public Type {
private:
	double m_real;
	Sign m_sign;
public:
	DoubleType(double real, Sign sign);

	virtual void print() const override;
	virtual DataType getType() const override;
	virtual void setType(DataType type) override;
	virtual DoubleType* clone() const override;

	double getNumber() const;
	void setNumber(double value);
};

