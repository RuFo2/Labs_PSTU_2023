// f(x) = 3*x - 4*log(x) - 5;
// f'(x) = 3 - 4/x;
// f''(x) = 4/x^2;
// [2, 4]
// 

//ф(x) = x + λ(3 * x - 4 * log(x) - 5)
// -1/r < λ < 0, если f'(x) > 0
// 0 < λ < 1/r, если f'(x) < 0
// r = max(|f'(a)|, |f'(b)|)
// r = max(|3*2 - 4*log(2) - 5|, |3*4 - 4*log(4) - 5|) = max(1.773, 1.455) = 11
// f'(x) > 0 => -1/r < λ < 0 => ~(-2/3;0)
// берем любое удобное число в диапазоне
// λ = -1/5 = -0.2

//Метод итераций
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	float x, xPrev;
	double lambda = -0.2;
	x = 2;
	xPrev = 0;
	double eps = 0.000001;
	while (abs(x - xPrev) > eps)
	{
		xPrev = x;
		x = lambda * (3 * xPrev - 4 * log(xPrev) - 5) + xPrev;
	}
	cout << "Result " << x << endl;
	return 0;
}