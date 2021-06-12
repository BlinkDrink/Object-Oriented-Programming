#include "Jedi.h"
#include<fstream>
#include<cstring>

using std::ofstream;
using std::ifstream;

size_t Jedi::incrementVersion() {
	return m_versionCount++;
}

Jedi::Jedi(vector<string> skills) : m_version(incrementVersion()) {
	m_skills = new char* [skills.size()];

	for (size_t i = 0; i < skills.size(); i++)
	{
		size_t skillSize = skills[i].size();

		m_skills[i] = new char[skillSize + 1];
		for (size_t j = 0; j < skills[i].size(); j++)
		{
			m_skills[i][j] = skills[i][j];
		}
		m_skills[i][skillSize] = '\0';
	}

	skillsCount = skills.size();
}

size_t Jedi::getVersion() {
	return m_version;
}

void Jedi::read(const char* filename) {
	if (!filename)
	{
		throw std::exception("Please provide a valid file name.");
	}

	ifstream in(filename);
	if (!filename)
	{
		throw std::exception("Couldn't open file for reading.");
	}

	string line;

	in >> line;
	for (size_t i = 0; i < line.size(); i++)
	{
		if (line[i] == ' ')
		{

		}
	}
}

void Jedi::write(const char* filename) {
	if (!filename)
	{
		throw std::exception("Please give a valid file input.");
	}

	ofstream out(filename, std::ios_base::app);
	if (!out)
	{
		throw std::exception("Couldn't open file for reading.");
	}

	for (size_t i = 0; i < skillsCount; i++)
	{
		out << m_skills[i] << " ";
	}

	out << '\n';
	out << m_version;
	out << '\n';

	out.close();
}

Jedi::~Jedi() {
	for (size_t i = 0; i < skillsCount; i++)
	{
		delete[] m_skills[i];
	}

	delete[] m_skills;
}