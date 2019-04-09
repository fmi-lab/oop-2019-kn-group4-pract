#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <vector>
using namespace std;
struct Person
{
	int height;
	char name[128];
	Person(char * _name, int _height)
	{
		strcpy_s(this->name, strlen(_name) + 1, _name);
		this->height = _height;
	}
	bool operator<(const Person & other)
	{
		return this->height < other.height;
	}

	friend ostream& operator<<(ostream& out, const Person & object);
};

ostream& operator<<(ostream& out, const Person & object)
{
	out << object.name << " is " << object.height << " centimeters tall";

	return out;
}

bool cmp(Person left, Person right)
{
	return left.height > right.height;
	/*
	if (left.height == right.height)
	{
		return strcmp(left.name, right.name) < 0;
	}
	return left.height < right.height;
	*/
}

int multBy2(int x)
{
	return x * 2;
}

template<class T>
using func = T(*)(T);

template<class T, size_t SIZE>
void map(T (&arr)[SIZE], func<T> f)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i] = f(arr[i]);
	}
}

template<class T>
using filterFunc = bool(*)(T);

template<class T, size_t SIZE>
T* filter(T (&arr)[SIZE], size_t & newSize, filterFunc<T> f)
{
	newSize = 0;
	T * filteredArray = new T[SIZE];

	for (size_t i = 0; i < SIZE; i++)
	{
		if (f(arr[i]))
		{
			filteredArray[newSize] = arr[i];
			newSize++;
		}
	}
	return filteredArray;
}

bool divBy2(int x)
{
	return x % 2 == 0;
}

int main()
{
	int arr[10] = { 1, 2, 3, 76, 3, 5, 6, 5, 55, 1999 };
	size_t resSize = 0;
	int * res = filter(arr, resSize, divBy2);

	for (size_t i = 0; i < resSize; i++)
	{
		cout << res[i] << " ";
	}

	cout << endl;



	cerr << "Error: ";

	/*
	vector<Person> persons;

	persons.push_back(Person("Ivan", 150));
	persons.push_back(Person("Traicho", 120));
	persons.push_back(Person("Alpaj", 140));

	sort(persons.begin(), persons.end());

	cout << persons[0].height << endl;

	vector<int> ints;
	ints.push_back(200);
	ints.push_back(20);
	ints.push_back(150);

	sort(ints.begin(), ints.end());

	cout << ints[0] << endl;
	*/

	return 0;
}

