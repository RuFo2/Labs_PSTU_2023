// f(x) = 3*x - 4*log(x) - 5;
// f'(x) = 3 - 4/x;
// f''(x) = 4/x^2;
// [2, 4]

//Метод итераций
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float x, xPrev;
    // f(b) * f''(b) > 0
    // (12 - 1.38629 - 5)*(4/16) > 0 => x=b;
    x = 4, xPrev = 0;
    double eps = 0.000001;
    while (abs(x - xPrev) > eps)
    {
        xPrev = x;
        x = xPrev - (3 * xPrev - 4 * log(xPrev) - 5) / (3 - 4 / x);
    }
    cout << "Result "<< x << endl;
    return 0;
}