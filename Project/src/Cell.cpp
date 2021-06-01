#include "Cell.h"
#include<iostream>
#include "DoubleType.h"
#include "IntegerType.h"

using std::cout;

Cell::Cell(Type* content) :m_content(content) {
}

void Cell::copyFrom(const Cell& other) {
	if (other.m_content != nullptr)
		m_content = other.m_content->clone();
	else
		m_content = nullptr;
}

Cell::Cell(const Cell& other)
{
	copyFrom(other);
	//m_content->setType(cell.getCellType());
}

Cell& Cell::operator=(const Cell& other)
{
	if (this != &other)
	{
		Type* t = other.m_content->clone();
		delete m_content;
		m_content = t;
	}

	return *this;
}

Cell::Cell(Cell&& other) noexcept
{
	m_content = other.m_content;
	other.m_content = nullptr;
}

Cell& Cell::operator=(Cell&& other) noexcept
{
	if (this != &other)
	{
		delete m_content;
		m_content = other.m_content;
		other.m_content = nullptr;
	}

	return *this;
}

void Cell::print() const {
	if (m_content == nullptr)
		cout << "";
	else
		m_content->print();
}

DataType Cell::getCellType() const {
	return m_content->getType();
}

Type* Cell::getContent() const {
	return m_content;
}


Cell::~Cell() {
	delete m_content;
}