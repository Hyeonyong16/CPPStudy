#include <iostream>

int Partition(int _arr[], int _low, int _high)
{
	int pivot = _arr[_high];
	int low = _low;
	int high = _high - 1;

	while (low <= high)
	{
		while (_arr[low] < pivot) ++low;
		while (_arr[high] > pivot) --high;

		if (low <= high)
		{
			int temp = _arr[low];
			_arr[low] = _arr[high];
			_arr[high] = temp;
		}
	}

	// Todo: ÇÇº¿À» High ¿Í ¹Ù²Ü °Í
	int temp = _arr[low];
	_arr[low] = _arr[_high];
	_arr[_high] = temp;

	return high;
}

void QuickSort(int _arr[], int _left, int _right)
{
	// Todo : Äü¼ÒÆ® º»¹® ±¸Çö
	if (_left < _right)
	{
		int pivot = Partition(_arr, _left, _right);

		QuickSort(_arr, _left, pivot - 1);
		QuickSort(_arr, pivot + 1, _right);
	}
}

int main()
{
	int arr[10] = { 1, 9, 2, 3, 6, 7, 10, 5, 4, 8 };

	QuickSort(arr, 0, 9);
	for (int num : arr)
	{
		std::cout << num << "\n";
	}


	std::cin.get();
}