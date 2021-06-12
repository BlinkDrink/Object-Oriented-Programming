#include<iostream>
#include "Jedi.h"

size_t Jedi::m_versionCount = 0;

int main() {
	vector<string> skills1 = { "Levitate", "Jump" };
	vector<string> skills2 = { "Dash", "Slice" };

	Jedi j(skills1);
	Jedi j1(skills2);

	j.write("input.txt");
	j1.write("input.txt");

	return 0;
}