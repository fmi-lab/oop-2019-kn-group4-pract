#include <iostream>
using namespace std;

int * read(size_t n)
{
	int * arr = new int[n];

	for (size_t i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	return arr;
}

void resize(int *& arr, size_t size, size_t newSize)
{
	int * newArr = new int[newSize];

	for (size_t i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}

	delete[] arr;
	arr = newArr;
}

void addElements(int *& arr, size_t size, size_t brNewElements)
{
	resize(arr, size, size + brNewElements);
	for (size_t i = size; i < size+brNewElements; i++)
	{
		cin >> arr[i];
	}

}

int* erase(int * arr, size_t size, size_t index)
{
	int * ans = new int[size - 1];
	for (size_t i = 0; i < index; i++)
	{
		ans[i] = arr[i];
	}
	for (size_t i = index + 1; i < size; i++)
	{
		ans[i - 1] = arr[i];
	}

	return ans;
}

int * erase(int * arr, size_t size, size_t leftIndex, size_t rightIndex)
{
	int * ans = new int[size - (rightIndex - leftIndex + 1)];
	for (size_t i = 0; i < leftIndex; i++)
	{
		ans[i] = arr[i];
	}

	for (size_t i = rightIndex+1; i < size - (rightIndex - leftIndex + 1); i++)
	{
		ans[i + (rightIndex - leftIndex)] = arr[i];
	}

	return ans;
}

void extend(int *& arr, size_t size, size_t newSize)
{
	resize(arr, size, newSize);
	for (size_t i = size; i < newSize; i++)
	{
		arr[i] = 0;
	}
}

int main()
{
	int * arr = new int[10];
	resize(arr, 100);
	return 0;
}