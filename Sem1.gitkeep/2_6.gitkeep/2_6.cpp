#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int stars = n;
	int spaces = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < spaces; j++) {
			cout << " ";
		}
		spaces+=2;
		for (int j = 0; j < stars; j++) {
			cout << " *";
		}
		stars--;
		cout << endl;
	}
	return 0;
}