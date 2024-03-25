#include <iostream>
using namespace std;

int main() {
    const int n = 5;
    int max;
    int a[n] = { 1,2,3,4,5 };
    max = a[0];
    for (int i = 1; i < n; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    cout << max << endl;
    return 0;
}