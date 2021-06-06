#pragma once
#include<fstream>
#include<string>
#include "Table.h"

using std::ifstream;
using std::ofstream;
using std::string;

/*
*	@brief Singleton class, handles operations with files and Table.
*/
class DocumentHandler {
private:
	ifstream m_reader;
	ofstream m_writer;
	Table m_table;
	string filePath;
	bool m_isSaved;

	DocumentHandler();

	/*
	*	@brief Populates in memory table's cells from the currently opened file
	*/
	void populateTableFromFile();
	void menu() const;
public:
	static DocumentHandler& getInstance();

	DocumentHandler(const DocumentHandler& other) = delete;
	DocumentHandler& operator=(const DocumentHandler& other) = delete;
	DocumentHandler(DocumentHandler&& other) = delete;
	DocumentHandler& operator=(DocumentHandler&& other) = delete;

	/*
	*	@brief Finds rows and longest column of file and initializes empty table with them
	*/
	void initializeEmptyTable();

	/*
	*	@brief Reads through the file and initializes table cells
	*/
	void fillTableFromFile();

	/*
	*	@brief Attempts to open file with given path then populates table from the file
	*/
	void openFile(const string& path);

	/*
	*	@brief Attempts to close the opened file. If session hasn't been saved then it prompts the user for confirmation
	*	to either save/don't save/cancel. Clears in memory table.
	*/
	void closeFile();

	/*
	*	@brief Attempts to save the current table into the same file opened by openFile()
	*/
	void saveToFile();

	/*
	*	@brief Edits a cell at the given row and column with given content.
	*
	*	@param row	   - row of table
	*	@param col	   - column of table
	*	@param content - content with which it will be edited
	*/
	void editFile(size_t row, size_t col, const string& content);

	/*
	*	@brief Executes the main logic of the program
	*/
	void run();

	/*
	*	@brief Closes file associated with this document
	*/
	~DocumentHandler();
};