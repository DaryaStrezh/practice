# Инициализация
В C++ есть три вида инициализации:

- Нотация присваивания (assignment notation)
```bash
int age;
age = 20;
```
- Функциональная нотация (functional notation)
```bash
int age (38);
```
- Инициализация в фигурных скобках (braced initialization)
```bash
int age {38};
```

# Типы данных
| Тип            | Размер            |Значение| По умолчанию|                                                 
| ----------- | ----------------|------------|------------------- |
|bool| 1 байт (8 бит) | 1 (true) и 0 (false)|false|
|signed char|1 байт (8 бит) |[-128; 127]||
|unsigned char|1 байт (8 бит) |[ 0; 255] ||
|char|1 байт (8 бит) |  [-128; 127] or [0; 255] ||
|short |2 байта (16 бит) | [–32768; 32767] |(short int / signed short int / signed short)|
|unsigned short |2 (16 бит) | [0; 65535] | (unsigned short int)|
|int |2  (16 бит) или 4 байта (32 бита)|[–32768; 32767] или [−2 147 483 648; 2 147 483 647(signed int / signed)
|unsigned int |2 (16 бит) или 4 байта (32 бита) |[ 0; 65535 ] или [0; 4 294 967 295]|(unsigned )|
|long | 4 (32) или 8 (64) байт|[−2 147 483 648; 2 147 483 647] или [−9 223 372 036 854 775 808; +9 223 372 036 854 775 807]|(long int / signed long int / signed long)|
|unsigned long|4 байта (32 бита) | [0; 4 294 967 295]| (unsigned long int)|
|long long |8 байт (64 бита)|[−9 223 372 036 854 775 808; +9 223 372 036 854 775 807]  |(long long int / signed long long int / signed long long)|
|unsigned long long|8 байт (64 бита) |[0;18 446 744 073 709 551 615]  | (unsigned long long int)|
|| |  ||
|| |  ||
|| |  ||
|| |  ||
