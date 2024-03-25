#include <iostream>
using namespace std;

int main()
{
    const int n = 8;
    int k=0;
    int a[n] = { 5,5,2,5,4,3,4,5 };
    int m = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > m)
        {
            m = a[i];
            k = 0;
        }
        if (a[i] == m)
        {
            k++;
        }
    }
    if (a[0] == m)
    {
        k++;
    }
    cout << m << "  " << k;
    return 0;
}