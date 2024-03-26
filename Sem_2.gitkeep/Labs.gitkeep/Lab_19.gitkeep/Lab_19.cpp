#include <iostream>
#include <cmath>
using namespace std;

class arProg {
    double first;
    unsigned int second;

public:
    void set(double a, unsigned int b)
    {
        first = a;
        second = b;
    }
    void element(int j)
    {
        cout << "a(j) = " << first * pow(second, j);
    }
};
int main()
{
    arProg el;
    el.set(1, 3);
    el.element(5);
    return 0;
}