#include <iostream>
using namespace std;
int main() {
	int n, max, tmp;
	cin >> n;
	cin >> max;
	for (int i = 2; i <= n; i++)
	{
		cin >> tmp;
		if (tmp > max)
		{
			max = tmp;
		}
	}
	cout << max << endl;
	return 0;
}