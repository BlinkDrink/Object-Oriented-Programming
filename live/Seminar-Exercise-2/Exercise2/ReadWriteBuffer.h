#include "ReadableBuffer.h"

using std::istream;

class ReadWriteBuffer : public ReadableBuffer {
public:
	ReadWriteBuffer(const char* other) : ReadableBuffer(other) {}

	char& operator[](size_t pos);
	size_t read(istream& in, size_t from, size_t to);
	void shuffleForFun();
	friend istream& operator>>(istream& in, ReadWriteBuffer& buff);
};