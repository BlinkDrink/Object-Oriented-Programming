#pragma once
#include<string>

using std::string;

class Registration {
private:
	string reg;

	/**
	*	Private class method, used to validate whether a registration
	*	number is valid or not.
	*
	*	@param s - string to be validated
	*/
	bool isRegValid(const string& s);
public:
	/**
	*	Constructor with const char * argument.
	*	Initialized registration number with the given str.
	*	Throws if str is invalid reg number.
	*/
	Registration(const string& str);

	/**
	*	Assignment operator, used to copy contents of str into the current
	*	object.
	*
	*	@param str - string to be copied
	*/
	Registration& operator=(const Registration& str);

	/**
	*	Operator== used to compare two strings.
	*
	*	@param reg - registration to be compared with
	*/
	bool operator==(const Registration& reg) const;

	/**
	*	Class method, returns pointer to the string holding the
	*	registration number inside the object.
	*/
	const string& toString() const;
};