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
	/**
	*	Default constructor
	*/
	CommandParser();

	/**
	*	Initializes raw with str.
	*	Calls tokenizeInnerString on the newly initialized raw.
	*
	*	@param str - string to initialize raw with
	*/
	CommandParser(const string& str);

	/**
	*	Populates raw using std::getline()
	*/
	void readCmd();

	/**
	*	Splits raw into parts(tokens) and pushes them inside tokens private member.
	*/
	void tokenizeInnerString();

	/**
	*	Converts all small alphabetic characters to capital characters.
	*
	*	@param str - string to be Uppered
	*/
	const string toUpper(const string& str) const;

	/**
	*	Getter
	*	returns raw string
	*/
	string& getRaw();

	/**
	*	Getter
	*
	*	returns size of tokens
	*/
	size_t size() const;

	/**
	*	Getter
	*	Throws out_of_range if pos is invalid
	*
	*	@param pos - index to be accessed
	*	returns the element at index pos
	*/
	const string& atToken(size_t pos) const;

	/**
	*	Clears raw    - leaves it empty
	*	Clears tokens - leaves it empty
	*/
	void clearCmd();

	CommandType getCommandType() const;
};