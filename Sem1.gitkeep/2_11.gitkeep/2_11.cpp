#include <iostream>
using namespace std;
int main()
{
	int n, tmp;
	bool plfirst = false;
	bool minfirst = false;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (!plfirst && !minfirst)
		{
			if (tmp > 0)
			{ 
				plfirst = true;
			}
			else if (tmp < 0)
			{
				minfirst = true;
			}
		}
	}
	if (plfirst)
	{
		cout << "+" << endl;
	}
	else if (minfirst)
	{
		cout << "-" << endl;
	}
	else
	{
		cout << 0 << endl;
	}
	return 0;
}