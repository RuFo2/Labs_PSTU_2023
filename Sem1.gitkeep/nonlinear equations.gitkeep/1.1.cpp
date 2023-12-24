// f(x) = 3*x - 4*ln(x) - 5
// [2; 4]

//Метод половинного деления
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a, b, c;
    double fA, fB, fC;
    double eps = 0.000001;
    a = 2;
    b = 4;
    while (b - a > eps)
    {
        c = (a + b) / 2;
        fA = (3 * a - 4 * log(a) - 5);
        fB = (3 * b - 4 * log(b) - 5);
        fC = (3 * c - 4 * log(c) - 5);
        if (fA * fC < 0) { b = c; }
        else if (fC * fB < 0) { a = c; }
        else { cout << "no result" << endl; }
    }
    cout << "Result: " << a << "; " << b << endl;
    return 0;
}
