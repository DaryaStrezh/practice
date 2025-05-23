/*Упражнение 1
Напишите программу, в которой с помощью функции std::cin.getline() 
пользователь вводит строку с консоли в массив символов. 
С помощью цикла подсчитайте количество символов, введенных пользователем. 
Затем с помощью второго цикла выведите все символы введенной строки в обратном порядке.
*/

#include <istream>
#include <iostream>

int main() {
	const int max {100};    // максимальная длина строки - не больше 100 символов
    char string[max];       // массив для ввода строки

    std::cout << "Enter a string: ";
    std::cin.getline(string, max);    // вводим строку

    // подсчет количества символов
    int count{};
    for (; count < max && string[count] != '\0'; ++count) {}
    std::cout << "Characters count: " << count << std::endl;

    // выводим в обратном порядке
    for (int i{ 1 }; i <= count; ++i)    {
        std::cout << string[count - i];
    }
	
}
