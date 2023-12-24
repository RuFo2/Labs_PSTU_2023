#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float n, max, a;
    int i = 2;
    int count = 1;
    cin >> n;
    max = round(sin(n + 1 / n) * 10) / 10;
    while (i <= n)
    {
        a = sin(n + i / n);
        a = round(a * 10) / 10;
        if (a > max)
        {
            max = a;
            count = 1;
        }
        else if (a == max)
        {
            count++;
        }
        i++;
    }
    cout << "max=" << max << " cnt=" << count << endl;
    return 0;
}