#include "Type.h"
#include <vector>

using std::vector;

class Cell {
private:
	Type* m_content;

	void copyFrom(const Cell& cell);
public:
	Cell(Type* content);
	Cell(const Cell& cell);
	Cell& operator=(const Cell& cell);
	Cell(Cell&& cell) noexcept;
	Cell& operator=(Cell&& cell) noexcept;

	void print() const;
	void setContent();

	DataType getCellType() const;
	~Cell();
};