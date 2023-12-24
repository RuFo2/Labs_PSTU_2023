#include <iostream>
using namespace std;
int main() {
	int n, s;
	cin >> n >> s;
	bool flag = false;
	while (n > 0 && !flag)
	{
		if (n % 10 == s)
		{
			flag = true;
			cout << "+" << endl;
		}
		else
			n /= 10;
	}
	if (!flag)
	{
		cout << "-" << endl;
	}
	return 0;
}