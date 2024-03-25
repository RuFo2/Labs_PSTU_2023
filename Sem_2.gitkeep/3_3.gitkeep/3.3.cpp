#include <iostream>
using namespace std;
int main()
{
	const int n = 5;
	int k, tmp;
	k = 3;
	int arr[5] = { 41,42,66,87,86 };
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		tmp = arr[0];
		for (int j = 0; j < n - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		arr[n - 1] = tmp;
		for (int j = 0; j < n; j++)
		{
			cout << arr[j] << " ";
		}
		cout << endl;
	}
	return 0;
}