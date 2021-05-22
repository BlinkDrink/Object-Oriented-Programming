#include "CommandParser.h"
#include <iostream>

using std::cin;
using std::getline;
using std::invalid_argument;

CommandParser::CommandParser() {
}

CommandParser::CommandParser(const string& str) {
	raw = str;
	tokenizeInnerString();
}

void CommandParser::tokenizeInnerString() {
	size_t tokensWordInd = 0;
	size_t numWhiteSpaces = 0;
	size_t i = 0;


	/*for (size_t i = 0; i < raw.size(); i++)
	{
		if (i == 0)
		{
			while (raw[i] == ' ')
			{
				i++;
				tokensWordInd++;
			}
		}

		if (raw[i] == '"')
		{
			tokensWordInd = i + 1;
			i++;
			while (raw[i] != '"')
			{
				i++;
			}
			tokens.push_back(raw.substr(tokensWordInd, i - tokensWordInd));
			tokensWordInd = i + 1;
		}
		else if (raw[i] == ' ')
		{
			while (raw[i] == ' ')
			{
				i++;
				numWhiteSpaces++;
			}
			tokens.push_back(raw.substr(tokensWordInd, i - tokensWordInd - numWhiteSpaces));
			tokensWordInd = i;
			numWhiteSpaces = 0;
			i--;
		}
		else if (i == (raw.size() - 1))
		{
			tokens.push_back(raw.substr(tokensWordInd, i - tokensWordInd + 1));
		}
	}*/

	while (raw[i])
	{
		if (raw[i] == '"')
		{
			tokensWordInd = i + 1;
			i++;
			while (raw[i] != '"')
			{
				i++;
			}
			tokens.push_back(raw.substr(tokensWordInd, i - tokensWordInd));
			i++;
		}
		else if (raw[i] == ' ')
		{
			while (raw[i] == ' ')
			{
				i++;
			}
		}
		else
		{
			tokensWordInd = i;
			while (isalpha(raw[i]) | isdigit(raw[i]))
			{
				i++;
			}
			tokens.push_back(raw.substr(tokensWordInd, i - tokensWordInd));
		}
	}
}

void CommandParser::readCmd() {
	std::getline(cin, raw);
}

void CommandParser::toUpper(string& str) {
	for (size_t i = 0; i < tokens[0].size(); i++)
	{
		if (tokens[0][i] >= 'a' && tokens[0][i] <= 'z')
		{
			tokens[0][i] -= 'a' - 'A';
		}
	}
}

void CommandParser::cmdToUpper() {
	toUpper(tokens[0]);
}

const string& CommandParser::atToken(size_t pos) const {
	if (pos >= tokens.size())
	{
		throw invalid_argument("Command out of range. There are not enough arguments.");
	}

	return tokens[pos];
}

size_t CommandParser::size() const {
	return tokens.size();
}

string& CommandParser::getRaw() {
	return raw;
}

CommandType CommandParser::getCommandType() const {
	if (tokens.empty() || tokens[0].empty())
	{
		return NOCOMMAND;
	}

	if (tokens[0] == "VEHICLE")
	{
		return VEHICLE;
	}
	else if (tokens[0] == "PERSON")
	{
		return PERSON;
	}
	else if (tokens[0] == "ACQUIRE")
	{
		return ACQUIRE;
	}
	else if (tokens[0] == "RELEASE")
	{
		return RELEASE;
	}
	else if (tokens[0] == "REMOVE")
	{
		return REMOVE;
	}
	else if (tokens[0] == "SAVE")
	{
		return SAVE;
	}
	else if (tokens[0] == "SHOW")
	{
		return SHOW;
	}
	else {
		return EXIT;
	}
}

void CommandParser::clearCmd() {
	raw.clear();
	tokens.clear();
}