#include "ReadWriteBuffer.h"

using std::out_of_range;
using std::cin;
using std::invalid_argument;

char& ReadWriteBuffer::operator[](size_t pos) {
	if (pos >= this->getSize())
	{
		throw out_of_range("Index out of range.");
	}

	return const_cast<char&>(ReadableBuffer::operator[](pos));
}

size_t ReadWriteBuffer::read(istream& in, size_t from, size_t to) {
	if (from >= getSize() || to >= getSize())
	{
		throw out_of_range("Index out of range.");
	}

	if (to < from)
	{
		throw invalid_argument("Start position cannot be greater than end position.");
	}

	for (size_t i = from; i <= to; i++)
	{
		char c;
		in >> c;
		this->operator[](i) = c;
	}

	return to - from;
}

void ReadWriteBuffer::shuffleForFun() {
	for (size_t i = 0; i < getSize(); i++)
	{
		operator[](i) = operator[](getSize() - i - 1);
	}
}

istream& operator>>(istream& in, ReadWriteBuffer& buff) {
	char buffer[200];
	in >> buffer;
	buff = buffer;

	return in;
}

