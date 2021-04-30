#include "MyString.h"
#include<iostream>
#include<cstring>
#define NDEBUG
#include<cassert>

MyString::MyString()
{
	this->capacity = 1;
	this->length = 0;
	this->myString = new char[this->capacity];

	if (!this->myString)
	{
		return;
	}

	this->myString[0] = 0;
}

MyString::MyString(const MyString& src)
{
	delete[] this->myString;
	this->length = src.length;
	this->capacity = src.capacity;
	this->myString = new char[this->capacity];

	strcpy_s(this->myString, sizeof(char) * (src.length + 1), src.myString);
}

MyString::MyString(MyString&& src) noexcept
{
	this->myString = src.myString;
	this->capacity = src.capacity;
	this->length = src.length;
	src.myString = nullptr;
	src.length = 0;
	src.capacity = 0;
}

MyString& MyString::operator=(const MyString& src)
{
	if (this == &src)
	{
		return *this;
	}

	delete[] this->myString;
	this->length = src.length;
	this->capacity = src.capacity;
	this->myString = new char[this->capacity];

	strcpy_s(this->myString, sizeof(char) * (src.length + 1), src.myString);

	return *this;
}

MyString& MyString::operator=(MyString&& src) noexcept
{
	if (this == &src)
	{
		return *this;
	}

	delete[] this->myString;
	this->length = src.length;
	this->capacity = src.capacity;
	this->myString = src.myString;
	src.myString = nullptr;
	src.length = 0;
	src.capacity = 0;

	return *this;
}

MyString::~MyString()
{
	delete[] this->myString;
}

MyString::MyString(const char* str)
{
	if (str == nullptr)
	{
		throw std::invalid_argument("Cannot accept nullptr argument.");
	}

	unsigned strLength = strlen(str);

	this->capacity = strLength + 1;
	this->length = strLength;
	this->myString = new char[capacity];

	if (!this->myString)
	{
		return;
	}

	strcpy_s(this->myString, sizeof(char) * (strLength + 1), str);
}

char& MyString::at(size_t pos)
{
	if (pos >= this->length)
	{
		throw std::out_of_range("Index is out of range.");
	}

	return this->myString[pos];
}

const char& MyString::at(size_t pos) const
{
	if (pos >= this->length)
	{
		throw std::out_of_range("Index is out of range.");
	}

	return this->myString[pos];
}

size_t MyString::size() const
{
	return this->length;
}

char& MyString::operator[](std::size_t pos)
{
	assert(pos < this->length);
	return this->myString[pos];
}

const char& MyString::operator[](std::size_t pos) const
{
	assert(pos < this->length);
	return this->myString[pos];
}

char& MyString::front()
{
	assert(this->length > 0);
	return this->myString[0];
}

const char& MyString::front() const
{
	assert(this->length > 0);
	return this->myString[0];
}

char& MyString::back()
{
	assert(this->length > 0);
	return this->myString[this->length - 1];
}

const char& MyString::back() const
{
	assert(this->length > 0);
	return this->myString[this->length - 1];
}

bool MyString::empty() const
{
	return this->length == 0;
}

void MyString::clear()
{
	for (size_t i = 0; i < this->length; i++)
	{
		this->myString[i] = 0;
	}
	this->length = 0;
}

void MyString::resize() {
	char* updatedString = new char[this->capacity * 2];

	for (size_t i = 0; i < this->length; i++)
	{
		updatedString[i] = this->myString[i];
	}

	delete[] this->myString;
	this->myString = updatedString;
	this->capacity *= 2;
}

void MyString::push_back(char c)
{
	if (c == 0)
	{
		throw std::invalid_argument("Invalid argument. Cannot push_back() null terminated symbol.");
	}

	if (this->length + 1 >= this->capacity)
	{
		try
		{
			resize();
		}
		catch (const std::bad_alloc& e)
		{
			throw e;
		}
	}

	this->myString[this->length] = c;
	this->myString[this->length + 1] = '\0';
	this->length++;
}

void MyString::pop_back()
{
	assert(this->length > 0);
	if (this->length != 0)
	{
		this->myString[this->length - 1] = '\0';
		this->length--;
	}
}

MyString& MyString::operator+=(char c)
{
	push_back(c);

	return *this;
}

MyString& MyString::operator+=(const MyString& rhs)
{
	if (rhs.length == 0)
	{
		return *this;
	}

	for (size_t i = 0; i < rhs.length; i++)
	{
		push_back(rhs[i]);
	}

	return *this;
}

MyString MyString::operator+(char c) const
{
	MyString str(*this);
	str += c;

	return str;
}

MyString MyString::operator+(const MyString& rhs) const
{
	MyString str(*this);
	str += rhs;

	return str;
}

const char* MyString::c_str() const
{
	return this->myString;
}

bool MyString::operator==(const MyString& rhs) const
{
	return strcmp(this->myString, rhs.myString) == 0;
}

bool MyString::operator<(const MyString& rhs) const
{
	return strcmp(this->myString, rhs.myString) < 0;
}
