/*
* Упражнение 3
* Напишите программу обмена валют: программа запрашивает текущий курс доллара, 
* например, к рублю, и количество единиц (рублей) для конвертации и выводит на консоль 
* сконвертированную сумму в долларах.
*/

#include <iostream>

int main(){
    double course{};
    double money{};
    std::cout << "Enter cource: ";
    std::cin >> course;
    std::cout << "Enter money: ";
    std::cin >> money; 
    std::cout << money <<" RUB = " <<money/course<< " $ " << std::endl;
}
