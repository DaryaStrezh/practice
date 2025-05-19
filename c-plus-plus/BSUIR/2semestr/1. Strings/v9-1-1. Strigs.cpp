#include <iostream>
#include <string>
#include <stdlib.h>

int main() {

    using namespace std;
    string s;
    cout << "Enter a string:\n";
    getline(cin, s);
    int i = 0, t = 0, m = 0;
    int* probels = new int[0];

    while (s[t] && t <= s.length()) {
        if (s[t] == ' ') {                      //счетчик пробелов
            probels[m] = t;                     //запоминаем позиции пробелов
            m++;                                //размер массива с пробелами-1
        }
        t++;                                    //счетчик элементов в строке
    }

    int* chisla = new int[m + 1];               //создаем массив, в котором будут числа (количество пробелов+1)

    for (int n = 0; n <= m; n++) {
        //1st
        if (n == 0) chisla[n] = atoi((s.substr(0, probels[n]).c_str()));

        //last
        else if (n == m) chisla[n] = atoi((s.substr(probels[n - 1] + 1, s.length() - probels[n] - 1).c_str()));

        //others
        else if (n != 0 && n != m)  chisla[n] = atoi((s.substr(probels[n - 1] + 1, probels[n] - probels[n - 1] - 1).c_str()));
    }

    delete[]probels;
    int temp = 0;

    for (int k = 0; k <= m; k++) {
        for (int n = 0; n < m - k; n++) {
            if (chisla[n] > chisla[n + 1]) {
                temp = chisla[n];
                chisla[n] = chisla[n + 1];
                chisla[n + 1] = temp;
            }
        }
    }

    for (int n = 0; n <= m; n++) {
        cout << chisla[n] << " ";
    }

    delete[]chisla;
    return 0;
}
