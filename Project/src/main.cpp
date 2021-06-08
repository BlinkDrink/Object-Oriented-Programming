#include <iostream>
#include "../include/DocumentHandler.h"
#include "../include/IntegerType.h"
#include "../include/StringType.h"
using std::cout;

int main()
{
	//DocumentHandler::getInstance().run();

	vector<Cell> v;
	v.push_back(Cell(new IntegerType("13")));
	v.push_back(Cell(new StringType("abc")));

	return 0;
}