#include <iostream>

int Partition(int _arr[], int _low, int _high)
{
	int pivot = _high;
	_high = pivot - 1;

	while (_low < _high)
	{
		while (_arr[_low] < _arr[pivot]) ++_low;
		while (_arr[_high] > _arr[pivot]) --_high;

		if (_low < _high)
		{
			int temp = _arr[_low];
			_arr[_low] = _arr[_high];
			_arr[_high] = temp;
		}
	}

	// Todo: �Ǻ��� High �� �ٲ� ��
}

int QuickSort(int _arr[], int _left, int _right)
{
	// Todo : ����Ʈ ���� ����
}

int main()
{



	std::cin.get();
}