#include <iostream>
#include <cstdlib>
#include <cassert>
#include "String.h"

int main()
{
	String s("ASD");

	s.makeEqualTo("QWE");

	s.addToBack(' ');

	s.addToBack("Dopulnitelna chast");

	s.print();

	return 0;
}