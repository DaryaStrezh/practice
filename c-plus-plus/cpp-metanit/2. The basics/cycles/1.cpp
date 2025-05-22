/*
* Упражнение 1
* Напишите программу, которая выводит квадраты нечетных целых чисел от 1 до предела который вводит пользователь.
*/

#include <iostream>

int main() {
	int limit{};
	std::cout << "Enter limit:";
	std::cin >> limit;
	for (int i = 1; i <= limit; i += 2) std::cout << i * i << " " << std::endl;
}
