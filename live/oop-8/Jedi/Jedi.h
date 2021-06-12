#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::string;

class Jedi {
private:
	char** m_skills;
	size_t skillsCount = 0;

	size_t m_version;
	static size_t m_versionCount; // posrednik

	static size_t incrementVersion();
public:
	Jedi(vector<string> skills);
	~Jedi();

	void read(const char* filename);
	void write(const char* filename);
	size_t getVersion();
};


