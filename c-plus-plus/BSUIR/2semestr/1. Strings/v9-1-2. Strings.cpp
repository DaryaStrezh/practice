/*
* Вариант 9, 2 уровень сложности
* Дана строка символов, состоящая из цифр, разделенных пробелами. 
* Вывести на экран числа этой строки в порядке возрастания
* их значений.
*/

#include <iostream>
#include <string>
#include <cstdlib>  

using namespace std;

int main() {
    string str_num; // строка с числами
    int count = 0;  // счетчик чисел в строке

    cout << "Enter the numbers separated by a space: " << endl; // ввод чисел через пробел
    getline(cin, str_num);

    //проверка, не состоит ли строка полностью из пробелов
    bool char_flag = false;
    for (char c : str_num) { // Перебираем строку и проверяем, что в строке есть хотя бы один не пробельный символ
        if (c != ' ') {
            char_flag = true; // ставим флаг, если нашли не пробел, выходим из цикла
            break;
        }
    }

    if (!char_flag) { // если флаг FALSE, выводим сообщение, что строка пустая или состоит из пробелов
        cout << "Error: input string is empty or contains only spaces." << endl;
        return 1;
    }
    else { // если нашли хотя бы один не пробельный символ
        for (int i = 0; i < str_num.length(); i++) { // проверяем, есть ли в строке буквы или симвлы, которые не являются цифрой или пробелом
            if (!isdigit(str_num[i]) && str_num[i] != ' ') { // Проверка, является ли заданный символ цифрой
                cout << "Error: input string contains invalid characters." << endl; // если нашли букву, то выходим из программы
                return 1;
            }
        }
        // Подсчет количества чисел в строке str_num
        for (int i = 0; i < str_num.length(); i++) {
            if (
                (i == 0 && str_num[i] != ' ') || // если рассматриваем первый символ и это не пробел ИЛИ
                (i > 0 && str_num[i] != ' ' && str_num[i - 1] == ' ') // если это не первый символ строки, И он не равен пробелу, И предыдущий символ не равен пробелу (т.е. двузначение число)
                ) {
                count++; // увеличиваем счетчик чисел в строке
            }
        }

        // Создаем динамический массив, в который положим числа из строки
        int* numbers = new int[count];

        // добавляем числа из строки str_num в массив numbers для последующей сортировки
        int temp_i = 0; // счетчик для добавления в массив чисел numbers
        string currentNumber = ""; // строка, которая будет хранить в себе символы текущего числа (например '1', дальше '12' и тд)
        for (int i = 0; i <= str_num.length(); i++) { // перебираем строку по символам
            if (i < str_num.length() && str_num[i] != ' ') { // если не дошли до конца строки И данный элемент не является пробелом
                currentNumber += str_num[i]; // тогда добавляем символ к числу 
            }
            else if (!currentNumber.empty()) { // иначе (при условии, что считанная подстрока не пробел)
                numbers[temp_i] = atoi(currentNumber.c_str()); // переводим считанную подстроку с помощью atoi в число и добавляем в массив чисел numbers
                temp_i++;
                currentNumber = ""; // обнуляем строку, в которой хранится подстрока с числом, для последующей итерации
            }
        }

        // Сортировка  пузырьком массива с извлеченными числами numbers
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - 1 - i; j++) {
                if (numbers[j] > numbers[j + 1]) {
                    int temp = numbers[j];
                    numbers[j] = numbers[j + 1];
                    numbers[j + 1] = temp;
                }
            }
        }

        cout << "\nThe numbers are in ascending order: \n"; // вывод чисел в порядке возрастания
        for (int i = 0; i < count; i++)  cout << numbers[i] << " ";
        cout << endl;
        delete[] numbers; // освобождение памяти,занятой динамическим массивом
    }
    return 0;
}
