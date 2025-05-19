#include <iostream> 
#include "math.h"
#include <string.h>

using namespace std;

float f(int n, float a) {
	if (n >= 1) {
		a = sqrt(n + a);
		return f(n - 1, a);
	}
}
int main() {
	int n;
	cout << "Enter n: ";
	cin >> n;
	for (int m = 1; m <= n; m++) {
		cout << "m = " << m << endl;
		//цикл для проверки суммы с корнем
		float a = 0, b = 0;
		for (int i = m; i >= 1; i--) {
			a = i + b;
			b = sqrt(a);
		}
		cout << "for: " << b << endl;
		cout << "fun: " << f(m, 0) << endl << endl;
	}
	cout << "fun: " << f(n, 0) << endl << endl;
	return 0;
}
