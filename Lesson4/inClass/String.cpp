#include "stdafx.h"
#include "String.h"
#include <cstring>
#include <algorithm>

void String::copy(const char * cstring)
{
	this->size = strlen(cstring);
	this->capacity = this->size + 1;

	this->str = new char[this->capacity];
	strcpy_s(this->str, this->capacity, cstring);
}

void String::destroy()
{
	delete[] this->str;
}

void String::resize(size_t cstringSize = 1)
{
	size_t newSize = std::max(this->capacity * 2, 
		                      this->capacity + cstringSize);
	this->copy(this->str);

	this->size = newSize;
	this->capacity = newSize + 1;

	char * newStr = new char[this->capacity];
	strcpy_s(newStr, newSize, this->str);

	delete[] this->str;
	this->str = newStr;
}

String::String()
{
	this->size = 0;
	this->capacity = 1;

	this->str = new char[this->capacity];
	this->str[0] = '\0';
}

String::String(const char * inputString)
{
	this->copy(inputString);
}

String::String(const String & other):String(other.str)
{
	/*
	this->size = other.size;
	this->capacity = other.capacity;

	this->str = new char[other.capacity];
	strcpy_s(this->str, other.capacity, other.str);
	*/
}

String::~String()
{
	this->destroy();
}

void String::makeEqualTo(const char * cstring)
{
	this->destroy();

	this->copy(cstring);
}

void String::makeEqualTo(const String & other)
{
	makeEqualTo(other.str);
}

void String::print()
{
}

void String::addToBack(char c)
{
}

void String::addToBack(const char * cstring)
{
	size_t sz = strlen(cstring);

	resize(sz);
}