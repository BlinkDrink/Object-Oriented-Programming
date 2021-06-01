#pragma once
#include <iostream>
#include <vector>
#include "./Cell.h"
#include <string>

using std::vector;

class Table
{
private:
	vector<vector<Cell>> m_cells;
	size_t m_rows;
	size_t m_cols;

	std::string getStringFilledWithSpaces(size_t num_of_spaces) const;
	size_t getLongestContentAtCol(size_t col) const;

public:
	Table(size_t rows, size_t cols);

	/*
	*	@brief Prints the table on the console
	*/
	void print() const;

	/*
	*	@brief Add a cell at given row and column
	*
	*	@param row - row index
	*	@param col - col index
	*/
	void addCellAt(size_t row, size_t col, const Cell &cell);

	/*
	*	@brief Expands the table to the given row
	*
	*	@param row - row to where it will expand
	*/
	void expandRows(size_t row);

	/*
	*	@brief Expands the table to the given col
	*
	*	@param col - column to where it will expand
	*/
	void expandCols(size_t col);

	/*
	*	@returns the number of rows
	*/
	size_t getRows() const;

	/*
	*	@returns the size of the longest row of the table
	*/
	size_t getMaxCol() const;

	void updateCell(size_t row, size_t col, const Cell &cell);

	~Table();
};
