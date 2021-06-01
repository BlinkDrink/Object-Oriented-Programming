#include <iostream>
#include <fstream>
#include "../include/CommandParser.h"
#include "../include/DocumentHandler.h"
#include "../include/IntegerType.h"
#include "../include/DoubleType.h"
#include "../include/Table.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::invalid_argument;

void menu()
{
	cout << "\t\t\t\t------------------" << endl
		 << "\t\t\t\t|Table of commands|" << endl
		 << "\t\t\t\t-------------------" << endl
		 << ">open <path>\t\t\t\t\t opens the file to the given path" << endl;
}

int main()
{
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
	t.addCellAt(0, 0, Cell(new IntegerType(13, Sign::PLUS)));
	t.addCellAt(0, 1, Cell(new DoubleType(423.23, Sign::MINUS)));
	t.addCellAt(1, 1, Cell(new DoubleType(54312.24, Sign::PLUS)));
	t.addCellAt(1, 0, Cell(new IntegerType(25, Sign::PLUS)));
	t.print();

	return 0;
}