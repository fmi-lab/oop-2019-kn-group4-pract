#include "stdafx.h"
#include "Set.h"


void Set::resize()
{
	if (this->capacity == 0)
	{
		this->capacity = 1;
	}

	int * newData = new int[this->capacity * 2];

	for (size_t i = 0; i < this->size; i++)
	{
		newData[i] = this->data[i];
	}

	delete[] this->data;

	this->data = newData;

	this->capacity *= 2;
}

Set::Set()
{
	this->size = 0;
	this->capacity = 0;
	this->data = nullptr;
}

bool Set::contains(int element) const
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (this->data[i] == element)
		{
			return true;
		}
	}
	return false;
}

bool Set::insert(int element)
{
	if (this->contains(element))
	{
		return false;
	}

	if (this->size + 1 > capacity)
	{
		this->resize();
	}

	this->data[size] = element;
	this->size++;


	return true;
}

bool Set::equals(const Set & other) const
{
	if (this->size != other.size)
	{
		return false;
	}

	for (size_t i = 0; i < this->size; i++)
	{
		if (!other.contains(this->data[i]))
		{
			return false;
		}
	}
	return true;
}

void Set::unifyWith(const Set & other)
{
	for (size_t i = 0; i < other.size; i++)
	{
		// insert takes care of this case; not needed
		if (!this->contains(other.data[i]))
		{
			this->insert(data[i]);
		}
	}
}

Set::~Set()
{
}
