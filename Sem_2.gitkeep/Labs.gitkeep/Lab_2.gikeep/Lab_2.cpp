#include <iostream>
using namespace std;

int main()
{
	int num[8] = { 1,2,3,4,5,6,7,8 };
	int arr[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (int i = 0, k = 0; i < 8; k++, i++)
	{
		for (int j = 0; j < 8 - k; j++)
		{
			arr[i + j][j] = num[k % 8];
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}