#include <iostream>
using namespace std;
int main()
{
	const int n = 5;
	bool flag = true;
	int a[n] = { 1,2,3,4,5 };
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1]) { flag = false; }
	}
	if (flag)
	{
		cout << "+" << endl;
	}
	else
	{
		cout << "-" << endl;
	}
	return 0;
}