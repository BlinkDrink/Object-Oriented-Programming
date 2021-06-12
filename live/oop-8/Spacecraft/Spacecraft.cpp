#include "Spacecraft.h"

Spacecraft::Spacecraft(size_t year, const string& name)
	: m_year(year)
	, m_name(name)
{}

void Spacecraft::serialize(ofstream& out) const
{
	out.write((const char*)&m_year, sizeof(m_year));
	size_t len = m_name.size();
	out.write((const char*)&len, sizeof(len));
	out.write((const char*)&m_name, len);
}

void Spacecraft::deserialize(ifstream& in)
{
	in.read((char*)&m_year, sizeof(m_year));
	size_t len;
	in.read((char*)&len, sizeof(len));
	in.read((char*)&m_name, len);
}

std::ostream& operator<<(std::ostream& out, const Spacecraft& obj)
{
	out << obj.getYear() << ' ' << obj.getName();

	return out;
}
