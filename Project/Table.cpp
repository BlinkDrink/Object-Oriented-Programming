#include "Table.h"

using std::cout;

void Table::print() const {
	for (size_t i = 0; i < m_cells.size(); i++)
	{
		for (size_t j = 0; j < m_cells[i].size(); j++)
		{
			m_cells[i][j].print();
		}
	}
}

void Table::addCellAt(size_t row, size_t col, Type* item) {
	if (row >= getRows() || col >= getMaxCol())
	{
		expand(row, col);
	}

	switch (m_cells[row][col])
	{
	default:
		break;
	}

	m_cells[row][col];
}

size_t Table::getRows() const {
	return m_cells.size();
}

size_t Table::getMaxCol() const {
	size_t maxCol = 0;
	for (size_t i = 0; i < m_cells.size(); i++)
	{
		if (maxCol < m_cells[i].size())
		{
			maxCol = m_cells[i].size();
		}
	}
	return maxCol;
}

void Table::expand(size_t row, size_t col) {

}

Table::~Table() {

}