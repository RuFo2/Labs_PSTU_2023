#include <iostream>
using namespace std;
int main()
{
	int n, pr = 1;
	cin >> n;
	if (n >= 1) {
		for (int i = 1; i <= n; i++) {
			pr *= i;
		}
		cout << pr << endl;
	}
	else {
		cout << "No result" << endl;
	}
	return 0;
}
