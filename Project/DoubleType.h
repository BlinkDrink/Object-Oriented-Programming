#include "Type.h"
#include "Sign.h"

class DoubleType : public Type {
private:
	double m_real;
	Sign m_sign;
public:
	void print() const override;
	DataType getType() const override;
	void setType(DataType type) override;

	void setNumber(double value);
	double getNumber() const;
};

