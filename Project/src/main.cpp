#include<iostream>
#include<fstream>
#include "CommandParser.h"
#include "DocumentHandler.h"
#include "IntegerType.h"
#include "DoubleType.h"
#include "StringType.h"
#include "FormulaType.h"
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
	//		cout << "Exiting the program...";
	//		return 0;
	//	default:
	//		break;
	//	}
	//}

	Table t(2, 2);
	t.setCellAt(0, 0, Cell(new IntegerType(13, Sign::PLUS)));
	t.setCellAt(0, 1, Cell(new DoubleType(423.23, Sign::MINUS)));
	t.setCellAt(2, 1, Cell(new DoubleType(3.5, Sign::MINUS)));
	t.setCellAt(2, 2, Cell(new DoubleType(3000.41259120, Sign::MINUS)));
	t.setCellAt(1, 1, Cell(new FormulaType("=14 + 15 + 24 / 3 * 0.5 - 200 + 1024 / 2")));
	t.setCellAt(1, 0, Cell(new IntegerType(25, Sign::PLUS)));
	t.setCellAt(2, 3, Cell(new StringType("\"Quoted\"")));
	t.setCellAt(4, 3, Cell(new IntegerType(100, Sign::PLUS)));
	t.setCellAt(1, 5, Cell(new StringType("abc")));
	t.setCellAt(2, 5, Cell(new FormulaType("=2 + 2 - 2 - 4 + 2")));
	t.setCellAt(3, 5, Cell(new FormulaType("=12 * 12 - 12 * 12")));
	t.setCellAt(4, 5, Cell(new StringType("\"\"Not so Quoted\"\"")));
	t.setCellAt(5, 5, Cell(new StringType("\"\"Not so Quoted\"\"")));
	t.setCellAt(5, 5, Cell(new IntegerType(15, Sign::NONE)));

	t.print();

	return 0;
}