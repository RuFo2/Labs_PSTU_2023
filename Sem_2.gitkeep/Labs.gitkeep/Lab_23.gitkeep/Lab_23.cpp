#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Vector.h"
using namespace std;
int main()
{
    Vector v(5);
    Person one;
    cin >> one;
    Student two;
    cin >> two;

    v.add(&one);
    v.add(&two);

    cout << v;
	return 0;
}