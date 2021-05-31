#include "Table.h"

using std::cout;

Table::Table(size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; i++)
	{
		vector<Cell> newRow;
		for (size_t j = 0; j < cols; j++)
		{
			newRow.push_back(Cell(nullptr));
		}
		m_cells.push_back(newRow);
	}
}

void Table::print() const {
	for (size_t i = 0; i < m_cells.size(); i++)
	{
		for (size_t j = 0; j < m_cells[i].size(); j++)
		{
			m_cells[i][j].print();
		}
	}
}

void Table::addCellAt(size_t row, size_t col, const Cell& cell) {
	if (row >= getRows() || col >= getMaxCol())
	{
		expand(row, col);
	}

	m_cells[row][col] = cell;
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
	for (size_t i = 0; i < row - getRows() + 1; i++)
	{
		vector<Cell> newRow;

		for (size_t j = 0; j < col - m_cells[i].size() + 1; j++)
		{
			newRow.push_back(Cell(nullptr));
		}
		m_cells.push_back(newRow);
	}
}

Table::~Table() {

}