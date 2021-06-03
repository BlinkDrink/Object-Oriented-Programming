#include<iostream>
#include "IntegerType.h"
#include "DoubleType.h"
#include "StringType.h"
#include "FormulaType.h"
#include "Table.h"
#include "DocumentHandler.h"
using std::cout;

int main() {
	/*Table t(5, 5);
	try
	{
		t.setCellAt(0, 0, Cell(new IntegerType("13")));
		t.setCellAt(0, 1, Cell(new DoubleType("-432.23")));
		t.setCellAt(2, 1, Cell(new DoubleType("-3.5")));
		t.setCellAt(2, 2, Cell(new DoubleType("3000.41259120")));
		t.setCellAt(1, 1, Cell(new FormulaType("=14 + 15 + 24 / 3 * 0.5 - 200 + 1024 / 2")));
		t.setCellAt(1, 0, Cell(new IntegerType("+66")));
		t.setCellAt(2, 3, Cell(new StringType("\"Quoted\"")));
		t.setCellAt(4, 3, Cell(new IntegerType("+5050")));
		t.setCellAt(1, 5, Cell(new StringType("abc")));
		t.setCellAt(2, 5, Cell(new FormulaType("=2 + 2 - 2 - 4 + 2")));
		t.setCellAt(3, 5, Cell(new FormulaType("=12 * 12 - 12 * 12")));
		t.setCellAt(4, 5, Cell(new StringType("\"\"Not so Quoted\"\"")));
		t.setCellAt(5, 5, Cell(new StringType("\"\"Not so Quoted\"\"")));
		t.setCellAt(5, 5, Cell(new IntegerType("15")));
		t.print();

	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}*/
	DocumentHandler::getInstance().run();

	return 0;
}