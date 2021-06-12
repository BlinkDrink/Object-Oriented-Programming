#include "ReadableBuffer.h"
#include<cstring>
#include<iostream>

using std::strlen;
using std::bad_alloc;
using std::out_of_range;
using std::cout;

ReadableBuffer::ReadableBuffer(const char* other) : size(strlen(other)) {
	try
	{
		buffer = new char[size + 1];
	}
	catch (const bad_alloc& e)
	{
		buffer = nullptr;
		throw e;
	}

	strcpy_s(buffer, size + 1, other);
}

void ReadableBuffer::copyFrom(const ReadableBuffer& other) {
	size = other.size;
	strcpy_s(buffer, size + 1, other.buffer);
}

ReadableBuffer::ReadableBuffer(const ReadableBuffer& other) {
	copyFrom(other);
}

ReadableBuffer& ReadableBuffer::operator=(const ReadableBuffer& other) {
	if (this != &other)
	{
		clear();
		copyFrom(other);
	}

	return *this;
}

void ReadableBuffer::clear() {
	delete[] buffer;
	size = 0;
}

size_t ReadableBuffer::getSize() const { return size; }

void ReadableBuffer::write(ostream& out, size_t from, size_t to) const {
	if (from >= size || to >= size)
	{
		throw out_of_range("Index out of range.");
	}

	for (size_t i = from; i <= to; i++)
	{
		out << buffer[i];
	}
}

const char& ReadableBuffer::operator[](size_t pos) const {
	if (pos >= size)
	{
		throw out_of_range("Index out of range.");
	}

	return buffer[pos];
}

ReadableBuffer::~ReadableBuffer() {
	delete[] buffer;
}

ostream& operator<<(ostream& out, const ReadableBuffer& other) {
	out << other.buffer;

	return out;
}
