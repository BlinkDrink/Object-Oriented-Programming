#pragma once
#include<string>
#include<vector>

using std::string;
using std::vector;

class StringHelper {
private:
public:
	/*
	*	@brief Splits a given string(source) into parts by given delimeter
	*
	*	@param source    - string to be splited
	*	@param delimeter - what to split it by
	*
	*	@returns vector<string> filled with the splited parts
	*/
	vector<string> splitBy(string source, const string& delimeter) const;

	/*
	*	@brief Checks if a given string is valid integer number.
	*
	*	@params source - string to be checked
	*	@returns true if valid, false othwerwise
	*/
	bool isStringInteger(const string& source) const;

	/*
	*	@brief Checks if a given string is valid real number.
	*
	*	@params source - string to be checked
	*	@returns true if valid, false othwerwise
	*/
	bool isStringDouble(const string& source) const;

	/*
	*	@brief Checks if a string is valid table formula
	*
	*	@params source - to be checked
	*	@returns true if valid, false otherwise
	*/
	bool isStringValidFormula(const string& source) const;

	/*
	*	@brief Removes leading and ending whitespaces
	*
	*	@param source - string to be trimmed
	*	@returns trimmed source
	*/
	string& trim(string& source) const;

	/*
	*	@brief Checks if given string is valid formula member
	*
	*	@param member - string to be checked
	*	@returns true if valid, false otherwise
	*/
	bool isValidFormulaMember(const string& member) const;

	/*
	*	@brief Checks if a given string is valid string format
	*
	*	@param source - string to be checked
	*	@returns true if valid, false otherwise
	*/
	bool isStringValidString(const string& source) const;
};