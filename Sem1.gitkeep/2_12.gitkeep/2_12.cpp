#include <iostream>
using namespace std;
int main()
{
	int n, max, min, tmp;
	cin >> n;
	cin >> tmp;
	max = tmp;
	min = tmp;
	for (int i = 1; i < n; i++)
	{
		cin >> tmp;
		if (tmp > max)
		{
			max = tmp;
		}
		else if (tmp < min)
		{
			min = tmp;
		}
	}
	cout << max + min << endl;
	return 0;
}