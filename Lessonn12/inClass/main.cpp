#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
using namespace std;
Figure* factory(string type) {
	if (type == "Circle") return new Circle();
	if (type == "Rectangle") return new Rectangle();
	return nullptr;
}
int main()
{
	vector<Figure*> figures;

	ofstream out("serialized.txt");

	figures.push_back(new Circle(13));
	figures.push_back(new Rectangle(12, 15));
	out << figures.size() << " ";
	for (size_t i = 0; i < figures.size(); i++)
	{
		figures[i]->serialize(out);
		out << " ";
	}
	out << endl;

	out.close();

	// Chetene ot faila

	Figure** read;
	ifstream in("serialized.txt");
	size_t size;
	in >> size;
	read = new Figure*[size];
	for (size_t i = 0; i < size; i++)
	{
		string type;
		in >> type;
		read[i] = factory(type);
		read[i]->read(in);
	}

	for (size_t i = 0; i < size; i++)
	{
		read[i]->serialize(cout);
		cout << " ";
	}

	ofstream outBinary("bin.txt", ios::binary);
	int writeBuffer[] = {1, 2, 3, 4, 5, 56465465};
	outBinary.write((char*)writeBuffer, sizeof(writeBuffer));

	/*
	//outBinary << figures.size() << " ";
	for (size_t i = 0; i < figures.size(); i++)
	{
		out.write()
		figures[i]->serialize(outBinary);
		//outBinary << " ";
	}
	//outBinary << endl;
	*/
	outBinary.close();
    return 0;
}

