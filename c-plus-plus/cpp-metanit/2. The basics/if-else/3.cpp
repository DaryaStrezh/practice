/*
* Упражнение 3
* Напишите программу, в которую пользователь вводит число от 1 до 100. 
* Используйте вложенный оператор if, чтобы сначала убедиться, 
* что число находится в пределах этого диапазона. 
* А затем при выполнении этого условия определите, является ли введенное число больше, меньше или равным 50. 
* И выведите результат на консоль.
*/

#include <iostream>

int main() {
	int a{};
	std::cout << "Enter a (0; 100):";
	std::cin >> a;
	
	if (a > 0 && a < 100) {
		if (a>50) std::cout << "a > 50";
		else if (a < 50) std::cout << "a < 50";
		else std::cout << "a = 50";
	}
	else std::cout << "the number is not in the range (0; 100)";
}
