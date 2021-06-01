#include <iostream>
#include <string>
#include "../include/DocumentHandler.h"

using std::cin;
using std::cout;
using std::invalid_argument;
using std::string;

DocumentHandler::DocumentHandler() : isSaved(false)
{
}

void DocumentHandler::openFile(const string &path)
{
	reader.open(path);

	if (!reader.is_open())
	{
		throw invalid_argument("Couldn't open file for reading.");
	}

	writer.open(path);

	if (!writer.is_open())
	{
		throw invalid_argument("Couldn't link current document with the file.");
	}
}

void DocumentHandler::closeFile()
{
	if (writer.is_open())
	{
		if (!isSaved)
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
				else if (choice == 'd')
				{
					writer.close();
				}
				else if (choice == 'c')
				{
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
			writer.close();
		}
	}
}

void DocumentHandler::saveToFile()
{
	if (!writer.is_open())
	{
		throw invalid_argument("Currently there is no file linked to this document.");
	}

	// TODO: Implement save table to file

	isSaved = true;
}

DocumentHandler::~DocumentHandler()
{
	if (reader.is_open())
	{
		reader.close();
	}

	if (writer.is_open())
	{
		writer.close();
	}
}