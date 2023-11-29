#include <iostream>
using namespace std;
int main()
{
    int n, s=0, t=0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        t = 1;
        for (int j = i; j <= 2 * i; j++) {
            t *= j;
        }
        s += t;
    }
    cout << s << endl;
    return 0;
}