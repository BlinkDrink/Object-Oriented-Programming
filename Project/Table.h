#include<iostream>
#include<vector>
#include "Cell.h"

using std::vector;

class Table {
private:
	vector<vector<Cell>> m_cells;
public:
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
	void addCellAt(size_t row, size_t col, Type* item);

	/*
	*	@brief Expands the table to the given row and col
	*
	*	@param row - row to where it will expand
	*	@param col - column to where it will expand
	*/
	void expand(size_t row, size_t col);

	/*
	*	@returns the number of rows
	*/
	size_t getRows() const;

	/*
	*	@returns the size of the longest row of the table
	*/
	size_t getMaxCol() const;

	~Table();
};

