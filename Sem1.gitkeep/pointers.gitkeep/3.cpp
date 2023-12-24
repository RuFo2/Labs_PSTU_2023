#include <iostream>
using namespace std;
int main() {
	float a, b;
	float* ptr1, * ptr2;
	cin >> a >> b;
	ptr1 = &a;
	ptr2 = &b;
	cout << (*ptr1 + *ptr2) << endl;
	return 0;
}