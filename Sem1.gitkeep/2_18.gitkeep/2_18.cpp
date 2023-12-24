#include <iostream>
using namespace std;
int main(){
	int n;
	int re = 0;
	cin >> n;
	while (n > 0)
	{
		re = re * 10 + n % 10;
		n /= 10;
	}
	cout << re << endl;
	return 0;
}