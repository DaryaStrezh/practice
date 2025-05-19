// lab3.cpp сложность 2
#include "stdio.h"
#include <math.h>

using namespace std;

int main() {

	float x, a, b, h, y = 0., s = 0.;
	int k, n, factorial = 1;

	printf("a = ");
	scanf_s("%f", &a);
	printf("b = ");
	scanf_s("%f", &b);
	printf("h = ");
	scanf_s("%f", &h);
	printf("n = ");
	scanf_s("%d", &n);
	printf("x\tY(x)\tS(x)\t|Y(x) - S(x)|\n");

	for (x = a; x < b+h; x += h) {
		y = exp(2 * x);
		for (int k = 0; k <= n; k++) {
			if (k != 0) {
				factorial *= k;
			}
			s += pow(2 * x, k) / factorial;
		}
		printf("\n");
		printf("%.1f%\t%f%\t%f%\t%f%\n", x, y, s, fabs(y - s));
		s = 0;
		factorial = 1;
	}
	/*
	n = 9 eps < 0.001
	n = 10 eps < 0.0001
	n = 11 eps < 0.00001
	*/

	return 0;
}
