#include<iostream>
#include<fstream>
#include<string>

using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::getline;

int main() {
	string path = "test.txt";

	ifstream in(path);
	if (!in)
	{
		cout << "Couldn't open file for reading.";
		return 1;
	}

	in.seekg(0, in.end);
	int length = in.tellg();
	in.seekg(0, in.beg);

	int linesCount = 0;
	string line;

	while (getline(in, line))
	{
		linesCount++;
		cout << line << '\n';
	}

	cout << "Lines count: " << linesCount << '\n';
	cout << "TotalBytes : " << length;


	return 0;
}