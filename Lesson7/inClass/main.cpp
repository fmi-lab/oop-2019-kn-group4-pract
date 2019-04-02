#include "stdafx.h"
#include <iostream>
#include <cassert>
#include <string>
#include <memory>
#include "Pair.h"
using namespace std;
class String
{
	char * str;
public:
	String()
	{
		cout << "Constructor called" << endl;
	}
	~String()
	{
		cout << "Destructor called" << endl;
	}
};

template<class T>
class UniquePtr
{
	T * ptr;
public:
	UniquePtr(T * _ptr) {
		this->ptr = _ptr;
	}
	~UniquePtr()
	{
		delete ptr;
	}
};
int main()
{
	unique_ptr<String> uptr(new String());
	return 0;
}

