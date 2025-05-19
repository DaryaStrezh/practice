// lab2 уровень 2

#include "stdio.h"
#include <math.h>
#include <string.h>

using namespace std;
int main() {
	float z, a, c, x, fi, y;
	int flag = 1;
	printf("a = ");
	do {
		flag = 0;
		if (!(scanf_s("%f", &a))) {
			printf("Error. Try again! \n");
			flag = 1;
			scanf_s("%*c");//вызов функции scanf с пустым форматом %*c, чтобы пропустить все символы в буфере и очистить его
			printf("a = ");//повторный запрос ввода
		}
	} while (flag == 1);

	printf("c = ");
	do {
		flag = 0;
		if (!(scanf_s("%f", &c))) {
			printf("Error. Try again! \n");
			flag = 1;
			scanf_s("%*c");//вызов функции scanf с пустым форматом %*c, чтобы пропустить все символы в буфере и очистить его
			printf("c = ");//повторный запрос ввода
		}
	} while (flag == 1);

	printf("z = ");
	do {
		flag = 0;
		if (!(scanf_s("%f", &z))) {
			printf("Error. Try again! \n");
			flag = 1;
			scanf_s("%*c");//вызов функции scanf с пустым форматом %*c, чтобы пропустить все символы в буфере и очистить его
			printf("z = ");//повторный запрос ввода
		}
	} while (flag == 1);

	if (z >= 0) {
		x = 2 * z + 1;
		printf("z >= 0\nx = 2z + 1.\n");
	}
	if (z < 0) {
		x = log(powf(z, 2) - z);
		printf("z < 0\nx = ln(z^2 - z).\n");
	}
	printf("Choice fi:\n1.fi = 2x\n2.fi = x^2\n3.fi = x/3\n");
	int answer;
	scanf_s("%d", &answer);
	if (answer == 1) {
		fi = 2 * x;
		printf("fi = 2x\n");
	}
	else if (answer == 2) {
		fi = powf(x, 2);
		printf("fi = x^2\n");
	}
	else if (answer == 3) {
		fi = x / 3.;
		printf("fi = x/3\n");
	}
	else printf("Error.\n");
	if (answer == 1 || answer == 2 || answer == 3) {
		if (powf(x, 2 / 5.) > 0) {
			y = powf(sin(fi), 2) + a * powf(cos(powf(x, 3)), 5) + c * log(powf(x, 2 / 5.));
			printf("y = %f", y);
		}
		else printf("Impossible to find y ( x^(2/5) <= 0 )");
	}
	return 0;
}
