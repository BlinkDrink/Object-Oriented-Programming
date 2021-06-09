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
	DocumentHandler::getInstance().run();

	return 0;
}