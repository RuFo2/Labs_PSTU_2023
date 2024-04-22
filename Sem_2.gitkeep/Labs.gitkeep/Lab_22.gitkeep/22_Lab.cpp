#include <iostream>
#include "Person.h"
#include "Student.h"
using namespace std;
int main()
{
	Person One("pupa", 56);
	Student Two("lupa", 32, "Math", 2);

	cin >> One;
	cout << One;

	cin >> Two;
	cout << Two;
	return 0;
}