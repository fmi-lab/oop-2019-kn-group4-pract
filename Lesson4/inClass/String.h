#pragma once
class String
{
	char * str;
	size_t size;
	size_t capacity;
	void copy(const char * cstring);
	void destroy();
	void resize(size_t newSize);
public:
	String();
	String(const char * inputString);
	String(const String & other);
	~String();

	void makeEqualTo(const char * cstring);
	void makeEqualTo(const String & other);

	void print();
	void addToBack(char c);
	void addToBack(const char * cstring);
};