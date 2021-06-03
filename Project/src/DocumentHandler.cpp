#include<iostream>
#include<string>
#include "DocumentHandler.h"
#include "StringHelper.h"
#include "CommandParser.h"
#include "IntegerType.h"
#include "DoubleType.h"
#include "FormulaType.h"
#include "StringType.h"

using std::cout;
using std::cin;
using std::string;
using std::invalid_argument;
using std::getline;
using std::endl;

DocumentHandler::DocumentHandler() : m_isSaved(false) {
}

void DocumentHandler::menu() const {
}

DocumentHandler& DocumentHandler::getInstance() {
	static DocumentHandler inst;
	return inst;
}

void DocumentHandler::populateTableFromFile() {
	StringHelper sh;

	if (!m_reader.is_open())
	{
		throw invalid_argument("There is no currently opened file.");
	}

	size_t rowsOfFile = 0;
	size_t maxColOfFile = 0;
	string content;

	while (getline(m_reader, content))
	{
		rowsOfFile++;
		vector<string> parts = sh.splitBy(content, ",");
		if (maxColOfFile < parts.size())
		{
			maxColOfFile = parts.size();
		}
	}

	m_table.expandRows(rowsOfFile);
	m_table.expandCols(maxColOfFile);

	if (!m_reader.good())
	{
		m_reader.clear();
	}
	m_reader.seekg(0, std::ios_base::beg);
	size_t currRow = 0;

	while (getline(m_reader, content))
	{
		vector<string> parts = sh.splitBy(content, ",");
		for (size_t i = 0; i < parts.size(); i++)
		{
			sh.trim(parts[i]);
			if (sh.isStringInteger(parts[i])) {
				m_table.setCellAt(currRow, i, Cell(new IntegerType(parts[i])));
			}
			else if (sh.isStringDouble(parts[i]))
			{
				m_table.setCellAt(currRow, i, Cell(new DoubleType(parts[i])));
			}
			else if (sh.isStringValidFormula(parts[i]))
			{
				m_table.setCellAt(currRow, i, Cell(new FormulaType(parts[i])));
			}
			else if (sh.isStringValidString(parts[i]))
			{
				m_table.setCellAt(currRow, i, Cell(new StringType(parts[i])));
			}
			else if (parts[i].empty())
			{
				m_table.setCellAt(currRow, i, Cell(nullptr));
			}
		}
		currRow++;
	}
}

void DocumentHandler::openFile(const string& path) {
	m_reader.open(path);

	if (!m_reader.is_open())
	{
		throw invalid_argument("Couldn't open file for reading.");
	}

	populateTableFromFile();

	m_reader.close();

	m_writer.open(path);

	if (!m_writer.is_open())
	{
		throw invalid_argument("Couldn't link current document with the file.");
	}
}

void DocumentHandler::closeFile() {
	if (m_writer.is_open())
	{
		if (!m_isSaved)
		{
			char choice;
			cout << "There are unsaved changes. SAVE/DON'T SAVE/CANCEL(s/d/c): ";
			cin >> choice;
			while (true)
			{
				if (choice == 's')
				{
					saveToFile();
				}
				else if (choice == 'd') {
					m_writer.close();
				}
				else if (choice == 'c') {
					break;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			m_writer.close();
		}
	}
}

void DocumentHandler::saveToFile() {
	if (!m_writer.is_open())
	{
		throw invalid_argument("Currently there is no file linked to this document.");
	}

	// TODO: Implement save table to file

	m_isSaved = true;
}

void DocumentHandler::run() {
	menu();
	CommandParser cp;

	while (true)
	{
		string cmd;
		cp.clearCmd();
		cout << ">";
		cp.readCmd();
		cp.tokenizeInnerString();
		if (cp.getRaw().size() == 0 || cp.size() == 0 || cp.size() > 3)
		{
			cout << "Invalid command." << endl;
			continue;
		}

		cmd = cp.atToken(0);

		switch (cp.getCommandType())
		{
		case CommandType::OPEN:
			try
			{
				openFile(cp.atToken(1));
			}
			catch (const invalid_argument& e)
			{
				cout << e.what() << endl;
				break;
			}

			cout << "Successfully opened " << cp.atToken(1) << endl;
			break;
		case CommandType::CLOSE:

			break;
		case CommandType::SAVE:

			break;
		case CommandType::NEW:

			break;
		case CommandType::SAVEAS:

		case CommandType::PRINT:
			try
			{
				m_table.print();
			}
			catch (const std::exception& e)
			{
				cout << e.what() << endl;
			}
			break;
		case CommandType::EXIT:
			cout << "Exiting the program...";
			return;
		default:
			break;
		}
	}
}

DocumentHandler::~DocumentHandler() {
	if (m_reader.is_open())
	{
		m_reader.close();
	}

	if (m_writer.is_open())
	{
		m_writer.close();
	}
}