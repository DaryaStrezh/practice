/*
* Упражнение 2
* Напишите программу, которая запрашивает у пользователь радиус круга и, 
* используя полученный радиус, вычисляет площадь круга.
*/

#include <iostream>

int main(){
    const double pi= 3.1415;
    int R{};
    std::cout << "Enter R: ";
    std::cin >> R;
    std::cout << "S = " << pi*R*R << " sm." << std::endl;
}
