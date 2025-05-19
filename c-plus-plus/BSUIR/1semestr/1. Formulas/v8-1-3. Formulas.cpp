// lab1.cpp. v8, уровень 3

#include "stdio.h"
#include <math.h>
using namespace std;

int main(){
	float fi, x, y, z;
	int flag = 1;
	printf("Enter x: ");
	do {
		flag = 0;
		if (!(scanf_s("%f", &x))) {
			printf("Error. Try again! \n");
			flag = 1;
			scanf_s("%*c");//вызов функции scanf с пустым форматом %*c, чтобы пропустить все символы в буфере и очистить его
			printf("Enter x: ");//повторный запрос ввода
		}
	} while (flag == 1);
	printf("Enter y: ");
	do {
		flag = 0;
		if (!(scanf_s("%f", &y))) {
			printf("Error. Try again! \n");
			flag = 1;
			scanf_s("%*c");//вызов функции scanf с пустым форматом %*c, чтобы пропустить все символы в буфере и очистить его
			printf("Enter y: ");//повторный запрос ввода
		}
	} while (flag == 1);
	printf("Enter z: ");
	do {
		flag = 0;
		if (!(scanf_s("%f", &z))) {
			printf("Error. Try again! \n");
			flag = 1;
			scanf_s("%*c");//вызов функции scanf с пустым форматом %*c, чтобы пропустить все символы в буфере и очистить его
			printf("Enter z: ");//повторный запрос ввода
		}
	} while (flag == 1);
	if (x > 0 && atan(x) + atan(z) != 0) {
		fi = (exp(fabs(x - y)) * powf(fabs(x - y), x + y) / (atan(x) + atan(z))) + powf((powf(x, 6) + powf(log(y), 2)), 1 / 3.);
		printf("fi = %f%", fi);
	}
	else {
		printf("It's impossible to find the value of the function.");
	}
	return 0;
}
