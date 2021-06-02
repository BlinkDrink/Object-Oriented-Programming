#include "Table.h"
#include "DoubleType.h"
#include "IntegerType.h"
#include "StringType.h"
#include "FormulaType.h"
#include<string>

using std::string;
using std::to_string;
using std::cout;
using std::invalid_argument;


string Table::getStringFilledWithSpaces(size_t num_of_spaces) const {
	string s;
	for (size_t i = 0; i < num_of_spaces; i++)
	{
		s.push_back(' ');
	}
	return s;
}

size_t Table::getLongestContentAtCol(size_t col) const {
	size_t longest = 0;

	for (size_t i = 0; i < m_rows; i++)
	{
		if (m_cells[i][col].getContent() != nullptr)
		{
			if (m_cells[i][col].getCellType() == DataType::DOUBLE)
			{
				DoubleType* dt = dynamic_cast<DoubleType*>(m_cells[i][col].getContent());

				if (longest < dt->getDoubleLength())
					longest = dt->getDoubleLength();
			}
			else if (m_cells[i][col].getCellType() == DataType::INTEGER)
			{
				IntegerType* it = dynamic_cast<IntegerType*>(m_cells[i][col].getContent());

				if (longest < it->getNumberLength())
					longest = it->getNumberLength();
			}
			else if (m_cells[i][col].getCellType() == DataType::STRING)
			{
				StringType* st = dynamic_cast<StringType*>(m_cells[i][col].getContent());

				if (longest < st->getString().size())
					longest = st->getString().size();
			}
			else if (m_cells[i][col].getCellType() == DataType::FORMULA) {
				FormulaType* ft = dynamic_cast<FormulaType*>(m_cells[i][col].getContent());

				if (longest < ft->getLengthOfNumber())
					longest = ft->getLengthOfNumber();
			}
		}
	}

	return longest;
}

vector<int> Table::getLongestWordPerCol() const {
	vector<int> lengthPerCol;

	for (size_t i = 0; i < m_cols; i++)
	{
		lengthPerCol.push_back(getLongestContentAtCol(i));
	}

	return lengthPerCol;
}

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

	m_rows = rows;
	m_cols = cols;
}

void Table::print() const {
	vector<int> longestWordsPerCol = getLongestWordPerCol();

	size_t rowsLen = strlen(to_string(m_rows).c_str());
	string leadingSpace = getStringFilledWithSpaces(rowsLen);
	cout << leadingSpace;
	for (size_t i = 0; i < m_cols; i++)
	{
		string spaces;
		if (longestWordsPerCol[i] != 0)
		{
			spaces = getStringFilledWithSpaces(longestWordsPerCol[i] - 1);
		}
		else
		{
			spaces = getStringFilledWithSpaces(longestWordsPerCol[i]);
		}
		cout << " | " << (char)(i + 65) << spaces;
	}

	cout << " |\n";

	for (size_t i = 0; i < m_rows; i++)
	{
		string spacesForNumbersCol = getStringFilledWithSpaces(rowsLen - strlen(to_string(i + 1).c_str()));
		cout << i + 1 << spacesForNumbersCol << " | ";
		for (size_t j = 0; j < m_cols; j++)
		{
			if (m_cells[i][j].getContent() != nullptr)
			{
				if (m_cells[i][j].getCellType() == DataType::DOUBLE)
				{
					DoubleType* dt = dynamic_cast<DoubleType*>(m_cells[i][j].getContent());
					if (dt)
					{
						string spaces = getStringFilledWithSpaces(longestWordsPerCol[j] - dt->getDoubleLength());
						dt->print();
						cout << spaces << " | ";
					}
				}
				else if (m_cells[i][j].getCellType() == DataType::INTEGER)
				{
					IntegerType* it = dynamic_cast<IntegerType*>(m_cells[i][j].getContent());

					if (it)
					{
						string spaces = getStringFilledWithSpaces(longestWordsPerCol[j] - it->getNumberLength());
						it->print();
						cout << spaces << " | ";
					}
				}
				else if (m_cells[i][j].getCellType() == DataType::STRING) {
					StringType* st = dynamic_cast<StringType*>(m_cells[i][j].getContent());
					if (st)
					{
						string spaces = getStringFilledWithSpaces(longestWordsPerCol[j] - st->getString().size());
						st->print();
						cout << spaces << " | ";
					}
				}
				else if (m_cells[i][j].getCellType() == DataType::FORMULA)
				{
					FormulaType* ft = dynamic_cast<FormulaType*>(m_cells[i][j].getContent());
					if (ft)
					{
						string spaces;
						spaces = getStringFilledWithSpaces(longestWordsPerCol[j] - ft->getLengthOfNumber());

						ft->print();
						cout << spaces << " | ";
					}
				}
			}
			else
			{
				string spaces;
				if (longestWordsPerCol[j] == 0)
					spaces = getStringFilledWithSpaces(longestWordsPerCol[j] + 1);
				else
					spaces = getStringFilledWithSpaces(longestWordsPerCol[j]);

				cout << spaces << " | ";
			}
		}
		cout << '\n';
	}
}

void Table::setCellAt(size_t row, size_t col, const Cell& cell) {
	if (col >= 26)
	{
		throw invalid_argument("Columns cannot exceed 25(counting from 0)");
	}

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

void Table::expandRows(size_t row) {
	size_t rowsToAdd = m_rows <= row ? row - m_rows : 0;
	for (size_t i = 0; i < rowsToAdd + 1; i++)
	{
		vector<Cell> newRow;
		for (size_t i = 0; i < m_cols; i++)
		{
			newRow.push_back(Cell(nullptr));
		}
		m_cells.push_back(newRow);
		m_rows++;
	}
}

void Table::expandCols(size_t col) {
	for (size_t i = 0; i < m_rows; i++)
	{
		while (m_cells[i].size() != col + 1)
		{
			m_cells[i].push_back(Cell(nullptr));
		}
	}

	m_cols = col + 1;
}

size_t Table::getRows() const { return m_rows; }

size_t Table::getCols() const { return m_cols; }