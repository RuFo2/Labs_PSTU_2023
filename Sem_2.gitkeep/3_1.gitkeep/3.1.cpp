#include <iostream>
using namespace std;
int main()
{
	const int n = 4;
	int tmp;
	int arr[n] = { 41,42,66,77 };//если arr[n] не работает, то забиваем целочисленный литерал. кол-во элементов здесь несильно важно
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n / 2; i++)
	{
		tmp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = tmp;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
