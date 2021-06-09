#include <iostream>
#include "../include/Table.h"
#include "../include/DocumentHandler.h"
#include "../include/IntegerType.h"
#include "../include/DoubleType.h"
#include "../include/FormulaType.h"
#include "../include/StringType.h"
using std::cout;

int main()
{
	Table t(3, 3);
	t.setCellAt(0, 0, Cell(new IntegerType("500")));
	t.setCellAt(0, 1, Cell(new StringType("500a")));

	FormulaType s("=A1 * (B1 + 2)", t);
	// FormulaType f("=3 + 4 * 2 / ( 1-5 ) ^ 2 ^ 3", t);
	// StringType a("-4.000");
	// StringType b("2");

	double f = s.toDouble();

	return 0;
}