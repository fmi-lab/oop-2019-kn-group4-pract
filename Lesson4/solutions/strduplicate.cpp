#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

char* strDuplicate(const char * str)
{
	assert(str != nullptr);
	
	char * ans = new char[strlen(str)+1];
	
	strcpy(ans, str);
	
	return ans;
}

int main()
{
	// Test strDuplicate
	char str[128] = "ASD";
	char * res = strDuplicate(str);
	
	assert(strcmp(str, res) == 0);
	
	delete[] res;
	
	res = strDuplicate("");
	
	assert(strcmp(res, "") == 0);
	return 0;
}