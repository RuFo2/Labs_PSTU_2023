#include <iostream>
using namespace std;
int main(){
	unsigned int n, fact = 1;
	unsigned int* f = &fact;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		*f *= i;
	}
	cout << "factorial " << n << " = " << fact << endl;
	return 0;
}