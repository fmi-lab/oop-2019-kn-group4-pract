#include "String.h"
#include <iostream>
#include <cstring>
#include <cstdlib> // size_t

using namespace std;

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

void String::resize()
{
	cout << "Resize called" << endl;

	size_t newCapacity = this->capacity * 2;

	char * newStr = new char[newCapacity];
	
	strcpy_s(newStr, this->size + 1, this->str);

	delete[] this->str;

	this->str = newStr;

	this->capacity = newCapacity;
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

String::String(const String & other) :String(other.str)
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
	cout << this->str << endl;
}

void String::addToBack(char c)
{
	if (this->size + 1 + 1 > this->capacity)
	{
		resize();
	}

	this->str[this->size] = c;
	this->size++;
	this->str[this->size] = '\0';
}

void String::addToBack(const char * cstring)
{
	for (size_t i = 0; cstring[i] != '\0'; i++)
	{
		addToBack(cstring[i]);
	}

}