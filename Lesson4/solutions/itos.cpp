#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

char* itos(int n)
{
	size_t nSize = 0;
	int nCopy = n;
	
	while(nCopy != 0)
	{
		nSize++;
		nCopy /= 10;
	}
	
	if(n == 0)
	{
		nSize = 1;
	}
	
	char * ans = new char[nSize];
	
	for(size_t i = 0; i < nSize; i++, n /= 10)
	{
		ans[i] = n%10 + '0';
	}
	ans[nSize] = '\0';
	
	// Reverse number
	for(size_t i = 0; i < nSize/2; i++)
	{
		swap(ans[i], ans[nSize - i - 1]);
	}
	
	return ans;
}

int main()
{
	// Test itos
	char * ans = itos(12);
	assert(strcmp(ans, "12") == 0);
	delete[] ans;
	
	ans = itos(1);
	assert(strcmp(ans, "1") == 0);
	delete[] ans; 
	
	ans = itos(0);
	assert(strcmp(ans, "0") == 0);
	delete[] ans;
	return 0;
}