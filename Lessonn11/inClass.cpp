#include "stdafx.h"
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
class Set {
protected:
	vector<int> elements;
public:
	virtual bool member(int value) {
		for(size_t i = 0; i < elements.size(); i++)
		{
			if (elements[i] == value) {
				return true;
			}
		}
		return false;
	}
	virtual void addNumber(int newValue) {
		if (!this->member(newValue)) {
			this->elements.push_back(newValue);
		}
	}
	Set() {} 
	virtual ~Set() {}
};
class Evens : public Set {
public:
	bool member(int value) {
		if (value % 2 == 0) {
			return Set::member(value);
		}
		return false;
	}
	Evens() {}
};
class FiniteMultiset : public Set {
protected:
	// vector<int> elements;
	const size_t MAX_SIZE;
public:
	FiniteMultiset(size_t _MAX_SIZE) :MAX_SIZE(_MAX_SIZE) { }

	void addNumber(int newValue) {
		if (elements.size() < MAX_SIZE) {
			this->elements.push_back(newValue);
		}
		else {
			cerr << "Error: too many elements" << endl;
		}
	}
	//FiniteMultiset():MAX_SIZE(0) {}
};
class FiniteSet : public FiniteMultiset {
public:
	void addNumber(int newValue) {
		if (!Set::member(newValue)) {
			FiniteMultiset::addNumber(newValue);
		}
		else {
			cerr << newValue << " already a member of the set" << endl;
		}
	}
	FiniteSet(size_t _MAX_SIZE):FiniteMultiset(_MAX_SIZE) {}
	~FiniteSet() {}
};
int main()
{
	vector<Set*> sets;

	sets.push_back(new FiniteSet(13));
	assert(sets[0]->member(6) == false);

	sets.push_back(new FiniteMultiset(2));
	sets[1]->addNumber(6);
	sets[1]->addNumber(6);
	sets[0]->addNumber(6);

	cout << endl;

	for (size_t i = 0; i < sets.size(); i++)
	{
		cout << sets[i]->member(2) << endl;
	}

    return 0;
}

