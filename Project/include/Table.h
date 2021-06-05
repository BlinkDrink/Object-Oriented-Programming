#pragma once
#include<iostream>
#include<vector>
#include "Cell.h"
#include<string>

using std::vector;
using std::string;

class Table {
private:
	vector<vector<Cell>> m_cells;
	size_t m_rows;
	size_t m_cols;

	/*
	*	@brief Looks up given column to find the longest content
	*
	*	@param col - column to check
	*/
	size_t getLongestContentAtCol(size_t col) const;

	/*
	*	@brief Create a vector of int that contains the longest word for each column
	*
	*	@returns vector<int> filled with size of longest word for the column
	*/
	vector<int> getLongestWordPerCol() const;
public:
	Table();

	/*
	*	@brief Initializes table size with given rows and cols
	*
	*	@param rows - rows to be initialized with
	*	@param cols - cols to be intiialized with
	*/
	Table(size_t rows, size_t cols);

	/*
	*	@brief Prints the table on the console
	*/
	void print() const;

	/*
	*	@brief Set a cell at given row and column. Changes entire cell. Expands if row/col is bigger than current
	*
	*	@param row - row index
	*	@param col - col index
	*/
	void setCellAt(size_t row, size_t col, const Cell& cell);

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
	*	@brief Gets current rows of the table
	*/
	size_t getRows() const;

	/*
	*	@brief Gets current columns of the table
	*/
	size_t getCols() const;

	/*
	*	@brief Checks if the table is empty
	*
	*	@returns true if empty, false otherwise
	*/
	bool empty() const;

	/*
	*	@brief Prints the first row of the table(the one containing A-Z)
	*/
	void printFirstRow() const;

	/*
	*	@brief Prints the rest of the table after the first row
	*/
	void printAfterFirstRow() const;

	/*
	*	@brief Prints the contents of a given cell
	*
	*	@param row				- row of cell
	*	@param col				- column of cell
	*	@param longestWordOfCol - the length of the longest word for the given column
	*/
	void printCellInformation(size_t row, size_t col, size_t longestWordOfCol) const;
};

