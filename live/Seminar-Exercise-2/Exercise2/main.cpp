#include "ReadWriteBuffer.h"
#include<fstream>
#include<string>

using std::cin;
using std::cout;
using std::ifstream;
using std::string;
using std::getline;

int main() {
	ifstream file("text.txt");
	string s;
	string final;

	while (getline(file, s))
	{
		final += s + '\n';
	}

	ReadWriteBuffer buffer(final.c_str());
	buffer.shuffleForFun();
	cout << buffer;

	return 0;
}