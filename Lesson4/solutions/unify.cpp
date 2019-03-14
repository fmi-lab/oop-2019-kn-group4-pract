#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;
void count(const char * str, bool* brs, size_t& numberOfUniqueChars)
{
	for(size_t i = 0, sz = strlen(str); i < sz; i++)
	{
		if(brs[str[i]] == false)
		{
			brs[str[i]] = true;
			numberOfUniqueChars++;
		}
	}
}
char* unify(const char * s1, const char * s2)
{
	bool brs[256] = {0};
	size_t strSize = 0;
	
	count(s1, brs, strSize);
	count(s2, brs, strSize);
	
	char * ans = new char[strSize+1];
	
	size_t endOfString = 0;
	
	for(size_t i = 0; i < 256; i++)
	{
		if(brs[i] == true)
		{
			ans[endOfString] = i;
			endOfString++;
		}
	}
	
	ans[endOfString] = '\0';
	
	return ans;
}

int main()
{
	char * ans = unify("ASD", "ASDF");
	assert(strcmp(ans, "ADFS") == 0);
	delete[] ans;
	
	ans = unify("", "QWE");
	assert(strcmp(ans, "EQW") == 0);
	delete[] ans;
	return 0;
}