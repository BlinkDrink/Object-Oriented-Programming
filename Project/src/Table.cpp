#include "../include/Table.h"
#include "../include/DoubleType.h"
#include "../include/IntegerType.h"
#include <string>

using std::cout;

using std::invalid_argument;
using std::string;
using std::to_string;

Table::Table(size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		vector<Cell> newRow;
		for (size_t j = 0; j < cols; j++)
		{
			newRow.push_back(Cell(nullptr));
		}
		m_cells.push_back(newRow);
	}

	m_rows = rows;
	m_cols = cols;
}

string Table::getStringFilledWithSpaces(size_t num_of_spaces) const
{
	string s;
	for (size_t i = 0; i < num_of_spaces; i++)
	{
		s.push_back(' ');
	}
	return s;
}

void Table::print() const
{
	for (size_t i = 0; i < m_cols; i++)
	{
		size_t longestContent = getLongestContentAtCol(i);
		if (i == 0)
		{
			//string spaces = getStringFilledWithSpaces(longestContent - 1);
			char colName = i + 65;
			cout << "  |" << colName << /*spaces*/ '|';
		}

		for (size_t j = 0; j < m_rows; j++)
		{
			cout << j + 1 << "  |";
			m_cells[i][j].print();
			cout << '|';
		}
	}
}

void Table::addCellAt(size_t row, size_t col, const Cell &cell)
{
	if (row >= m_rows)
	{
		expandRows(row);
	}

	if (col >= m_cols)
	{
		expandCols(col);
	}

	m_cells[row][col] = cell;
}

void Table::updateCell(size_t row, size_t col, const Cell &cell)
{
	if (row >= m_rows || col >= m_cols)
	{
		throw invalid_argument("Invalid indexes.");
	}

	m_cells[row][col] = cell;
}

size_t Table::getRows() const
{
	return m_cells.size();
}

size_t Table::getMaxCol() const
{
	size_t maxCol = 0;
	for (size_t i = 0; i < m_rows; i++)
	{
		if (maxCol < m_cells[i].size())
		{
			maxCol = m_cells[i].size();
		}
	}
	return maxCol;
}

void Table::expandRows(size_t row)
{
	size_t rowsToAdd = m_rows <= row ? row - m_rows : 0;
	for (size_t i = 0; i < rowsToAdd + 1; i++)
	{
		vector<Cell> newRow;
		m_cells.push_back(newRow);
		m_rows++;
	}
}

void Table::expandCols(size_t col)
{
	for (size_t i = 0; i < m_rows; i++)
	{
		while (m_cells[i].size() != col + 1)
		{
			m_cells[i].push_back(Cell(nullptr));
		}
	}

	m_cols = col + 1;
}

size_t Table::getLongestContentAtCol(size_t col) const
{
	size_t longest = 0;
	for (size_t i = 0; i < m_rows; i++)
	{
		if (m_cells[i][col].getCellType() == DataType::DOUBLE)
		{
			DoubleType *dt = (DoubleType *)m_cells[i][col].getContent();

			string doubleAsString = to_string(dt->getNumber());
			if (longest < doubleAsString.size())
			{
				longest = doubleAsString.size();
			}
		}
		else if (typeid(m_cells[i][col].getContent()) == typeid(IntegerType))
		{
			cout << 'h';
		}
	}
	return longest;
}

//void Table::expand(size_t row, size_t col) {
//	for (size_t i = 0; i < m_rows; i++)
//	{
//		size_t currentCols = m_cells[i].size() - 1;
//		size_t colsToAdd = currentCols <= col ? col - currentCols : 0;
//		for (size_t j = 0; j < colsToAdd; j++)
//		{
//			m_cells[i].push_back(Cell(nullptr));
//		}
//	}
//
//	size_t rowsToAdd = m_rows <= row ? row - m_rows : 0;
//	for (size_t i = 0; i < rowsToAdd + 1; i++)
//	{
//		vector<Cell> newRow;
//
//		for (size_t j = 0; j < col + 1; j++)
//		{
//			newRow.push_back(Cell(nullptr));
//		}
//		m_cells.push_back(newRow);
//	}
//
//	m_rows = m_cells.size();
//	m_cols = getMaxCol();
//}

Table::~Table() {}