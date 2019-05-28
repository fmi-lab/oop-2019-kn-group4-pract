#pragma once
#include "Figure.h"
#include <iostream>
using namespace std;
class Rectangle : public Figure {
	double height;
	double width;
public:
	Rectangle(double _height = 0, double _width = 0) {
		this->height = _height;
		this->width = _width;
	}
	double getArea() const override {
		return height * width;
	}
	void print() const {
		cout << this->height << " " << this->width;
	}
	void serialize(ostream& out) const {
		out << "Rectangle " << this->height << " " << this->width;
	}
	void read(istream& in) {
		in >> this->height >> this->width;
	}
};
