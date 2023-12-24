#include <iostream>
using namespace std;
int main() {
	int n,tmp;
	bool flag = true;
	cin >> n;
	while (n != 0)
	{
		cin >> tmp;
		if (tmp != 0 && n > tmp)
		{
			flag = false;
		}
		n = tmp;
	}
	if (flag)
	{
		cout << "ordered" << endl;
	}
	else
	{
		cout << "unordered" << endl;
	}
	return 0;
}