#pragma once
class Set
{
	int * data;
	size_t size, capacity;
	void resize();
public:
	Set();
	Set(const Set & other);
	Set& operator=(const Set & other);
	~Set();

	bool contains(int element) const;
	bool insert(int element);
	bool equals(const Set & other) const;
	void unifyWith(const Set & other);
};

