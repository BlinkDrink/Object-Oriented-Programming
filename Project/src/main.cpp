#include <iostream>
#include "../include/DocumentHandler.h"
#include "../include/IntegerType.h"
#include "../include/DoubleType.h"
#include "../include/FormulaType.h"
#include "../include/StringType.h"
using std::cout;

int main()
{
	FormulaType f("=3 + 4 * 2 / ( 1 − 5 ) ^ 2 ^ 3");

	double s = f.toDouble();

	return 0;
}