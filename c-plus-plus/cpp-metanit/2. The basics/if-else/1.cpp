/*
* Упражнение 1
* Напишите программу, которая предлагает ввести два целых числа, 
* а затем использует конструкцию if-else для вывода сообщения о том, равны ли два числа.
*/

#include <iostream>

int main() {
	int a{}, b{};
	std::cout << "Enter a:";
	std::cin >> a;
	std::cout << "Enter b:";
	std::cin >> b;
	if (a == b) std::cout << "a = b";
	else std::cout << "a != b";
}
