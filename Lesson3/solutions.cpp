int * erase(int * arr, size_t size, size_t leftIndex, size_t rightIndex)
{
	assert(leftIndex <= rightIndex);
	assert(leftIndex < size);
	assert(rightIndex < size);
	assert(rightIndex - leftIndex + 1 < size); // array will have at least 1 element

	int * ans = new int[size - (rightIndex - leftIndex + 2)];

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