#include <iostream>
#include "../include/Cell.h"
#include "../include/StringHelper.h"
#include "../include/IntegerType.h"
#include "../include/DoubleType.h"
#include "../include/FormulaType.h"
#include "../include/StringType.h"

using std::cout;
using std::invalid_argument;

Cell::Cell(const string &content, const Table &ref)
{
	StringHelper sh;
	if (sh.isStringInteger(content))
	{
		m_content = new IntegerType(content);
	}
	else if (sh.isStringDouble(content))
	{
		m_content = new DoubleType(content);
	}
	else if (sh.isStringValidString(content))
	{
		string cpy(content);
		sh.removeQuotations(cpy);
		if (sh.isStringValidFormula(cpy))
			m_content = new FormulaType(cpy, ref);
		else
			m_content = new StringType(cpy);
	}
	else if (content.empty())
	{
		m_content = nullptr;
	}
	else
	{
		string err = "Error: incorrect value " + content;
		throw invalid_argument(err);
	}
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

double Cell::getContentAsDouble() const
{
	if (m_content == nullptr)
	{
		return 0;
	}

	return m_content->toDouble();
}

CellType *Cell::getContent() const
{
	return m_content;
}

Cell::~Cell()
{
	delete m_content;
}