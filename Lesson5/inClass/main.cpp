#include "stdafx.h"
#include <iostream>
#include <cassert>
#include "Set.h"
using namespace std;
int main()
{
	Set s;

	assert(!s.contains(2));

	assert(s.insert(5));

	assert(!s.insert(5));
	

	Set s2;

	assert(!s.equals(s2));
	assert(!s2.equals(s));

	assert(s2.equals(s2));
	assert(s.equals(s));


	s2.insert(15);

	s.unifyWith(s2);

	assert(s.contains(15));

    return 0;
}

