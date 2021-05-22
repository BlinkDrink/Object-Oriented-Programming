#pragma once
#include<string>
#include<vector>
#include "CommandType.h"

using std::string;
using std::vector;

class CommandParser {
private:
	string raw;
	vector<string> tokens;
public:
	CommandParser();
	CommandParser(const string& str);

	void readCmd();
	void tokenizeInnerString();
	void toUpper(string& str);
	void cmdToUpper();

	string& getRaw();
	size_t size() const;
	const string& atToken(size_t pos) const;
	void clearCmd();

	CommandType getCommandType() const;
};