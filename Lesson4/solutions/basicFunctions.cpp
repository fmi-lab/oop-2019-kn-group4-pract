#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;
char car(const char * x)
{
	assert(x != nullptr);
	return x[0];
}
char* cdr(char * x)
{
	assert(x != nullptr);	
	return x+1;
}
char* cons(char x, const char * y)
{
	char * ans = new char[1 + strlen(y) + 1];
	ans[0] = x;
	strcat(ans+1, y);
	return ans;
}
bool eq(const char * x, const char * y)
{
	assert(x != nullptr && y != nullptr);
	
	size_t i, xSz = strlen(x), ySz = strlen(y);
	
	if(xSz != ySz) 
	{
		return false;
	}
	
	for(i = 0; i < xSz; i++)
	{
		if(x[i] != y[i])
		{
			return false;
		}
	}
	
	return true;
}
char* reverse(char * x)
{
	char * ans = new char[strlen(x)+1];
	
	while(car(x) != '\0')
	{
		cons(car(x), ans);
		x = cdr(x);
	}
	
	return ans;
}
int main()
{
	char str[] = "ASD";
	cout<<reverse(str)<<endl;
	return 0;
}