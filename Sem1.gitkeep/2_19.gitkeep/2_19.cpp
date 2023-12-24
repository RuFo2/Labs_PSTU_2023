#include <iostream>
using namespace std;
int main(){
	int n;
	int s = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % 3 == 0)
		{
			s -= i;
		}
		else
		{
			s += i;
		}
	}
	cout << s << endl;
	return 0;
}