# Лабораторная работа №19
>[!NOTE]
>Тема : "Классы и объекты. Инкапсуляция."
>Цель :
>1) Создание консольного приложения, состоящего из нескольких файлов в системе программирования Visual Studio.
>2) Использование классов и объектов в О программе.
# Вариант № 15
Элемент арифметической прогрессии $a_j$ вычисляется по формуле: $a_j=a_0*r^j$. Поле first -
дробное число, первый элемент прогрессии ао, поле second - положительное целое число,
постоянное отношение r. Реализовать метод element(int j) -вычисление j-го элемента
прогрессии.
# Блок-схема
![](https://sun9-31.userapi.com/impg/xDfgL3qvo5oAzfaXVNn6PEsUAS9NacMDnEk3gw/rauZAQhXRkk.jpg?size=204x256&quality=96&sign=86844ba4fe8f8998a826877df0b40bb4&type=album)
# Код программы
```cpp
#include <iostream>
#include <cmath>
using namespace std;

class arProg {
    double first;
    unsigned int second;

public:
    void set(double a, unsigned int b)
    {
        first = a;
        second = b;
    }
    void element(int j)
    {
        cout << "a(j) = " << first * pow(second, j);
    }
};
int main()
{
    arProg el;
    el.set(1, 3);
    el.element(5);
    return 0;
}
```
