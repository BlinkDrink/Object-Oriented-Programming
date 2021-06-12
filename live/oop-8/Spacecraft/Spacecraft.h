#pragma once
#include <string>
#include <fstream>
#include <iostream>
using std::string;
using std::ifstream;
using std::ofstream;

class Spacecraft
{
public:
	Spacecraft(size_t year = 0, const string& name = "");

	void serialize(ofstream& out) const;
	void deserialize(ifstream& in);

	inline size_t getYear() const { return m_year; };
	inline const string& getName() const { return m_name; };

private:
	size_t m_year;
	string m_name;
};

std::ostream& operator<<(std::ostream& out, const Spacecraft& obj);
