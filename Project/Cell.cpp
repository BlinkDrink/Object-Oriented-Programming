#include "Cell.h"
#include<iostream>
#include "DoubleType.h"
#include "IntegerType.h"

using std::cout;

Cell::Cell(Type* content) :m_content(content) {
}

void Cell::copyFrom(const Cell& cell) {
	if (cell.m_content != nullptr)
		m_content = cell.m_content->clone();
	else
		m_content = nullptr;
}

Cell::Cell(const Cell& cell)
{
	copyFrom(cell);
	//m_content->setType(cell.getCellType());
}

Cell& Cell::operator=(const Cell& cell)
{
	if (this != &cell)
	{
		Type* t = cell.m_content->clone();
		delete m_content;
		m_content = t;
	}

	return *this;
}

Cell::Cell(Cell&& cell) noexcept
{
	m_content = cell.m_content;
	cell.m_content = nullptr;
}

Cell& Cell::operator=(Cell&& cell) noexcept
{
	if (this != &cell)
	{
		delete m_content;
		m_content = cell.m_content;
		cell.m_content = nullptr;
	}

	return *this;
}

void Cell::print() const {
	m_content->print();
}

void Cell::setContent()
{
}

DataType Cell::getCellType() const {
	return m_content->getType();
}

Cell::~Cell() {
	delete m_content;
}

