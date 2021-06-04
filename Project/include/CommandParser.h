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
	/*
	*	@brief Default constructor
	*/
	CommandParser();

	/*
	*	@brief Initializes raw with str. Calls tokenizeInnerString on the newly initialized raw.
	*
	*	@param str - string to initialize raw with
	*/
	CommandParser(const string& str);

	/*
	*	@brief Populates raw using std::getline()
	*/
	void readCmd();

	/*
	*	@brief Splits raw into parts(tokens) and pushes them inside tokens private member.
	*/
	void tokenizeInnerString();

	/*
	*	@brief Converts all small alphabetic characters to capital characters.
	*
	*	@param str - string to be Uppered
	*	@returns string with all lowercase letters converted to uppercase letters
	*/
	const string toUpper(const string& str) const;

	/*
	*	@brief Getter
	*	@returns returns raw string
	*/
	string& getRaw();

	/*
	*	@brief Getter
	*
	*	@returns size of tokens
	*/
	size_t size() const;

	/*
	*	@brief Getter. Throws out_of_range if pos is invalid
	*
	*	@param pos - index to be accessed
	*	@returns the element at index pos
	*/
	const string& atToken(size_t pos) const;

	/*
	*	@brief Clears raw, leaves it empty. Clears tokens, leaves it empty
	*/
	void clearCmd();

	/*
	*	@returns the type of the input command
	*/
	CommandType getCommandType() const;
};