#pragma once
#include<cstddef>

class MyString {
private:
	char* myString = nullptr;
	size_t length = 0;
	size_t capacity = 0;

	/**
	*	Class method, resizes the myString field with capacity *= 2.
	*/
	void resize();
public:
	/**
	*	Default constructor
	*	Initialize myString with empty string;
	*/
	MyString();

	/*
	*	Destructor
	*/
	~MyString();

	/**
	*	Copy constructor
	*	Copy the contents of src into the object
	*/
	MyString(const MyString& src);

	/*
	*	Move constructor
	*	Move contents from src into the object. Src is left "empty"
	*/
	MyString(MyString&& src) noexcept;

	/*
	* Copy assignment
	*/
	MyString& operator=(const MyString& src);

	/*
	*	Move assignment
	*	Move contents from src into the object. Src is left "empty"
	*/
	MyString& operator=(MyString&& src) noexcept;

	/**
	*	Constructor used to initialize object's myString field
	*	with given string
	*
	*	@param str - string to be used for initialization
	*/
	MyString(const char* str);

	/**
	*	Class method
	*	Used to access a character at the given index.
	*	Throws error if out of range.
	*	Throws error if trying to access nullptr string.
	*
	*	@param pos - position to be accessed
	*/
	char& at(size_t pos);

	/**
	*	Class method, same as the upper one, but for consts
	*
	*	@param pos - position to be accessed
	*/
	const char& at(size_t pos) const;

	/**
	*	operator[] - used like at(pos). Return the char at
	*	the desired position.
	*
	*	@param pos - position to be accessed
	*/
	char& operator[](size_t pos);

	/**
	*	operator[] - same as above, but for consts
	*
	*	@param pos - position to be accessed
	*/
	const char& operator[](std::size_t pos) const;

	/**
	*	Class method, used to access the first element
	*	of the string.
	*/
	char& front();

	/**
	*	Same as above, but for consts.
	*/
	const char& front() const;

	/**
	*	Class method, used to access the last element of the string.
	*/
	char& back();

	/**
	*	Same as above, but for consts.
	*/
	const char& back() const;

	/**
	*	Class method, checks if string is empty or not.
	*/
	bool empty() const;

	/**
	*	Class method, returns length of string.
	*/
	size_t size() const;

	/**
	*	Class method, erases the contents of the string, which becomes an empty string.
	*/
	void clear();

	/**
	*	Class method, concatenates the character (char c) at the end of the string.
	*	Throws if char c is null terminated symbol.
	*/
	void push_back(char c);

	/**
	*	Class method, removes the last character of the string.
	*/
	void pop_back();

	/**
	*	operator+=, concatenates a single symbol c at the end of the string
	*
	*	@param c - character to be concatenated to the string
	*	return *this
	*/
	MyString& operator+=(char c);

	/**
	*	operator+=, concatenates rhs at the end of the string
	*
	*	@param rhs - MyString object
	*	return *this
	*/
	MyString& operator+=(const MyString& rhs);

	/**
	*	operator+, returns a new string, which is produced by concatenating
	*	char c to the current string.
	*
	*	@param c - char to be concatenated
	*/
	MyString operator+(char c) const;

	/**
	*	operator+, returns a new MyString object, which is produced by concatenating
	*	char c to the current string.
	*
	*	@param rhs - MyString object
	*/
	MyString operator+(const MyString& rhs) const;

	/**
	*	Class method, returns a null-terminated char array with contents identical
	*	to the one of myString.
	*/
	const char* c_str() const;

	/**
	*	opreator==, returns boolean, true if strings are identical, false otherwise
	*
	*	@param rhs - MyString object with which will be compared
	*/
	bool operator==(const MyString& rhs) const;

	/**
	*	opreator<, returns boolean, true if left string precedes right string, false otherwise
	*
	*	@param rhs - MyString object with which will be compared for precedence
	*/
	bool operator<(const MyString& rhs) const;
};