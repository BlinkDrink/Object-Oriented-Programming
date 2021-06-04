#include "StringHelper.h"

vector<string> StringHelper::splitBy(string source, const string& delimiter) const {
	vector<string> words;
	size_t pos = 0;

	if (source.find(delimiter) == string::npos && !source.empty())
	{
		words.push_back(source);
		return words;
	}

	while ((pos = source.find(delimiter)) != string::npos) {
		words.push_back(source.substr(0, pos));
		source.erase(0, pos + delimiter.length());

		if (pos = source.find(delimiter) == string::npos)
		{
			words.push_back(source);
		}
	}

	return words;
}

bool StringHelper::isStringInteger(const string& source) const {
	if (source.empty())
	{
		return false;
	}

	for (size_t i = 0; i < source.size(); i++)
		if (!isdigit(source[i]))
			return false;

	return true;
}

bool StringHelper::isStringDouble(const string& source) const {
	if (source.empty())
	{
		return false;
	}

	size_t numberOfDots = 0;

	for (size_t i = 0; i < source.size(); i++)
	{
		if (source[i] == '.')
		{
			numberOfDots++;
		}
	}

	if (numberOfDots != 1)
	{
		return false;
	}

	vector<string> parts = splitBy(source, ".");
	removeEmptyStringsInVector(parts);

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

//TODO: FIX
bool StringHelper::isStringValidFormula(const string& source) const {
	if (source.empty() || source[0] != '=')
	{
		return false;
	}

	string cpy(source);
	trim(cpy);
	cpy.erase(cpy.begin());
	addSpaceInBetweenWords(cpy);

	vector<string> parts = splitBy(cpy, " ");
	removeEmptyStringsInVector(parts);

	// Check first and last symbols to evaluate their correctness
	if (parts[0] == "/" || parts[0] == "*" || parts[0] == "^" || parts[parts.size() - 1] == "/" || parts[parts.size() - 1] == "*" || parts[parts.size() - 1] == "^" ||
		parts[parts.size() - 1] == "+" || parts[parts.size() - 1] == "-" || !isValidFormulaMember(parts[0]) || !isValidFormulaMember(parts[parts.size() - 1]))
	{
		return false;
	}

	for (size_t i = 1; i < parts.size() - 1; i++)
	{
		trim(parts[i]);
		if (!isValidFormulaMember(parts[i]))
		{
			return false;
		}

		if (parts[i] == "+" || parts[i] == "-" || parts[i] == "/" || parts[i] == "*" || parts[i] == "^")
		{
			if ((isStringInteger(parts[i - 1]) || isStringDouble(parts[i - 1]) || isStringValidString(parts[i - 1])) && (isStringDouble(parts[i + 1]) || isStringValidString(parts[i + 1]) || isStringInteger(parts[i + 1])))
			{
				continue;
			}
			else
			{
				return false;
			}

			/*if ((!isStringInteger(parts[i - 1]) && !isStringDouble(parts[i - 1]) && !isStringValidString(parts[i - 1])) || (!isStringDouble(parts[i + 1]) && !isStringValidString(parts[i + 1]) && !isStringInteger(parts[i + 1])))
			{
				return false;
			}*/
		}
	}

	return true;
}

bool StringHelper::isValidFormulaMember(const string& member) const {
	if (member == "+" || member == "-" || member == "/" || member == "*" || member == "^" || isStringDouble(member) || isStringInteger(member) || isStringValidString(member))
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
	if (source.size() < 2 || source.empty() || source[0] != '"' || source[source.size() - 1] != '"')
	{
		return false;
	}

	return true;
}

void StringHelper::removeQuotations(string& source) const {
	if (!isStringValidString(source))
	{
		return;
	}

	source.erase(source.begin());
	source.erase(source.end() - 1);
}

string StringHelper::calculateEquationInString(string source) const {
	if (source.empty())
	{
		return "#ERROR";
	}
	source.insert(source.begin(), '=');

	if (!isStringValidFormula(source))
	{
		return "#ERROR";
	}
	source.erase(source.begin());

	addSpaceInBetweenWords(source);
	trim(source);
	vector<string> parts = splitBy(source, " ");
	removeEmptyStringsInVector(parts);

	// Check if equation contains strings
	// If so, remove it's quotations and check if it is a valid int or double
	for (size_t i = 0; i < parts.size(); i++)
	{
		if (isStringValidString(parts[i]))
		{
			removeQuotations(parts[i]);
			if (!isStringDouble(parts[i]) && !isStringInteger(parts[i]))
			{
				parts[i] = "0";
			}
		}
	}

	if (!isStringInteger(parts[0]) && !isStringDouble(parts[0]))
	{
		parts[1].insert(parts[1].begin(), parts[0][0]);
		parts.erase(parts.begin());
	}

	bool hasNumbers = false;

	for (size_t i = 0; i < parts.size(); i++)
	{
		if (isStringDouble(parts[i]) || isStringInteger(parts[i]))
		{
			hasNumbers = true;
			break;
		}
	}

	if (!hasNumbers)
	{
		return "#ERROR";
	}

	// Power first
	while (containsPower(parts))
	{
		for (size_t i = 1; i < parts.size() - 1; i++)
		{
			if (parts[i] == "^")
			{
				parts[i - 1] = std::to_string(pow(stod(parts[i - 1]), stod(parts[i + 1])));
				parts.erase(parts.begin() + i);
				parts.erase(parts.begin() + i);
				break;
			}
		}
	}

	// Multiplication second
	while (containsMultiplication(parts))
	{
		for (size_t i = 1; i < parts.size() - 1; i++)
		{
			if (parts[i] == "*")
			{
				parts[i - 1] = std::to_string(stod(parts[i - 1]) * stod(parts[i + 1]));
				parts.erase(parts.begin() + i);
				parts.erase(parts.begin() + i);
				break;
			}
		}
	}

	// Division third
	while (containsDivision(parts))
	{
		for (size_t i = 1; i < parts.size() - 1; i++)
		{
			if (parts[i] == "/")
			{
				if (stod(parts[i + 1]) == 0)
				{
					return "#ERROR";
				}

				parts[i - 1] = std::to_string(stod(parts[i - 1]) / stod(parts[i + 1]));
				parts.erase(parts.begin() + i);
				parts.erase(parts.begin() + i);
				break;
			}
		}
	}

	// Subtraction and Addition last
	while (containsAditionOrSubtraction(parts))
	{
		for (size_t i = 1; i < parts.size() - 1; i++)
		{
			if (parts[i] == "+")
			{
				parts[i - 1] = std::to_string(stod(parts[i - 1]) + stod(parts[i + 1]));
				parts.erase(parts.begin() + i);
				parts.erase(parts.begin() + i);
				break;
			}
			else if (parts[i] == "-")
			{
				parts[i - 1] = std::to_string(stod(parts[i - 1]) - stod(parts[i + 1]));
				parts.erase(parts.begin() + i);
				parts.erase(parts.begin() + i);
				break;
			}
		}
	}

	return parts[0];
}

bool StringHelper::containsPower(const vector <string>& parts) const {
	for (size_t i = 0; i < parts.size(); i++)
	{
		if (parts[i] == "^")
		{
			return true;
		}
	}

	return false;
}

bool StringHelper::containsMultiplication(const vector<string>& parts) const {
	for (size_t i = 0; i < parts.size(); i++)
	{
		if (parts[i] == "*")
		{
			return true;
		}
	}

	return false;
}

bool StringHelper::containsDivision(const vector<string>& parts) const {
	for (size_t i = 0; i < parts.size(); i++)
	{
		if (parts[i] == "/")
		{
			return true;
		}
	}

	return false;
}

bool StringHelper::containsAditionOrSubtraction(const vector<string>& parts) const {
	for (size_t i = 0; i < parts.size(); i++)
	{
		if (parts[i] == "+" || parts[i] == "-")
		{
			return true;
		}
	}

	return false;
}

void StringHelper::removeEmptyStringsInVector(vector<string>& parts) const {
	for (size_t i = 0; i < parts.size(); i++)
	{
		if (parts[i].empty())
		{
			parts.erase(parts.begin() + i);
			i--;
		}
	}
}

string StringHelper::getStringFilledWithSpaces(size_t num_of_spaces) const {
	string s;
	for (size_t i = 0; i < num_of_spaces; i++)
	{
		s.push_back(' ');
	}
	return s;
}

void StringHelper::addSpaceInBetweenWords(string& source) const {
	for (size_t i = 0; i < source.size(); i++)
	{
		if (!isdigit(source[i]) && !isalpha(source[i]) && source[i] != '.' && source[i] != ' ' && source[i] != '"')
		{
			source.insert(source.begin() + i, ' ');
			source.insert(source.begin() + i + 2, ' ');
			i += 2;
		}
	}
}