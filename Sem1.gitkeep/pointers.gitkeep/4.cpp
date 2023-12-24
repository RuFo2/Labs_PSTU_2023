#include <iostream>
using namespace std;
int main() {
	int n, tmp, max, min, *ptr=&tmp;
	cin >> n;
	cin >> *ptr;
	max = *ptr;
	min = *ptr;
	for (int i = 2; i <= n; i++)
	{
		cin >> *ptr;
		if (*ptr > max)
		{
			max = *ptr;
		}
		else if (*ptr < min)
		{
			min = *ptr;
		}
	}
	cout << max <<  min << endl;
	return 0;
}