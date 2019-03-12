#include "stdafx.h"
#include <iostream>
#include "String.h"
int main()
{
	String s("ASD");
	
	s.makeEqualTo("QWE");
	s.addToBack('3');
	s.addToBack('3');
	s.addToBack('3');
	s.addToBack('3');
	
	s.addToBack("Dopulnitelna chast");
	
	return 0;
}