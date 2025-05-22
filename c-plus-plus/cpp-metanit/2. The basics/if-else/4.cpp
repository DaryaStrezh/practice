/*
* Упражнение 4
* Напишите программу, в которой вводятся два числа, и программа проверят, 
* больше ли первое число второму или меньше или они равны. 
* Для проверки используйте тренарный оператор.
*/

#include <iostream>

int main() {
	int a{}, b{};
	std::cout << "Enter a:";
	std::cin >> a;
	std::cout << "Enter b:";
	std::cin >> b;
	if (a == b) std::cout << "a = b";
	else if (a < b) std::cout << "a < b";
	else std::cout << "a > b";
}
