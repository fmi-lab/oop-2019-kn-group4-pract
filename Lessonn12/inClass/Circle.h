#pragma once
#include "Figure.h"
#include <iostream>
using namespace std;
class Circle : public Figure {
	const double PI = 3.1415926;
	double radius;
public:
	Circle(double _radius = 0) {
		this->radius = _radius;
	}
	double getArea() const override {
		return radius*radius* PI;
	}
	void print() const {
		cout << this->radius;
	}
	void serialize(ostream& out) const {
		out << "Circle " << this->radius;
	}
	void read(istream & in) {
		in >> radius;
	}
};
