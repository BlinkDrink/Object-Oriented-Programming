#include "Type.h"
#include <vector>

using std::vector;

class Cell {
private:
	Type* m_content;
public:
	void print() const;
	DataType getCellType() const;

	~Cell();
};