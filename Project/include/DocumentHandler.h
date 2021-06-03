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
	bool m_isSaved;

	DocumentHandler();

	void populateTableFromFile();
	void menu() const;
public:
	static DocumentHandler& getInstance();

	DocumentHandler(const DocumentHandler& other) = delete;
	DocumentHandler& operator=(const DocumentHandler& other) = delete;
	DocumentHandler(DocumentHandler&& other) = delete;
	DocumentHandler& operator=(DocumentHandler&& other) = delete;

	void openFile(const string& path);
	void closeFile();
	void saveToFile();

	void run();

	~DocumentHandler();
};