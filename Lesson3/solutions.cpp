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
	assert(newSize > size);
	assert(arr != nullptr);

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
	assert(arr != nullptr);

	resize(arr, size, size + brNewElements);
	for (size_t i = size; i < size + brNewElements; i++)
	{
		cin >> arr[i];
	}
}

int * erase(int * arr, size_t size, size_t leftIndex, size_t rightIndex)
{
	assert(arr != nullptr);
	assert(leftIndex <= rightIndex);
	assert(leftIndex < size);
	assert(rightIndex < size);
	assert(rightIndex - leftIndex + 1 < size); // array will have at least 1 element

	int * ans = new int[size - (rightIndex - leftIndex + 1)];

	for (size_t i = 0; i < leftIndex; i++)
	{
		ans[i] = arr[i];
	}

	for (size_t i = rightIndex + 1; i < size; i++)
	{
		ans[i - (rightIndex - leftIndex + 1)] = arr[i];
	}

	return ans;
}

int * erase(int * arr, size_t size, size_t index)
{
	return erase(arr, size, index, index);
}

void extend(int *& arr, size_t size, size_t newSize)
{
	assert(arr != nullptr);
	assert(size < newSize);

	resize(arr, size, newSize);
	for (size_t i = size; i < newSize; i++)
	{
		arr[i] = 0;
	}
}

void testErase()
{
	size_t sizeOfArray = 10;

	int * arr = new int[sizeOfArray]{ 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10 };

	// Test single index erase
	int * result = erase(arr, sizeOfArray, 1);
	assert(result[0] == 1);
	assert(result[1] == 3);
	assert(result[sizeOfArray-2] == 10);

	// Print deleted array
	cout << "Erasing elements at index 1: " << endl;
	cout << "Array: ";
	for (size_t i = 0; i < sizeOfArray - 1; i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;

	delete[] result;

	// Test range erase
	result = erase(arr, sizeOfArray, 0, 3);
	assert(result[0] == 5);
	assert(result[sizeOfArray - 5] == 10);

	cout << "Erasing elements at indexes [0, 3]: "<<endl;
	cout << "Array: ";
	for (size_t i = 0; i < sizeOfArray - 4; i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;

	delete[] result;
	delete[] arr;
}