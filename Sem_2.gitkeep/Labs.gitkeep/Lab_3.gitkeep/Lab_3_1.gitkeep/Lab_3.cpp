#include <iostream>
#include <cmath>
using namespace std;

double sum(double n, double x)
{
    if (n == 0) return x;
    else return  (pow(- 1, n) * (pow(x, (2 * n + 1)) / (2 * n + 1))) + sum(n - 1, x);
}

int main()
{
    double n, x, k = 0; 
    cin >> n >> x;
    cout << sum(n, x) << endl;
    return 0;
}
