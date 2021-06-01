#include <iostream>
#include "../include/CommandParser.h"

using std::cin;
using std::getline;
using std::invalid_argument;
using std::out_of_range;

CommandParser::CommandParser()
{
}

CommandParser::CommandParser(const string &str)
{
	raw = str;
	tokenizeInnerString();
}

void CommandParser::tokenizeInnerString()
{
	size_t tokensWordInd = 0;
	size_t numWhiteSpaces = 0;
	size_t i = 0;

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
			while (isalpha(raw[i]) | isdigit(raw[i]) || raw[i] == '.' || raw[i] == '\\' || raw[i] == '/')
			{
				i++;
			}
			tokens.push_back(raw.substr(tokensWordInd, i - tokensWordInd));
		}
	}
}

void CommandParser::readCmd()
{
	std::getline(cin, raw);
}

const string CommandParser::toUpper(const string &str) const
{
	string item;
	item = str;
	for (size_t i = 0; i < item.size(); i++)
	{
		if (item[i] >= 'a' && item[i] <= 'z')
		{
			item[i] -= 'a' - 'A';
		}
	}

	return item;
}

const string &CommandParser::atToken(size_t pos) const
{
	if (pos >= tokens.size())
	{
		throw out_of_range("Command out of range. There are not enough arguments.");
	}

	return tokens[pos];
}

size_t CommandParser::size() const
{
	return tokens.size();
}

string &CommandParser::getRaw()
{
	return raw;
}

CommandType CommandParser::getCommandType() const
{
	if (tokens.size() == 0)
	{
		return CommandType::NOCOMMAND;
	}

	if (tokens[0].size() == 0)
	{
		return CommandType::NOCOMMAND;
	}

	string cmd = toUpper(tokens[0]);

	if (cmd == "OPEN")
	{
		return CommandType::OPEN;
	}

	return CommandType::NOCOMMAND;
}

void CommandParser::clearCmd()
{
	raw.clear();
	tokens.clear();
}