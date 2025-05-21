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
|bool| - | 1 (true) и 0 (false)|false|
|signed char|1 байт (8 бит) |[-128; 127]||
|unsigned char|1 байт (8 бит) |[ 0; 255] ||
|char|1 байт (8 бит) |  [-128; 127] or [0; 255] ||
|short (short int / signed short int / signed short)|2 байта (16 бит) | [–32768; 32767]   ||
|unsigned short (unsigned short int) |2 байта (16 бит) | [0; 65535] ||
|int (signed int / signed)|2 байта (16 бит) или 4 байта (32 бита)|[–32768; 32767] или [−2 147 483 648; 2 147 483 647]||
|unsigned int (unsigned )|2 байта (16 бит) или 4 байта (32 бита) |[ 0; 65535 ] или [0; 4 294 967 295]||
|long (long int / signed long int / signed long)| 4 (32) или 8 (64) байт|[−2 147 483 648; 2 147 483 647] или [−9 223 372 036 854 775 808; +9 223 372 036 854 775 807]||
|unsigned long (unsigned long int)|4 байта (32 бита) | [0; 4 294 967 295]||
|long long (long long int / signed long long int / signed long long)|8 байт (64 бита)|[−9 223 372 036 854 775 808; +9 223 372 036 854 775 807]  ||
|unsigned long long (unsigned long long int)|8 байт (64 бита) |[0;18 446 744 073 709 551 615]  |-|
|| |  ||
|| |  ||
|| |  ||
|| |  ||
