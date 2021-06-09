#pragma once
#include <vector>
#include "./CellType.h"
#include "./Table.h"

using std::vector;

class Cell
{
private:
	CellType *m_content;

	/*
	*	@brief Copies contents from other into the object
	*
	*	@param other - Cell object from which copying will be made
	*/
	void copyFrom(const Cell &other);

public:
	/*
	*	@brief Initializes cell's content with the given argument
	*
	*	@param content - content to assign
	*/
	Cell(const string &content, const Table &ref);

	/*
	*	@brief Copy constructor
	*
	*	@param other - Cell object from which copying will be made
	*/
	Cell(const Cell &other);

	/*
	*	@brief Copy assignment operator
	*
	*	@param other - Cell object from which copying will be made
	*	@returns *this
	*/
	Cell &operator=(const Cell &other);

	/*
	*	@brief Move constructor
	*
	*	@param other - Cell object from which moving will be made
	*/
	Cell(Cell &&other) noexcept;

	/*
	*	@brief Move assignment operator
	*
	*	@param other - Cell object from which moving will be made
	*/
	Cell &operator=(Cell &&other) noexcept;

	/*
	*	@brief Prints cell's information on the console
	*/
	void print() const;

	CellType *getContent() const;

	double getContentAsDouble() const;

	~Cell();
};