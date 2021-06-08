#include "../include/Cell.h"
#include <iostream>

using std::cout;

Cell::Cell(CellType *content) : m_content(content)
{
}

void Cell::copyFrom(const Cell &other)
{
	if (other.m_content != nullptr)
		m_content = other.m_content->clone();
	else
		m_content = nullptr;
}

Cell::Cell(const Cell &other)
{
	copyFrom(other);
}

Cell &Cell::operator=(const Cell &other)
{
	if (this != &other)
	{
		if (other.m_content != nullptr)
		{
			CellType *t = other.m_content->clone();
			delete m_content;
			m_content = t;
		}
		else
		{
			delete m_content;
			m_content = nullptr;
		}
	}

	return *this;
}

Cell::Cell(Cell &&other) noexcept
{
	m_content = other.m_content;
	other.m_content = nullptr;
}

Cell &Cell::operator=(Cell &&other) noexcept
{
	if (this != &other)
	{
		delete m_content;
		m_content = other.m_content;
		other.m_content = nullptr;
	}

	return *this;
}

void Cell::print() const
{
	if (m_content == nullptr)
		cout << "";
	else
		m_content->print();
}

CellType *Cell::getContent() const
{
	return m_content;
}

Cell::~Cell()
{
	delete m_content;
}