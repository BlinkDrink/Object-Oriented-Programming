#pragma once
#include <string>
#include <vector>
#include "./Pair.h"

using std::string;
using std::vector;

class StringHelper
{
public:
	/*
	*	@brief Splits a given string(source) into parts by given delimeter
	*
	*	@param source    - string to be splited
	*	@param delimeter - what to split it by
	*
	*	@returns vector<string> filled with the splited parts
	*/
	vector<string> splitBy(string source, const string &delimeter) const;

	/*
	*	@brief Checks if a given string is valid integer number.
	*
	*	@param source - string to be checked
	*	@returns true if valid, false othwerwise
	*/
	bool isStringInteger(const string &source) const;

	/*
	*	@brief Checks if a given string is valid real number.
	*
	*	@param source - string to be checked
	*	@returns true if valid, false othwerwise
	*/
	bool isStringDouble(const string &source) const;

	/*
	*	@brief Checks if a string is valid table formula
	*
	*	@param source - to be checked
	*	@returns true if valid, false otherwise
	*/
	bool isStringValidFormula(const string &source) const;

	/*
	*	@brief Removes leading and ending whitespaces
	*
	*	@param source - string to be trimmed
	*	@returns trimmed source
	*/
	string &trim(string &source) const;

	/*
	*	@brief Checks if given string is valid formula member
	*
	*	@param member - string to be checked
	*	@returns true if valid, false otherwise
	*/
	bool isValidFormulaMember(const string &member) const;

	/*
	*	@brief Checks if a given string is valid string format
	*
	*	@param source - string to be checked
	*	@returns true if valid, false otherwise
	*/
	bool isStringValidString(const string &source) const;

	/*
	*	@brief Removes opening and closing quotations of a given string, if there are any
	*
	*	@param source - string to have it's quotations removed
	*/
	void removeQuotations(string &source) const;

	/*
	*	@brief Calculates given equation in string
	*
	*	@param source - string to be calculated
	*	@returns result as string
	*/
	string calculateEquationInString(string source) const;

	/*
	*	@brief Checks if a vector of strings contains power sign(^)
	*
	*	@param parts - vector of strings to be check
	*	@returns true if contained, false otherwise
	*/
	bool containsPower(const vector<string> &parts) const;

	/*
	*	@brief Checks if a vector of strings contains multiplication sign
	*
	*	@param parts - vector of strings to be check
	*	@returns true if vector contains '*', false otherwise
	*/
	bool containsMultiplication(const vector<string> &parts) const;

	/*
	*	@brief Checks if a vector of strings contains division sign
	*
	*	@param parts - vector of strings to be check
	*	@returns true if vector contains '/', false otherwise
	*/
	bool containsDivision(const vector<string> &parts) const;

	/*
	*	@brief Checks if a vector of strings contains adition or subraction signs
	*
	*	@param parts - vector of strings to be check
	*	@returns true if vector contains '+' or '-', false otherwise
	*/
	bool containsAditionOrSubtraction(const vector<string> &parts) const;

	/*
	*	@brief Removes all empty strings from a vector of strings
	*
	*	@param parts - vector of strings to have it's empty strings removed
	*/
	void removeEmptyStringsInVector(vector<string> &parts) const;

	/*
	*	@brief Fills a string with num_of_spaces whitespaces
	*
	*	@param num_of_spaces - number of whitespaces to create
	*	@returns string filled with white spaces
	*/
	string getStringFilledWithSpaces(size_t num_of_spaces) const;

	/*
	*	@brief Adds whitespace between every 2 words/numbers. Only exception is '.'.
	*	Used to divide words/numbers with ' '.
	*
	*	@param source - string which numbers/words will be divided by whitespace
	*/
	void addSpaceInBetweenWords(string &source) const;

	/*
	*	@brief Checks if given string matches a cell adress type("A1" is valid but "AA1" is invalid)
	*
	*	@param source - string to be checked
	*/
	bool isStringValidCellAddress(string source) const;

	/*
	*	@brief Goes through a cell address and extracts rows and columns
	*
	*	@param source - string to have it's details extracted
	*	@returns pair of numbers, first one - rows, second one - columns
	*/
	Pair<size_t, size_t> extractCellAddressDetails(string source) const;

	/*
	*	@brief Enqote the given string
	*
	*	@param source - string to be enquoted
	*/
	void enquoteString(string &source) const;
};
