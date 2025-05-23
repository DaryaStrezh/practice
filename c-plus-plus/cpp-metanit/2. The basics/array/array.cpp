/*Упражнение 1
* Напишите программу, в которой определен одномерный массив чисел int. 
* Пользователь должен вводить с консоли значения для всех элементов массива. 
* После завершения ввода всех чисел программа должна вывести элементы массива в обратном порядке.
*/
#include <iostream>

int main() {
	const int array_size{ 10 };
	int num{ 0 };
	int nums[array_size];
	for (int i = 0; i < array_size; i++) {
		std::cout << "enter " << i + 1 << " element: ";
		std::cin >> num;
		nums[i] = num;
	}
	for (int i = array_size - 1; i >= 0; i--) {
		std::cout << nums[i] << " ";
	}
}
