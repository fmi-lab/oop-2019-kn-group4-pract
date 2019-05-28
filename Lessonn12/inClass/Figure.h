#pragma once
#include <iostream>
#include <string>
using namespace std;
class Figure {
public:
	virtual double getArea() const = 0;
	virtual void print() const = 0;
	virtual void serialize(std::ostream& out) const = 0;
	virtual void read(istream& in) = 0;
};
