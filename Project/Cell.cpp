#include "Cell.h"
#include<iostream>

using std::cout;

void Cell::print() const {
	m_content->print();
}

DataType Cell::getCellType() const {
	return m_content->getType();
}

Cell::~Cell() {
	delete m_content;
}

