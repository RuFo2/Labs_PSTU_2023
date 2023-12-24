#include <iostream>
using namespace std;
int main(){
    float n, max, a;
    int i = 2;
    int num = 1;
    cin >> n;
    max = sin(n + 1 / n);
    while (i <= n)
    {
        a = sin(n + i / n);
        if (a > max)
        {
            max = a;
            num = i;
        }
        i++;
    }
    cout << "max:" << max << ", num:" << num << endl;
    return 0;
}