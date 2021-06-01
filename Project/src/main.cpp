#include<iostream>
#include<fstream>
#include "CommandParser.h"
#include "DocumentHandler.h"
#include "IntegerType.h"
#include "DoubleType.h"
#include "Table.h"
#include "FormulaType.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::invalid_argument;

void menu() {
	cout <<
		"\t\t\t\t------------------" << endl <<
		"\t\t\t\t|Table of commands|" << endl <<
		"\t\t\t\t-------------------" << endl <<
		">open <path>\t\t\t\t\t opens the file to the given path" << endl;
}

int main() {
	//ifstream file;
	//DocumentHandler fh;

	//while (true)
	//{
	//	cout << '>';
	//	CommandParser cp;
	//	cp.readCmd();
	//	cp.tokenizeInnerString();

	//	switch (cp.getCommandType())
	//	{
	//	case CommandType::OPEN:
	//		fh.openFile(cp.atToken(1));
	//		break;
	//	case CommandType::CLOSE:
	//		fh.closeFile();
	//		break;
	//	case CommandType::NEW:
	//		//TODO: Implement New
	//		break;
	//	case CommandType::SAVE:
	//		//TODO: Implement Save
	//		break;
	//	case CommandType::SAVEAS:
	//		//TODO: Implement SaveAs
	//		break;
	//	case CommandType::EXIT:
	//		return 0;
	//	default:
	//		break;
	//	}
	//}

	Table t(2, 2);
	t.setCellAt(0, 0, Cell(new IntegerType(13, Sign::PLUS)));
	t.setCellAt(0, 1, Cell(new DoubleType(423.23, Sign::MINUS)));
	t.setCellAt(1, 1, Cell(new DoubleType(54312.24, Sign::PLUS)));
	t.setCellAt(1, 0, Cell(new IntegerType(25, Sign::PLUS)));
	t.setCellAt(12, 3, Cell(new IntegerType(100, Sign::PLUS)));
	t.setCellAt(100, 16, Cell(new IntegerType(100, Sign::PLUS)));

	t.print();

	/*FormulaType f("=432 - 2 + 24 * 4 * 3 + 12 / 4 / 6");
	double res = f.calculateFormula();*/
	return 0;
}