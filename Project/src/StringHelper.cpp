#include "StringHelper.h"

vector<string> StringHelper::splitBy(string source, const string& delimeter) const {
	vector<string> words;
	size_t pos = 0;

	while ((pos = source.find(delimeter)) != string::npos) {
		words.push_back(source.substr(0, pos));
		source.erase(0, pos + delimeter.length());
	}
	words.push_back(source);

	return words;
}

bool StringHelper::isStringInteger(const string& source) const {
	if (source.empty())
	{
		return false;
	}

	for (size_t i = 0; i < source.length(); i++)
		if (isdigit(source[i]) == false)
			return false;

	return true;
}

bool StringHelper::isStringDouble(const string& source) const {
	if (source.empty())
	{
		return false;
	}
	vector<string> parts = splitBy(source, ".");

	if (parts.size() != 2)
	{
		return false;
	}

	for (size_t i = 0; i < parts.size(); i++)
	{

		for (size_t j = 0; j < parts[i].size(); j++)
		{
			if (parts[i][j] != '.' && !isdigit(parts[i][j]))
			{
				return false;
			}
		}
	}

	return true;
}

bool StringHelper::isStringValidFormula(const string& source) const {
	if (source.empty() || source[0] != '=')
	{
		return false;
	}

	vector<string> parts = splitBy(source, " ");
	parts.erase(parts.begin());
	for (size_t i = 0; i < parts.size(); i++)
	{
		trim(parts[i]);
		if (!isValidFormulaMember(parts[i]))
		{
			return false;
		}

		if (parts[i] == "+" || parts[i] == "-" || parts[i] == "/" || parts[i] == "*" || parts[i] == "^")
		{
			if (i == 0 || i == parts.size() - 1)
			{
				return false;
			}
			if ((!isStringInteger(parts[i - 1]) && !isStringDouble(parts[i - 1])) || (!isStringDouble(parts[i + 1]) && !isStringInteger(parts[i + 1])))
			{
				return false;
			}
		}
	}

	return true;
}

bool StringHelper::isValidFormulaMember(const string& member) const {
	if (member == "+" || member == "-" || member == "/" || member == "*" || member == "^" || isStringDouble(member) || isStringInteger(member))
	{
		return true;
	}

	return false;
}

string& StringHelper::trim(string& source) const {
	if (source.empty())
	{
		return source;
	}

	size_t start = 0;

	while (source[start] == ' ')
	{
		source.erase(source.begin() + start);
	}

	size_t end = source.size() > 0 ? source.size() - 1 : 0;

	while (source[end] == ' ')
	{
		source.erase(source.begin() + end);
		end--;
	}

	return source;
}

bool StringHelper::isStringValidString(const string& source) const {
	if (source.empty() || source[0] != '"' || source[source.size() - 1] != '"')
	{
		return false;
	}

	return true;
}