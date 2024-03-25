#include <iostream>
using namespace std;
int main()
{
    const int n = 5;
    int m, p;
    int a[n] = { 1,2,3,4,5 };
    p = a[0];
    m = a[0];
    for (int i = 1; i < n; i++)
    {
        if (p < a[i])
        {
            p = a[i];
        }
        else if (m > a[i])
        {
            m = a[i];
        }
    }
    cout << p << "  " << m;
    return 0;
}