#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

enum Food {Kebapcheta = 5, Kifteta, Bira};
class Page
{
public:
	char text[1024];
	Page() {}
	void write(ostream& in)
	{
		in << text;
	}
};
int main()
{
	Page p;
	strcpy_s(p.text, "ASD");
	p.write(cout);

	ofstream out("ASDFile");
	p.write(out);

	Food hrana = Kifteta;

	cout << hrana << endl;


	return 0;
}




