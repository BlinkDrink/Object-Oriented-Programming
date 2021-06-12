#include<iostream>

using std::ostream;

class ReadableBuffer {
private:
	char* buffer;
	size_t size;

	void copyFrom(const ReadableBuffer& other);
public:
	ReadableBuffer(const char* other);
	ReadableBuffer(const ReadableBuffer& other);
	ReadableBuffer& operator=(const ReadableBuffer& other);
	~ReadableBuffer();

	void clear();
	size_t getSize() const;
	const char& operator[](size_t pos) const;
	void write(ostream& out, size_t from, size_t to) const;

	friend ostream& operator<<(ostream& out, const ReadableBuffer& other);
};