#include <iostream>
using namespace std;

void linearySearch(int arr[], int size, int key)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			cout << i << endl;
			break;
		}
	}
}

void binarySearch(int arr[], int left, int right, int key)
{
	int mid = (left + right) / 2;
	if (arr[mid] == key) {
		cout << mid << endl;
		return;
	}
	if (arr[mid + 1] <= key)
	{
		binarySearch(arr, mid + 1, right, key);
	}
	else
	{
		binarySearch(arr, left, mid - 1, key);
	}
}

void interpolationSearch(int arr[], int left, int right, int key)
{
	int mid = left + ((key - arr[left]) * (right - left)) / (arr[right] - arr[left]);
	if (arr[mid] == key) {
		cout << mid << endl;
		return;
	}
	if (arr[mid + 1] <= key)
	{
		interpolationSearch(arr, mid + 1, right, key);
	}
	else
	{
		interpolationSearch(arr, left, mid - 1, key);
	}
}

int main()
{
	int arr[6] = { 2,6,9,34,56,78 };
	linearySearch(arr, 6, 34);
	binarySearch(arr, 0, 5, 56);
	interpolationSearch(arr, 0, 5, 6);
}